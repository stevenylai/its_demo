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
  uint8_t counter;

  event void Boot.booted() {
    counter = 0xFF;
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t error) {
    call Timer.startPeriodic(100);
    //call Timer.startOneShot(500);
  }

  event void SplitControl.stopDone(error_t error) {
    call Timer.stop();
  }

  event void Timer.fired() {
    uint8_t * payload = (uint8_t *)call AMSend.getPayload(&msg, sizeof(counter));
    call Leds.led1Toggle();
    memcpy(payload, &counter, sizeof(counter));
    if ((call AMSend.send(0x0, &msg, sizeof(counter))) == SUCCESS) {
      counter--;
      if (!counter)
	counter = 0xFF;
    } else {
      call Leds.led0Toggle();
    }
  }

  event void AMSend.sendDone(message_t* message, error_t error) {
  }
}
