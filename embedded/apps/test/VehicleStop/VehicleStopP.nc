#include "Vehicle.h"

module VehicleStopP {
  uses {
    interface Boot;
    interface Leds;

    interface Timer<TMilli> as Timer;

    interface SplitControl as SerialControl;

    interface Packet as SerialPacket;
    interface Receive as SerialReceive;
    interface AMSend as SerialSend;

  }
} implementation {

  uint8_t lasticnum, turnPoint;
  uint32_t delay;
  bool turned;
  message_t pkt;

  event void Boot.booted() {
    delay = 5000;
    lasticnum = 0;
    turnPoint = 10;
    turned = FALSE;
    call SerialControl.start();
  }

  event void SerialControl.startDone(error_t err) {}
  event void SerialControl.stopDone(error_t err) {}

  task void serialSendTask() {
    if (call SerialSend.send(0, &pkt, sizeof(VehicleMsg)) != SUCCESS) {
      post serialSendTask();
    }
  }
  event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len){
    VehicleMsg * vm = (VehicleMsg *)payload;
    if (len != sizeof(VehicleMsg)) return msg;
    if (lasticnum == vm->icnum) return msg; // No change

    lasticnum = vm->icnum;
    if (vm->icnum == turnPoint) {
      call Leds.led0Toggle();
      if (!turned) {
        VehicleMsg* reply = (VehicleMsg*)call SerialPacket.getPayload(&pkt, sizeof(VehicleMsg));
        reply->icnum = vm->icnum;
        reply->speed = 0;
        reply->dir = 0;
        post serialSendTask();
        call Timer.startOneShot(delay);
        turned = TRUE;
      }
    } else {
      call Leds.led2Toggle();
      turned = FALSE;
    }
    return msg;
  }

  event void SerialSend.sendDone(message_t* msg, error_t error) {
    if (error)
      post serialSendTask();
    else
      call Leds.led1Toggle();
  }
  event void Timer.fired() {
    VehicleMsg* reply = (VehicleMsg*)call SerialPacket.getPayload(&pkt, sizeof(VehicleMsg));
    reply->speed = 0x10;
    reply->dir = 0;
    post serialSendTask();
  }
}
