module TestBareUARTP {
  uses {
    interface Boot;
    interface UartStream;
    interface Leds;
  }
} implementation {
  uint8_t sendBuff;
  event void Boot.booted() {
  }
  task void writeToSerial () {
    uint8_t sendData;
    atomic sendData = sendBuff;
    if (call UartStream.send(&sendData, 1)) {
      call Leds.led0Toggle();
      post  writeToSerial();
    }
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    call Leds.led1Toggle();
  }
  async event void UartStream.receivedByte( uint8_t byte ) {
    atomic {
      if (byte == 'z') {
        sendBuff = 'a';
      } else {
        sendBuff = byte + 1;
      }
      if (sendBuff >= 'a' && sendBuff <= 'z') {
        post writeToSerial();
      }
    }
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
}
