module MsgListP {
  provides interface MsgList;
  uses {
    interface Leds;
    interface AMPacket;
    interface Timer<TMilli> as Timer;
  }
} implementation {
  struct msg_info_list msgList;
  uint8_t last_check;

  static void shift_left(uint8_t idx) {
      uint8_t i;
      for (i = idx; i < msgList.used; i++)
        memcpy(msgList.msgs+(i-1), msgList.msgs+i, sizeof(struct msg_info));
      msgList.used--;
  }
  static void debug_dump(){
    /*
    uint8_t i;
    if (msgList.used == 0)
      return;
    dbg("MsgList", "Current list:\n");
    for (i = 0; i < msgList.used; i++) {
      dbg("MsgList", "\t am: %d, dest: %d, len: %d, retrial: %d, tick: %d\n",
	  msgList.msgs[i].am_id, msgList.msgs[i].dest, msgList.msgs[i].len,
	  msgList.msgs[i].retrial, msgList.msgs[i].tick);
    }
    */
  }
  command void MsgList.init() {
    msgList.capacity = ACK_QUEUE_LEN;
    msgList.used = 0;
    last_check = 0;
    call Timer.startPeriodic(20);
  }

  event void Timer.fired() {
    uint8_t i;
    //call Leds.led1Toggle();
    if (last_check >= msgList.used)
      last_check = 0;
    for (i = last_check; i < msgList.used; i++) {
      msgList.msgs[i].tick++;
      if (msgList.msgs[i].tick > RESEND_TICK) {
        bool resent;
	dbg("MsgList", "Trying to resend msg. dest: %d, am: %d\n",
	    msgList.msgs[i].dest, msgList.msgs[i].am_id);
	resent = signal MsgList.resend(msgList.msgs + i);
	msgList.msgs[i].retrial++;
	msgList.msgs[i].tick = 0;
        if (!resent) {
	  break;
        }
      }
    }
    if (i < msgList.used)
      last_check = i;
    else
      last_check = 0;
    debug_dump();
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

  command error_t MsgList.add(am_id_t am_id, am_addr_t dest, message_t * msg, uint8_t len) {
    uint8_t i;
    bool alreadyExists = FALSE;

    for (i = 0; i < msgList.used; i++) {
      if (msgList.msgs[i].dest == dest)
        alreadyExists = TRUE;
        break;
    }

    if (!alreadyExists && msgList.used < msgList.capacity) {
      msgList.msgs[msgList.used].origin_msg = msg;
      msgList.msgs[msgList.used].dest = dest;
      msgList.msgs[msgList.used].am_id = am_id;
      msgList.msgs[msgList.used].len = len;
      msgList.msgs[msgList.used].retrial = 0;
      msgList.msgs[msgList.used].tick = 0;
      memcpy(&msgList.msgs[msgList.used].msg, msg, sizeof(message_t));
      msgList.used++;
      debug_dump();
      return SUCCESS;
    } else {
      debug_dump();
      return FAIL;
    }
  }
  command void MsgList.removeByInfo(am_addr_t dest, am_id_t am_id){
    uint8_t i;
    bool alreadyExists = FALSE;

    for (i = 0; i < msgList.used; i++) {
      if (msgList.msgs[i].dest == dest && msgList.msgs[i].am_id == am_id)
        alreadyExists = TRUE;
        break;
    }
    if (alreadyExists) {
      shift_left(i+1);
    }
    debug_dump();
  }
  command void MsgList.removeByMsg(message_t * msg) {
    uint8_t i;
    bool alreadyExists = FALSE;

    for (i = 0; i < msgList.used; i++) {
      if (&msgList.msgs[i].msg == msg)
        alreadyExists = TRUE;
        break;
    }
    if (alreadyExists) {
      shift_left(i+1);
    }
    debug_dump();
  }

  command msg_info_t * MsgList.get(uint8_t idx) {
    if (idx < msgList.used)
      return msgList.msgs + idx;
    else
      return NULL;
  }
}
