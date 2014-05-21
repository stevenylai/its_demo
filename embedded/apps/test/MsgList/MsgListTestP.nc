#include "AM.h"

module MsgListTestP {
  uses {
    interface MsgList;
    interface Timer<TMilli> as Timer;
    interface Boot;
    interface AMSend;
    interface Leds;
  }
} implementation {
  message_t testmsg;
  uint8_t counter;

  static void add_msg() {
    void * payload = call AMSend.getPayload(&testmsg, sizeof(counter));
    memcpy(payload, &counter, sizeof(counter));
    call MsgList.add(counter % 5, counter % 5, &testmsg, sizeof(counter));
  }
  static void remove_msg_by_info() {
    call MsgList.removeByInfo((counter - 1) % 5, (counter - 1) % 5);
  }
  event void Boot.booted() {
    counter = 1;
    call MsgList.init();
    dbg("Timer", "Timer started.\n");
    call Timer.startPeriodic(10);
  }
  
  event bool MsgList.resend(msg_info_t * msgInfo) {
    return FALSE;
  }

  event void Timer.fired() {
    dbg("Timer", "Timer fired.\n");
    counter++;
  }

  event void AMSend.sendDone(message_t* msg, error_t error) {
    /* Not used */
  }
}
