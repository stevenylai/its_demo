#include "Vehicle.h"

module VehicleTurnP {
  uses {
    interface Boot;
    interface Leds;

    interface Timer<TMilli> as Timer;

    interface SplitControl as RadioControl;
    interface SplitControl as SerialControl;

    interface Packet as SerialPacket;
    interface Receive as SerialReceive;
    interface AMSend as SerialSend;

    interface Receive as RadioReceive;
  }
} implementation {
  enum {
    NON_STOP,
    STOP_FIRST,
    TURNED,
    WAITED,
    MOVED,
    SLOW_DOWN_SPEED = 0x20
  } stopStatus;

  uint8_t lasticnum, turnPoint;
  uint32_t delay;
  bool turned;
  message_t pkt;

  event void Boot.booted() {
    delay = 5000;
    lasticnum = 0;
    turnPoint = 10;
    turned = FALSE;
    stopStatus = NON_STOP;
    //stopStatus = STOP_FIRST;
    call RadioControl.start();
    call SerialControl.start();
  }

  event void RadioControl.startDone(error_t err) {}
  event void RadioControl.stopDone(error_t err) {}
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
        if (stopStatus == STOP_FIRST) { // Stop
          reply->icnum = vm->icnum;
          reply->speed = 0;
          reply->dir = 0;
        } else { // Turn
          reply->icnum = vm->icnum;
          reply->speed = vm->speed;
          reply->dir = 0x1;
        }
        post serialSendTask();
        turned = TRUE;
      }
    } else {
      call Leds.led2Toggle();
      turned = FALSE;
    }
    return msg;
  }

  event void SerialSend.sendDone(message_t* msg, error_t error) {
    VehicleMsg* reply;
    if (error)
      post serialSendTask();
    else if (stopStatus == STOP_FIRST) {
      /*reply = (VehicleMsg*)call SerialPacket.getPayload(&pkt, sizeof(VehicleMsg));
      reply->dir = 0x01;
      stopStatus = TURNED;
      post serialSendTask();*/
    //} else if (stopStatus == TURNED) {
      if (delay)
        call Timer.startOneShot(delay);
      else {
        reply = (VehicleMsg*)call SerialPacket.getPayload(&pkt, sizeof(VehicleMsg));
        reply->dir = 0x01;
        reply->speed = SLOW_DOWN_SPEED;
        stopStatus = MOVED;
        post serialSendTask();
      }
    } else if (stopStatus == MOVED) {
      stopStatus = STOP_FIRST;
      call Leds.led1Toggle();
    } else
      call Leds.led1Toggle();
  }
  event void Timer.fired() {
    VehicleMsg * reply = (VehicleMsg*)call SerialPacket.getPayload(&pkt, sizeof(VehicleMsg));
    reply->dir = 0x01;
    reply->speed = SLOW_DOWN_SPEED;
    stopStatus = MOVED;
    post serialSendTask();
  }
  event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len){
    VehicleTurnMsg* vtm = (VehicleTurnMsg*)payload;
    if (len != sizeof(VehicleTurnMsg)) return msg;
    turnPoint = vtm->turnPoint;
    delay = vtm->delay;
    return msg;
  }
}
