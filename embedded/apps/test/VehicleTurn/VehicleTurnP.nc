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
    //stopStatus = NON_STOP;
    stopStatus = STOP_FIRST;
    call RadioControl.start();
    call SerialControl.start();
  }

  event void RadioControl.startDone(error_t err) {}
  event void RadioControl.stopDone(error_t err) {}
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
        if (stopStatus == STOP_FIRST) { // Stop
          bmm->cmd = 0x01;
          bmm->data = 0;
        } else { // Turn
          bmm->cmd = 0x02;
          bmm->data = 0x01<<8|turnPoint;
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
    BaseToMoteMsg* bmm;
    if (error)
      post serialSendTask();
    else if (stopStatus == STOP_FIRST) {
      bmm = (BaseToMoteMsg*)call SerialPacket.getPayload(&pkt, sizeof(BaseToMoteMsg));
      bmm->cmd = 0x02;
      bmm->data = 0x01<<8|turnPoint;
      //stopStatus = TURNED;
      stopStatus = STOP_FIRST;
      post serialSendTask();
    } else if (stopStatus == TURNED) {
      if (delay)
        call Timer.startOneShot(delay);
      else {
        stopStatus = WAITED;
        post serialSendTask();
      }
    } else if (stopStatus == WAITED) {
      bmm = (BaseToMoteMsg*)call SerialPacket.getPayload(&pkt, sizeof(BaseToMoteMsg));
      bmm->cmd = 0x01;
      bmm->data = SLOW_DOWN_SPEED;
      stopStatus = MOVED;
      post serialSendTask();
    } else if (stopStatus == MOVED) {
      stopStatus = STOP_FIRST;
      call Leds.led1Toggle();
    } else
      call Leds.led1Toggle();
  }
  event void Timer.fired() {
    stopStatus = WAITED;
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
