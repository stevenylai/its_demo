#include "VehicleSerial.h"
module VehicleAmP {
  uses {
    interface Packet as SerialPacket;
    interface AMPacket as SerialAMPacket;
    interface ActiveMessageAddress;
    interface VehicleData;
    interface Leds;
  } provides {
    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  message_t * sendMsg;
  VehicleMsg sendBuf;
  bool sending;

  am_id_t ignoredAm;
  message_t * ignoredMsg;

  message_t recvAm;
  message_t * recvAmPtr;
  VehicleMsg * recvPayload;

  task void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    recvPayload = (VehicleMsg *)call SerialPacket.getPayload(recvAmPtr = &recvAm, sizeof(VehicleMsg));
    sending = FALSE;
    //carStopped = sendingBeacon = FALSE;
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  task void receiveMsgTask() {
    call Leds.led0Toggle();
    call SerialAMPacket.setSource(recvAmPtr, call ActiveMessageAddress.amAddress());
    //call SerialAMPacket.setSource(recvAmPtr, TOS_NODE_ID);
    call SerialAMPacket.setDestination(recvAmPtr, 0);
    call SerialAMPacket.setType(recvAmPtr, AM_VEHICLE_RECEIVE);
    call SerialAMPacket.setGroup(recvAmPtr, call SerialAMPacket.localGroup());
    call SerialPacket.setPayloadLength(recvAmPtr, sizeof(VehicleMsg));
    recvAmPtr = signal Receive.receive[AM_VEHICLE_RECEIVE](recvAmPtr, call SerialPacket.getPayload(recvAmPtr, sizeof(VehicleMsg)), sizeof(VehicleMsg));
    recvPayload = (VehicleMsg *)call SerialPacket.getPayload(recvAmPtr, sizeof(VehicleMsg));
  }
  event VehicleMsg * VehicleData.receive(VehicleMsg *msg) {
    recvPayload->dir = msg->dir;
    recvPayload->icnum = msg->icnum;
    recvPayload->speed = msg->speed;
    post receiveMsgTask();
    return msg;
  }
  event void VehicleData.sendDone(VehicleMsg *msg, error_t err) {
    signal AMSend.sendDone[AM_VEHICLE_SEND](sendMsg, err);
    sending = FALSE;
  }
  task void sendMsgIgnoredTask() {
    signal AMSend.sendDone[ignoredAm](ignoredMsg, SUCCESS); 
  }
  command error_t AMSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    VehicleMsg * vm;
    if (id != AM_VEHICLE_SEND) {
      ignoredAm = id;
      ignoredMsg = msg;
      post sendMsgIgnoredTask();
      return SUCCESS;
    }
    if (sending)
      return FAIL;
    vm = (VehicleMsg *)call SerialPacket.getPayload(msg, sizeof(VehicleMsg));
    sendBuf.speed = (uint8_t)vm->speed;
    sendBuf.dir = vm->dir;
    sendBuf.icnum = vm->icnum;
    sendMsg = msg;
    sending = TRUE;
    return call VehicleData.send(&sendBuf);
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
  async event void ActiveMessageAddress.changed() {}

  default event message_t* Receive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    return msg;
  }
  default event void AMSend.sendDone[am_id_t id](message_t* msg, error_t error) {
  }
}
