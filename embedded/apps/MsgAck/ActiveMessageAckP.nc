#include "ActiveMessageAck.h"

module ActiveMessageAckP {
  uses {
    interface Boot;
    interface MsgList;
    
    interface AMSend as RadioSend[am_id_t id];
    interface Receive as RadioReceive[am_id_t id];
    interface Packet as RadioPacket;
    interface AMPacket as RadioAMPacket;
  } provides {
    interface AMSend as AckSend[am_id_t id];
    interface Receive as AckReceive[am_id_t id];
  }
} implementation {
  bool msgBusy;
  uint8_t seq;
  struct msg_queue msg_queue;

  event void Boot.booted() {
    call MsgList.init();
    queue_clear(&msg_queue);
    msgBusy = FALSE;
    seq = 0;
  }

  task void msgQueueTask() {
    message_t cur_msg;
    if (dequeue(&msg_queue, &cur_msg) == SUCCESS) {
      am_addr_t dest = call RadioAMPacket.destination(&cur_msg);
      am_id_t am_type = call RadioAMPacket.type(&cur_msg);
      uint8_t len = call RadioPacket.payloadLength(&cur_msg);
      if (call RadioSend.send[am_type](dest, &cur_msg, len) != SUCCESS)
	enqueue(&msg_queue, &cur_msg);
      else
	msgBusy = TRUE;
    }
  }
  event bool MsgList.resend(msg_info_t * msgInfo) {
    enqueue(&msg_queue, &msgInfo->msg);
    if (!msgBusy) {
      post msgQueueTask();
      return TRUE;
    } else
      return FALSE;
  }

  command error_t AckSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    bool msgFull = call MsgList.full();
    if (msgFull)
      return FAIL;
    else {
      uint8_t * payload = (uint8_t *)call RadioPacket.getPayload(msg, len + ACK_HEAD_LEN); 
      if (!payload)
        return FAIL;
      payload[len] = MESSAGE_TYPE_SEND << 7 & (seq++);
      call RadioAMPacket.setType(msg, id);
      call RadioAMPacket.setDestination(msg, addr);
      call RadioPacket.setPayloadLength(msg, len + ACK_HEAD_LEN);
      enqueue(&msg_queue, msg);
      if (!msgBusy)
	post msgQueueTask();
      return call MsgList.add(msg, len);
    }
  }

  command error_t AckSend.cancel[am_id_t id](message_t* msg) {
    call MsgList.remove(msg);
    return SUCCESS;
  }

  command uint8_t AckSend.maxPayloadLength[am_id_t id]() {
    return (call RadioSend.maxPayloadLength[id]()) - ACK_HEAD_LEN;
  }

  command void* AckSend.getPayload[am_id_t id](message_t* msg, uint8_t len) {
    uint8_t * payload = (uint8_t *)call RadioPacket.getPayload(msg, len + ACK_HEAD_LEN);
    return payload;
  }

  default event void AckSend.sendDone[am_id_t id](message_t* message, error_t error) {
  }

  event void RadioSend.sendDone[am_id_t id](message_t* msg, error_t error) {
    msgBusy = FALSE;
    if (!queue_empty(&msg_queue))
      post msgQueueTask();
  }

  event message_t* RadioReceive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    uint8_t *ack_head = (uint8_t *)payload;
    if (*ack_head & (MESSAGE_TYPE_SEND << 7)) {
      message_t reply;
      uint8_t * reply_payload = (uint8_t *)call RadioPacket.getPayload(&reply, ACK_HEAD_LEN);
      call RadioAMPacket.setType(&reply, call RadioAMPacket.type(msg));
      call RadioAMPacket.setDestination(&reply, call RadioAMPacket.source(msg));
      *reply_payload = *ack_head | (MESSAGE_TYPE_ACK << 7);
      enqueue(&msg_queue, &reply);
      if (!msgBusy)
	post msgQueueTask();
    } else {
      uint8_t i;
      am_addr_t src = call RadioAMPacket.source(msg);
      am_id_t am_type = call RadioAMPacket.type(msg);
      for (i = 0; i < (call MsgList.size()); i++) {
	msg_info_t * msg_info = call MsgList.get(i);
	if (src == msg_info->dest && am_type == msg_info->am_id) {
	  call RadioPacket.setPayloadLength(&msg_info->msg, msg_info->len);
	  signal AckSend.sendDone[msg_info->am_id](&msg_info->msg, SUCCESS);
	  call MsgList.remove(&msg_info->msg);
	  break;
	}
      }
    }
    return msg;
  }
}
