module TestBareUARTP {
  uses {
    interface Boot;
    //interface SplitControl as SerialControl;
    interface UartStream;
    interface Timer<TMilli> as MilliTimer;
    interface Leds;
  }
} implementation {
  int counter;
  uint8_t sendBuf;
  event void Boot.booted() {
    counter = 0;
    //call SerialControl.start();
    call MilliTimer.startPeriodic(250);
  }
  /*event void SerialControl.startDone(error_t error) {
    call UartStream.enableReceiveInterrupt();
  }*/
  event void MilliTimer.fired() {
    error_t error;
    counter = (counter + 1) % 3;
    sendBuf = 'a' + counter;
    if (call UartStream.send(&sendBuf, 1)) {
      call Leds.led0Toggle();
    }
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
      call Leds.led1Toggle();
  }
  async event void UartStream.receivedByte( uint8_t byte ) {
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
}
