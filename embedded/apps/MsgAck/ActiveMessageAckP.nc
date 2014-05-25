#include "ActiveMessageAck.h"

module ActiveMessageAckP {
  uses {
    interface MsgList;
    interface Leds;
    
    interface SplitControl as RadioControl;
    interface AMSend as RadioSend[am_id_t id];
    interface Receive as RadioReceive[am_id_t id];
    interface Receive as RadioSnoop[am_id_t id];
    interface Packet as RadioPacket;
    interface AMPacket as RadioAMPacket;
  } provides {
    interface SplitControl;
    interface Receive as AckSnoop[am_id_t id];
    interface AMSend as AckSend[am_id_t id];
    interface Receive as AckReceive[am_id_t id];
  }
} implementation {
  bool msgBusy;
  uint8_t seq;
  struct msg_queue msg_queue;
  msg_info_t cur_msg, buffer;

  static void dump_queue(struct msg_queue * queue) {
    /*
    uint8_t i = queue->head;
    dbg("MsgAck", "Pending msgs\n");
    while (i != queue->tail) {
      dbg("MsgAck", "\t am: %d, dest: %d, len: %d\n",
	  queue->buffer[i].am_id,
	  queue->buffer[i].dest,
	  queue->buffer[i].len);
      i = (i + 1) % MSG_QUEUE_LEN;
    }
    */
  }
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
      dbg("MsgAck", "Msg queue is full!\n");
      queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
    }
    memcpy(queue->buffer + queue->tail, item, sizeof(msg_info_t));
    queue->tail = (queue->tail + 1) % MSG_QUEUE_LEN;
    dump_queue(queue);
  }
  static error_t dequeue(struct msg_queue * queue, msg_info_t *item) {
    if (queue_empty(queue))
      return FAIL;
    memcpy(item, queue->buffer + queue->head, sizeof(msg_info_t));
    queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
    dump_queue(queue);
    return SUCCESS;
  }

  command error_t SplitControl.start() {
    return call RadioControl.start();
  }
  command error_t SplitControl.stop() {
    return call RadioControl.stop();
  }
  event void RadioControl.startDone(error_t error) {
    queue_clear(&msg_queue);
    msgBusy = FALSE;
    seq = 125;
    call MsgList.init();
    dbg("MsgAck", "AM_ACK init'd\n");
    signal SplitControl.startDone(error);
  }
  event void RadioControl.stopDone(error_t error) {
    signal SplitControl.stopDone(error);
  }

  task void msgQueueTask() {
    if (dequeue(&msg_queue, &cur_msg) == SUCCESS) {
      dbg("MsgAck", "RadioSend msg. am: %d, dest: %d, len: %d, head: 0x%x, msg: 0x%x ",
	  cur_msg.am_id, cur_msg.dest, cur_msg.len,
	  *((uint8_t *)call RadioPacket.getPayload(&cur_msg.msg, cur_msg.len)), &cur_msg.msg);
      call RadioAMPacket.setType(&cur_msg.msg, cur_msg.am_id);
      if (call RadioSend.send[cur_msg.am_id](cur_msg.dest, &cur_msg.msg, cur_msg.len) != SUCCESS) {
	dbg("MsgAck", "failed\n");
	enqueue(&msg_queue, &cur_msg);
	post msgQueueTask();
      } else {
	dbg("MsgAck", "successfully, am_id: %d\n", cur_msg.am_id);
	call Leds.led2On();
      }
    } else {
      msgBusy = FALSE;
    }
  }
  event bool MsgList.resend(msg_info_t * msgInfo) {
    enqueue(&msg_queue, msgInfo);
    if (!msgBusy) {
      msgBusy = TRUE;
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
      if (!payload) {
        return FAIL;
      }
      //payload[0] = 0x7F & seq;
      payload[0] = MESSAGE_TYPE_SEND;
      seq = (seq + 1) % 128;
      memcpy(&buffer.msg, msg, sizeof(message_t));
      buffer.origin_msg = msg;
      buffer.am_id = id;
      buffer.dest = addr;
      buffer.len = len + ACK_HEAD_LEN;
      enqueue(&msg_queue, &buffer);
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
    payload[0] = MESSAGE_TYPE_SEND;
    return payload + ACK_HEAD_LEN;
  }

  default event void AckSend.sendDone[am_id_t id](message_t* message, error_t error) {
  }

  default event message_t* AckReceive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    /*
    uint8_t *ack_head = (uint8_t *)payload;
    dbg("MsgAck", "Default receving msg. am: %d, src: %d, len: %d, head: 0x%x\n",
	id, (call RadioAMPacket.source(msg)), len, *ack_head);
    */
    return msg;
  }

  default event message_t* AckSnoop.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    /*
    uint8_t *ack_head = (uint8_t *)payload;
    dbg("MsgAck", "Default snooping msg. am: %d, src: %d, len: %d, head: 0x%x\n",
	id, (call RadioAMPacket.source(msg)), len, *ack_head);
    */
    return msg;
  }

  event void RadioSend.sendDone[am_id_t id](message_t* msg, error_t error) {
    dbg("MsgAck", "RadioSend msg done for msg. am: %d, dest: %d, head: 0x%x, msg: 0x%x\n",
	id, (call RadioAMPacket.destination(msg)),
	*((uint8_t *)call RadioPacket.getPayload(msg, ACK_HEAD_LEN)), msg);
    msgBusy = FALSE;
    call Leds.led2Off();
    if (!queue_empty(&msg_queue)) {
      msgBusy = TRUE;
      post msgQueueTask();
    }
  }
  event message_t* RadioSnoop.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    uint8_t *ack_head = (uint8_t *)payload;
    //if ((*ack_head >> 7) == MESSAGE_TYPE_SEND) {
    if (*ack_head == MESSAGE_TYPE_SEND) {
      memmove(payload, ((uint8_t *)payload) + ACK_HEAD_LEN, len - ACK_HEAD_LEN);
      call RadioPacket.setPayloadLength(msg, len - ACK_HEAD_LEN);
      msg = signal AckSnoop.receive[id](msg, payload, len - ACK_HEAD_LEN);
    }
    return msg;
  }
  event message_t* RadioReceive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    uint8_t *ack_head = (uint8_t *)payload;
    //if (((*ack_head >> 7) & 0x1) == MESSAGE_TYPE_SEND) {
    if (*ack_head == MESSAGE_TYPE_SEND) {
      dbg("MsgAck", "RadioReceive msg. am: %d, src: %d, len: %d, head: 0x%x\n",
	  id, (call RadioAMPacket.source(msg)), len, *ack_head);
      if (call RadioAMPacket.isForMe(msg)) {
	//uint8_t reply_head = (*ack_head | 0x80);
	uint8_t reply_head = MESSAGE_TYPE_ACK;
	uint8_t * reply_payload = (uint8_t *)call RadioPacket.getPayload(&buffer.msg, sizeof(reply_head));
	call Leds.led1Toggle();
	memcpy(reply_payload, &reply_head, sizeof(reply_head));
	buffer.am_id = id;
	buffer.dest = call RadioAMPacket.source(msg);
	buffer.len = sizeof(reply_head);
	enqueue(&msg_queue, &buffer);
	if (!msgBusy) {
	  msgBusy = TRUE;
	  post msgQueueTask();
	}
	memmove(payload, ((uint8_t *)payload) + ACK_HEAD_LEN, len - ACK_HEAD_LEN);
	call RadioPacket.setPayloadLength(msg, len - ACK_HEAD_LEN);
	msg = signal AckReceive.receive[id](msg, payload, len - ACK_HEAD_LEN);
      }
    } else { // ACK
      uint8_t i;
      am_addr_t src = call RadioAMPacket.source(msg);
      am_id_t am_type = id;
      call Leds.led0Toggle();
      dbg("MsgAck", "RadioReceive ack. am: %d, src: %d, len: %d, head: 0x%x\n",
	  id, src, len, *ack_head);
      for (i = 0; i < (call MsgList.size()); i++) {
	msg_info_t * msg_info = call MsgList.get(i);
	if ((msg_info->dest == src || msg_info->dest == AM_BROADCAST_ADDR)
	    && am_type == msg_info->am_id) {
	  uint8_t * origin_payload = (uint8_t *)call RadioPacket.getPayload(msg_info->origin_msg,
									    msg_info->len);
	  memmove(origin_payload, origin_payload + ACK_HEAD_LEN, msg_info->len - ACK_HEAD_LEN);
	  signal AckSend.sendDone[msg_info->am_id](msg_info->origin_msg, SUCCESS);
	  call MsgList.removeByInfo(msg_info->dest, am_type);
	  break;
	}
      }
    }
    return msg;
  }
}
