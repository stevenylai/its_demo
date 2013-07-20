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
        bmm->cmd = 0x01;
        bmm->data = 0;
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
    BaseToMoteMsg* bmm = (BaseToMoteMsg*)call SerialPacket.getPayload(&pkt, sizeof(BaseToMoteMsg));
    bmm->cmd = 0x01;
    bmm->data = 0x20;
    post serialSendTask();
  }
}
