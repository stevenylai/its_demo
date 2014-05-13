module MsgListP {
  provides interface MsgList;
  uses {
    interface AMPacket;
    interface Timer<TMilli> as Timer;
  }
} implementation {
  struct msg_info_list msgList;

  static void shift_left(uint8_t idx) {
      uint8_t i;
      for (i = idx; i < msgList.used; i++)
        memcpy(msgList.msgs+(i-1), msgList.msgs+i, sizeof(struct msg_info));
      msgList.used--;
  }
  command void MsgList.init() {
    msgList.capacity = ACK_QUEUE_LEN;
    msgList.used = 0;
    call Timer.startPeriodic(4);
  }

  event void Timer.fired() {
    uint8_t i;
    for (i = 0; i < msgList.used; i++) {
      msgList.msgs[i].tick++;
      if (msgList.msgs[i].tick > RESEND_TICK) {
        signal msgList.resend(msgList.msgs + i);
        msgList.msgs[i].retrial++;
        msgList.msgs[i].tick = 0;
      }
    }
  }

  command bool MsgList.full() {
    return msgList.used == msgList.capacity;
  }

  command bool MsgList.size() {
    return msgList.used;
  }

  command bool MsgList.empty() {
    return msgList.used == 0;
  }

  command error_t MsgList.add(message_t * msg) {
    uint8_t i;
    bool alreadyExists = FALSE;
    am_addr_t dest = call AMPacket.destination(msg);
    am_id_t am_id = call AMPacket.type(msg);

    for (i = 0; i < msgList.used; i++) {
      if (msgList.msgs[i].dest == dest)
        alreadyExists = TRUE;
        break;
    }

    if (!alreadyExists && msgList.used < msgList.capacity) {
      msgList.msgs[msgList.used].dest = dest;
      msgList.msgs[mstList.used].am_id = am_id;
      msgList.msgs[mstList.used].retrial = 0;
      msgList.msgs[mstList.used].tick = 0;
      memcpy(&msgList.msgs[mstList.used].msg, msg, sizeof(message_t));
      return SUCCESS;
    } else
      return FAIL;
  }
  command void MsgList.remove(message_t * msg) {
    uint8_t i;
    bool alreadyExists = FALSE;
    am_addr_t dest = call AMPacket.destination(msg);
    am_id_t am_id = call AMPacket.type(msg);

    for (i = 0; i < msgList.used; i++) {
      if (msgList.msgs[i].dest == dest)
        alreadyExists = TRUE;
        break;
    }
    if (alreadyExists)
      shift_left(i+1);
  }

  command msg_info_t * MsgList.get(uint8_t idx) {
    if (idx < msgList.used)
      return msgList.msgs + idx;
    else
      return NULL;
  }
}
