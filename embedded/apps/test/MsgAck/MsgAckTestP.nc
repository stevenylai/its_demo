module MsgAckTestP {
  uses {
    interface Boot;
    interface SplitControl;
    interface Timer<TMilli> as Timer;
    interface AMSend;
    interface Receive;
    interface Packet;
    interface AMPacket;
  }
} implementation {
  message_t testmsg;
  message_t * msgptr;
  uint8_t counter;

  event void Boot.booted() {
    counter = 0;
    msgptr = &testmsg;
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t error) {
    if (error == SUCCESS) {
      dbg("MsgAckTest", "Starting test with ID: %d, addr: %d\n",
	  TOS_NODE_ID, (call AMPacket.address()));
      call Timer.startPeriodic(100);
    } else {
      dbg("MsgAckTest", "Restarting AM\n");
    }
  }

  event void SplitControl.stopDone(error_t error) {
    call Timer.stop();
  }

  event void Timer.fired() {
    if (TOS_NODE_ID == 0)
      dbg("Timer", "Timer fired\n");
    else {
      void * payload = call AMSend.getPayload(msgptr, sizeof(counter));
      memcpy(payload, &counter, sizeof(counter));
      if ((call AMSend.send(AM_BROADCAST_ADDR, msgptr, sizeof(counter))) != SUCCESS) {
	dbg("MsgAckTest", "Failed to send msg: %d, size: %d\n",
	    counter, sizeof(counter));
      } else {
	dbg("MsgAckTest", "Successfully sent msg: %d, size: %d\n",
	    counter, sizeof(counter));
      }
      counter++;
    }
  }

  event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
    uint8_t result = *((uint8_t *)payload);
    dbg("MsgAckTest", "Received msg: %d\n", result);
    return msg;
  }

  event void AMSend.sendDone(message_t* message, error_t error) {
    uint8_t * payload = (uint8_t *)(call AMSend.getPayload(message, sizeof(counter)));
    dbg("MsgAckTest", "Sent message %d with status: %d\n", *payload, error);
  }
}
