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
  bool recvBufBusy;

  VehicleMsg recvMsgBuf, *recvMsg, *sendMsg;

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
      recvMsg = &recvMsgBuf;
      recvBufBusy = FALSE;

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
  task void receiveMsgTask() {
    call Leds.led0Toggle();
    atomic {
      recvMsg->dir = recvBuf.dir;
      recvMsg->speed= recvBuf.speed;
      recvMsg->icnum = recvBuf.icnum;
    }
    recvMsg = signal VehicleData.receive(recvMsg);
    atomic recvBufBusy = FALSE;
  }
  command error_t VehicleData.send(VehicleMsg *msg) {
    atomic {
      sendBuf.speed = msg->speed;
      sendBuf.dir = msg->dir;
      sendBuf.icnum = msg->icnum;
      sendError = call UartStream.send((uint8_t *)&sendBuf, sizeof(vehicle_send_t));
    }
    sendMsg = msg;
    atomic return sendError;
  }
  task void sendMsgDoneTask() {
    error_t tmpError;
    atomic tmpError = sendError;
    signal VehicleData.sendDone(sendMsg, tmpError);
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    atomic sendError = error;
    post sendMsgDoneTask();
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
  async event void UartStream.receivedByte( uint8_t byte ) {
    atomic {
      if (byte == VEHICLE_PREAMBLE) {
        recvBufIdx = 0;
	recvBufBusy = TRUE;
      }
      if (recvBufIdx < sizeof(vehicle_receive_t)) {
        ((uint8_t *)&recvBuf)[recvBufIdx++] = byte;
        if (recvBufIdx == sizeof(vehicle_receive_t)) {
          post receiveMsgTask();
        }
      } else { /* Ignored */ }
    }
  } // UartStream.receivedByte
}
