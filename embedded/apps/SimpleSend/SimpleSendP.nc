module SimpleSendP {
  uses {
    interface Boot;
    interface Timer<TMilli> as Timer;
    interface AMSend;
    interface Packet;
    interface AMPacket;
  }
} implementation {
  message_t msg;

  event void Boot.booted() {
    call Timer.startPeriodic(500);
  }
  event void Timer.fired() {
    call AMSend.send(1, &msg, 0);
  }
  event void AMSend.sendDone(message_t* message, error_t error) {
  }
}
