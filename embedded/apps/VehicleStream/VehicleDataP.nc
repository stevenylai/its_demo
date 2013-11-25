#include "VehicleSerial.h"

module VehicleDataP {
  uses {
    interface UartStream;
    interface Leds;
  } provides {
    interface SplitControl;
    interface VehicleData;
  }
} implementation {
  vehicle_receive_t recvBuf;
  uint8_t recvBufIdx;
  bool recvBufferBusy;
  VehicleMsg recvMsgBuf, *recvMsgPtr, *sendMsgPtr;

  vehicle_send_t sendBuf;
  error_t sendError;

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
      recvMsgPtr = &recvMsgBuf;
      recvBufferBusy = false;

      sendBuf.preamble = 0xFF; // Always fixed
      sendBuf.id = TOS_NODE_ID;
    }
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  task void receiveMsgTask() {
    call Leds.led0Toggle();
    atomic {
      recvMsgPtr->dir = recvBuf.dir;
      recvMsgPtr->speed= recvBuf.speed;
      recvMsgPtr->icnum = recvBuf.icnum;
    }
    recvMsgPtr = signal VehicleData.receive(recvMsgPtr);
    atomic recvBufferBusy = false;
  }
  event VehicleMsg * VehicleData.receive(VehicleMsg *msg) {
    recvMsgPtr->dir = msg->dir;
    recvMsgPtr->speed= msg->speed;
    recvMsgPtr->icnum = msg->icnum;
  }
  command error_t VehicleData.send(VehicleMsg *msg) {
  }
  event VehicleData.sendDone(VehicleMsg * msg, error_t err) {
  }
  command error_t VehicleData.send(VehicleMsg *msg) {
    atomic {
      sendBuf.speed = msg->speed;
      sendBuf.dir = msg->dir;
      sendBuf.icnum = msg->icnum;
      sendError = call UartStream.send((uint8_t *)&sendBuf, sizeof(vehicle_send_t));
      sendMsg = msg;
    }
    return sendError;
  }
  task void sendMsgDoneTask() {
    message_t * tmpMsg;
    error_t tmpError;
    atomic {
      tmpMsg = sendMsg;
      tmpError = sendError;
    }
    signal VehicleData.sendDone(tmpMsg, tmpError);
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    atomic sendError = error;
    post sendMsgDoneTask();
  }
}
