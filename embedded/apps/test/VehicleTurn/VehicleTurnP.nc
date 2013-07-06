#include <Timer.h>
#include "Vehicle.h"
#include "VehicleTurn.h"

module VehicleTurnP {
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli> as Timer;

    interface SplitControl as SerialControl;
    interface SplitControl as RadioControl;

    interface Receive as SerialReceive;
    interface AMSend as SerialSend;
    interface Packet as SerialPacket;

    interface Receive as RadioReceive;
  }
} implementation {
  uint8_t lasticnum;
  uint8_t turnPoint;
  uint32_t delay;
  bool turned;
  message_t pkt;

  event void Boot.booted() {
    lasticnum = 0;
    turnPoint = 10;
    //turnPoint = 8;
    delay = 0;
    turned = FALSE;
    call RadioControl.start();
    call SerialControl.start();
  }

  event void RadioControl.startDone(error_t err) {}
  event void SerialControl.startDone(error_t err) {}
  event void RadioControl.stopDone(error_t err) {}
  event void SerialControl.stopDone(error_t err) {}

  task void serialSendTask() {
    if (call SerialSend.send(0, &pkt, sizeof(BaseToMoteMsg)) != SUCCESS) {
      post serialSendTask();
    }
  }
  event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len){
    MoteToBaseMsg * mbm = (MoteToBaseMsg *)payload;
    if (len != sizeof(MoteToBaseMsg)) return msg;
    if (lasticnum == mbm->icnum) return msg; // No change

    lasticnum = mbm->icnum;
    if (mbm->icnum == turnPoint) {
      call Leds.led0Toggle();
      if (!turned) {
        BaseToMoteMsg* bmm = (BaseToMoteMsg*)call SerialPacket.getPayload(&pkt, sizeof(BaseToMoteMsg));
        bmm->cmd = 0x02;
        bmm->data = 0x01<<8|turnPoint;
        if (!delay)
          post serialSendTask();
        else
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
