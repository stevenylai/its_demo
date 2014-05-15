module SimpleSendP {
  uses {
    interface Boot;
    interface SplitControl;
    interface Timer<TMilli> as Timer;
    interface AMSend;
    interface Packet;
    interface AMPacket;
    interface Leds;
  }
} implementation {
  message_t msg;

  event void Boot.booted() {
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t error) {
    call Timer.startPeriodic(500);
  }

  event void SplitControl.stopDone(error_t error) {
    call Timer.stop();
  }

  event void Timer.fired() {
    call Leds.led0Toggle();
    call AMSend.send(1, &msg, 0);
  }

  event void AMSend.sendDone(message_t* message, error_t error) {
  }
}
