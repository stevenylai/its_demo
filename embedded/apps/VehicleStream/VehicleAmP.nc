#include "VehicleSerial.h"
module VehicleAmP {
  uses {
    interface Packet as SerialPacket;
    interface AMPacket as SerialAMPacket;
    interface ActiveMessageAddress;
    interface Leds;
    interface Timer<TMilli> as Timer;
  } provides {
    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  message_t * sendMsg;

  am_id_t ignoredAm;
  message_t * ignoredMsg;

  message_t recvAm;
  message_t * recvAmPtr;
  VehicleMsg * recvPayload;

  /*message_t serial_msg_queue[QUEUE_LEN];
  uint8_t serial_queue_head, serial_queue_tail;
  bool carStopped, sendingBeacon;
  */

  task void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    atomic {
      recvPayload = (VehicleMsg *)call SerialPacket.getPayload(recvAmPtr = &recvAm, sizeof(VehicleMsg));
      //carStopped = sendingBeacon = false;
    }
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  task void receiveMsgTask() {
    call Leds.led0Toggle();
    atomic {
      call SerialAMPacket.setSource(recvAmPtr, call ActiveMessageAddress.amAddress());
      call SerialAMPacket.setDestination(recvAmPtr, 0);
      call SerialAMPacket.setType(recvAmPtr, AM_VEHICLE_RECEIVE);
      call SerialAMPacket.setGroup(recvAmPtr, call SerialAMPacket.localGroup());
      call SerialPacket.setPayloadLength(recvAmPtr, sizeof(VehicleMsg));
      recvAmPtr = signal Receive.receive[AM_VEHICLE_RECEIVE](recvAmPtr, call SerialPacket.getPayload(recvAmPtr, sizeof(VehicleMsg)), sizeof(VehicleMsg));
      recvPayload = (VehicleMsg *)call SerialPacket.getPayload(recvAmPtr, sizeof(VehicleMsg));
    }
  }
  task void sendMsgDoneTask() {
    message_t * tmpMsg;
    error_t tmpError;
    atomic {
      tmpMsg = sendMsg;
      tmpError = sendError;
    }
    signal AMSend.sendDone[AM_VEHICLE_SEND](tmpMsg, tmpError);
  }
  task void sendMsgIgnoredTask() {
    signal AMSend.sendDone[ignoredAm](ignoredMsg, SUCCESS); 
  }
  command error_t AMSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    error_t returnErr;
    VehicleMsg * vm;
    if (id != AM_VEHICLE_SEND) {
      ignoredAm = id;
      ignoredMsg = msg;
      post sendMsgIgnoredTask();
      return SUCCESS;
    }
    vm = (VehicleMsg *)call SerialPacket.getPayload(msg, sizeof(VehicleMsg));
    atomic {
      sendBuf.id = recvBuf.id;
      sendBuf.speed = (uint8_t)vm->speed;
      sendBuf.dir = vm->dir;
      sendBuf.icnum = vm->icnum;
      sendMsg = msg;
      returnErr = sendError;
    }
    return returnErr;
  }
  command error_t AMSend.cancel[am_id_t id](message_t* msg) {
    return FAIL;
  }
  command uint8_t AMSend.maxPayloadLength[am_id_t id]() {
    return call SerialPacket.maxPayloadLength();
  }
  command void* AMSend.getPayload[am_id_t id](message_t* msg, uint8_t len) {
    return call SerialPacket.getPayload(msg, len);
  }
  event void Timer.fired() {
    atomic {
    }
  }
  async event void ActiveMessageAddress.changed() {}

  default event message_t* Receive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    return msg;
  }
  default event void AMSend.sendDone[am_id_t id](message_t* msg, error_t error) {
  }
}
