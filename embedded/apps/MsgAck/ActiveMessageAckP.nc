#include "ActiveMessageAck.h"

module ActiveMessageAckP {
  uses {
    interface Boot;
    interface MsgList;
    interface Leds;
    
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

  static void queue_clear(struct msg_queue * queue) {
    queue->head = queue->tail = 0;
  }
  static bool queue_full(struct msg_queue * queue) {
    return (queue->tail + 1) % MSG_QUEUE_LEN == queue->head;
  }
  static bool queue_empty(struct msg_queue * queue) {
    return queue->head == queue->tail;
  }
  static void enqueue(struct msg_queue * queue, msg_info_t *item) {
    if (queue_full(queue)) { // Queue is full so make room first
      queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
    }
    memcpy(queue->buffer + queue->tail, item, sizeof(msg_info_t));
    queue->tail = (queue->tail + 1) % MSG_QUEUE_LEN;
  }
  static error_t dequeue(struct msg_queue * queue, msg_info_t *item) {
    if (queue_empty(queue))
      return FAIL;
    memcpy(item, queue->buffer + queue->head, sizeof(msg_info_t));
    queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
    return SUCCESS;
  }

  event void Boot.booted() {
    queue_clear(&msg_queue);
    msgBusy = FALSE;
    seq = 15;
    call MsgList.init();
  }

  task void msgQueueTask() {
    msg_info_t cur_msg;
    //call Leds.led1Toggle();
    if (dequeue(&msg_queue, &cur_msg) == SUCCESS) {
      if (call RadioSend.send[cur_msg.am_id](cur_msg.dest, &cur_msg.msg, cur_msg.len) != SUCCESS) {
	//call Leds.led0Toggle();
	enqueue(&msg_queue, &cur_msg);
	post msgQueueTask();
      } else {
	call Leds.led2On();
      }
    } else {
      //call Leds.led0Toggle();
      msgBusy = FALSE;
    }
  }
  event bool MsgList.resend(msg_info_t * msgInfo) {
    enqueue(&msg_queue, msgInfo);
    if (!msgBusy) {
      msgBusy = TRUE;
      post msgQueueTask();
      //call Leds.led0Toggle();
      return TRUE;
    } else
      return FALSE;
  }

  command error_t AckSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    bool msgFull = call MsgList.full();
    if (msgFull)
      return FAIL;
    else {
      msg_info_t item;
      uint8_t * payload = (uint8_t *)call RadioPacket.getPayload(msg, len + ACK_HEAD_LEN); 
      if (!payload) {
        return FAIL;
      }
      payload[0] = 0x7F & seq;
      seq = (seq + 1) % 128;
      memcpy(&item.msg, msg, sizeof(message_t));
      item.am_id = id;
      item.dest = addr;
      item.len = len + ACK_HEAD_LEN;
      enqueue(&msg_queue, &item);
      if (!msgBusy) {
	msgBusy = TRUE;
	post msgQueueTask();
      }
      return call MsgList.add(id, addr, msg, len + ACK_HEAD_LEN);
    }
  }

  command error_t AckSend.cancel[am_id_t id](message_t* msg) {
    call MsgList.removeByMsg(msg);
    return SUCCESS;
  }

  command uint8_t AckSend.maxPayloadLength[am_id_t id]() {
    return (call RadioSend.maxPayloadLength[id]()) - ACK_HEAD_LEN;
  }

  command void* AckSend.getPayload[am_id_t id](message_t* msg, uint8_t len) {
    uint8_t * payload = (uint8_t *)call RadioPacket.getPayload(msg, len + ACK_HEAD_LEN);
    return payload + ACK_HEAD_LEN;
  }

  default event void AckSend.sendDone[am_id_t id](message_t* message, error_t error) {
  }

  default event message_t* AckReceive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    return msg;
  }

  event void RadioSend.sendDone[am_id_t id](message_t* msg, error_t error) {
    msgBusy = FALSE;
    call Leds.led2Off();
    if (!queue_empty(&msg_queue)) {
      msgBusy = TRUE;
      post msgQueueTask();
    }
  }

  event message_t* RadioReceive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    uint8_t *ack_head = (uint8_t *)payload;
    if ((*ack_head >> 7) == MESSAGE_TYPE_SEND) {
      if (call RadioAMPacket.isForMe(msg)) {
	msg_info_t reply;
	uint8_t * reply_payload = (uint8_t *)call RadioPacket.getPayload(&reply.msg, ACK_HEAD_LEN);
	*reply_payload = (*ack_head | 0x80);
	reply.am_id = id;
	reply.dest = call RadioAMPacket.source(msg);
	reply.len = ACK_HEAD_LEN;
	enqueue(&msg_queue, &reply);
	if (!msgBusy) {
	  msgBusy = TRUE;
	  post msgQueueTask();
	}
	call Leds.led1Toggle();
	memmove(payload, ((uint8_t *)payload) + ACK_HEAD_LEN, len - ACK_HEAD_LEN);
	call RadioPacket.setPayloadLength(msg, len - ACK_HEAD_LEN);
	msg = signal AckReceive.receive[id](msg, payload, len - ACK_HEAD_LEN);
      }
    } else { // ACK
      uint8_t i;
      am_addr_t src = call RadioAMPacket.source(msg);
      am_id_t am_type = id;
      call Leds.led1Toggle();
      for (i = 0; i < (call MsgList.size()); i++) {
	msg_info_t * msg_info = call MsgList.get(i);
	if (src == msg_info->dest && am_type == msg_info->am_id) {
	  signal AckSend.sendDone[msg_info->am_id](&msg_info->msg, SUCCESS);
	  call MsgList.removeByInfo(src, am_type);
	  break;
	}
      }
    }
    return msg;
  }
}
