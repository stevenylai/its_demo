module SimpleReceiveP {
  uses {
    interface Boot;
    interface SplitControl;
    interface Receive;
    interface AMPacket;
    interface Leds;
  }
} implementation {
  event void Boot.booted() {
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t error) {
  }

  event void SplitControl.stopDone(error_t error) {
  }

  event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
    call Leds.led1Toggle();
    return msg;
  }
}
  
