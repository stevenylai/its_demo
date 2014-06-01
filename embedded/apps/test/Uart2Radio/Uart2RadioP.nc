#include "VehicleSerial.h"

module Uart2RadioP {
  uses {
    interface Boot;
    interface Timer<TMilli> as Timer;

    interface SplitControl as RadioControl;
    interface AMSend as RadioAMSend;
    interface Receive as RadioReceive;
    interface Packet as RadioPacket;
    interface AMPacket as RadioAMPacket;

    interface SplitControl as SerialControl;
    interface AMSend as SerialAMSend;
    interface Packet as SerialPacket;
    interface AMPacket as SerialAMPacket;

    interface Leds;
  }
} implementation {
  message_t msg;
  uint8_t counter;
  bool serialInitialized, radioInitialized;

  event void Boot.booted() {
    counter = 0;
    serialInitialized = radioInitialized = FALSE;
    call SerialControl.start();
    call RadioControl.start();
  }

  static void start_timer() {
    if (TOS_NODE_ID != 0x0) {
      dbg("Timer", "Timer started\n");
      call Timer.startPeriodic(500);
      //call Timer.startOneShot(500);
    }
  }
  event void SerialControl.startDone(error_t error) {
    serialInitialized = TRUE;
    if (radioInitialized)
      start_timer();
  }
  event void RadioControl.startDone(error_t error) {
    radioInitialized = TRUE;
    if (serialInitialized)
      start_timer();
  }
  event void SerialControl.stopDone(error_t error) {
    call Timer.stop();
  }
  event void RadioControl.stopDone(error_t error) {
    call Timer.stop();
  }

  static void uart_2_radio(message_t * message, uint8_t len) {
    message_t backup;
    uint8_t *uart_payload, *radio_payload;
    memcpy(&backup, message, sizeof(message_t));

    uart_payload = (uint8_t *)call SerialAMSend.getPayload(&backup, len);
    radio_payload = (uint8_t *)call RadioAMSend.getPayload(message, len);
    memcpy(radio_payload, uart_payload, len);
  }

  event message_t* RadioReceive.receive(message_t* message, void* payload, uint8_t len) {
    VehicleMsg * vehicleInfo = (VehicleMsg *)payload;
    dbg("Uart2Radio", "Receiving speed %d, icnum: %d, dir: %d\n",
	vehicleInfo->speed, vehicleInfo->icnum, vehicleInfo->dir);
    return message;
  }
  event void Timer.fired() {
    VehicleMsg * payload = (VehicleMsg *)call SerialAMSend.getPayload(&msg, sizeof(VehicleMsg));
    dbg("Timer", "Timer fired. sending current counter: %d\n", counter);
    payload->speed = counter;
    payload->icnum = counter;
    payload->dir = counter;
    uart_2_radio(&msg, sizeof(VehicleMsg));
    if ((call RadioAMSend.send(0x0, &msg, sizeof(VehicleMsg))) == SUCCESS) {
      counter++;
    } 
  }

  event void RadioAMSend.sendDone(message_t* message, error_t error) {
    if (message == &msg) {
      dbg("Uart2Radio", "RadioAMSend is done\n");
    }
  }
  event void SerialAMSend.sendDone(message_t* message, error_t error) {
  }
}
