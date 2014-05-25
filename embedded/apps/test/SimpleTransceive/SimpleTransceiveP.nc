module SimpleTransceiveP {
  uses {
    interface Boot;
    interface SplitControl;
    interface Timer<TMilli> as Timer;
    interface AMSend;
    interface Receive;
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
    if (TOS_NODE_ID != 0x0) {
      call Timer.startPeriodic(500);
      //call Timer.startOneShot(500);
    }
  }

  event void SplitControl.stopDone(error_t error) {
    call Timer.stop();
  }

  event message_t* Receive.receive(message_t* message, void* payload, uint8_t len) {
    call Leds.led1Toggle();
    dbg("SimpleTransceive", "Recivinging counter %d\n", *((uint8_t *)payload));
    return message;
  }

  event void Timer.fired() {
    uint8_t * payload = (uint8_t *)call AMSend.getPayload(&msg, sizeof(counter));
    memcpy(payload, &counter, sizeof(counter));
    dbg("SimpleTransceive", "Sending counter %d\n", counter);
    if ((call AMSend.send(0x0, &msg, sizeof(counter))) == SUCCESS) {
      call Leds.led1Toggle();
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
