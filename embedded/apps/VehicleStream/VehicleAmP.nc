#include "VehicleSerial.h"
module VehicleAmP {
  uses {
    interface UartStream;
    interface Packet as SerialPacket;
    interface AMPacket as SerialAMPacket;
    interface ActiveMessageAddress;
    interface Leds;
  } provides {
    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  vehicle_send_t sendBuf;
  message_t * sendMsg;
  error_t sendError;

  am_id_t ignoredAm;
  message_t * ignoredMsg;

  vehicle_receive_t recvBuf;
  uint8_t recvBufIdx;
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
    atomic {
      recvBuf.id = TOS_NODE_ID;
      recvBuf.speed = 0;

      recvBufIdx = sizeof(vehicle_receive_t);
      recvPayload = (VehicleMsg *)call SerialPacket.getPayload(recvAmPtr = &recvAm, sizeof(VehicleMsg));

      sendBuf.preamble = 0xFF; // Always fixed
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
      sendError = call UartStream.send((uint8_t *)&sendBuf, sizeof(vehicle_send_t));
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

  async event void UartStream.receivedByte( uint8_t byte ) {
    atomic {
      if (byte == VEHICLE_PREAMBLE) {
        recvBufIdx = 0;
      }
      if (recvBufIdx < sizeof(vehicle_receive_t)) {
        ((uint8_t *)&recvBuf)[recvBufIdx++] = byte;
        if (recvBufIdx == sizeof(vehicle_receive_t)) {
          recvPayload->dir = recvBuf.dir;
          recvPayload->icnum = recvBuf.icnum;
          recvPayload->speed = recvBuf.speed;
          post receiveMsgTask();
        }
      } else {
        // Ignored
      }
    }
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    atomic sendError = error;
    post sendMsgDoneTask();
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
  async event void ActiveMessageAddress.changed() {}

  default event message_t* Receive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    return msg;
  }
  default event void AMSend.sendDone[am_id_t id](message_t* msg, error_t error) {
  }
}
