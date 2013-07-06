#include "VehicleSerial.h"
module VehicleAmP {
  uses {
    interface UartStream;
    interface Packet as SerialPacket;
  } provides {
    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  vehicle_send_t sendBuf;
  uint8_t* sendMsg;
  error_t sendError;

  am_id_t ignoredAm;
  message_t * ignoredMsg;

  vehicle_receive_t recvBuf;
  uint8_t recvBufIdx;
  message_t recvAm;
  message_t * recvAmPtr;

  void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  void startDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    atomic {
      recvBuf.id = TOS_NODE_ID;
      recvBuf.speed = 0;

      recvBufIdx = sizeof(vehicle_receive_t);
      recvAmPtr = &recvAm;

      sendBuf.preemble = 0xFF; // Always fixed
    }
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  void receiveMsgTask() {
    recvAmPtr = signal Receive.receive[AM_VEHICLE_RECEIVE](recvAmPtr, call SerialPacket.getPayload(recvAmPtr, sizeof(MoteToBaseMsg)), sizeof(MoteToBaseMsg));
  }
  void sendMsgDoneTask() {
    uint8_t* tmpMsg;
    error_t tmpError;
    atomic {
      tmpMsg = sendMsg;
      tmpError = sendError;
    }
    signal AMSend.sendDone[AM_VEHICLE_SEND](tmpMsg, sendError);
  }
  void sendMsgIgnoredTask() {
    signal AMSend.sendDone[ignoredAm](ignoredMsg, SUCCESS); 
  }
  command error_t AMSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    if (id != AM_VEHICLE_SEND) {
      ignoredAm = id;
      ignoredMsg = msg;
      post sendMsgIgnoredTask();
      return SUCCESS;
    }
    BaseToMoteMsg * btm = (BaseToMoteMsg *)call SerialPacket.getPayload(msg, sizeof(BaseToMoteMsg));
    atomic {
      sendBuf.id = recvBuf.id;
      sendError = SUCCESS;
      if (cmd == 0x01) { // set speed
        sendBuf.speed = btm->data;
        sendBuf.icnum = 0;
      } else if (cmd == 0x02) { // set turn
        sendBuf.speed = (recvBuf.speed ? recvBuf.speed : VEHICLE_DEFAULT_SPEED);
        sendBuf.dir = btm->data >> 8;
        sendBuf.icnum = (uint8_t) (btm->data & 0xFF);
      } else  // Unknown command
        sendError = FAIL;
      if (!sendError) {
        sendMsg = msg;
        sendError = call UartStream.send(&sendBuf, sizeof(vehicle_send_t));
      }
    }
    return sendError;
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
      if (byte == VEHICLE_PREEMBLE) {
        recvBufIdx = 0;
      }
      if (recvBufIdx < sizeof(vehicle_receive_t)) {
        ((uint8_t *)&recvBufIdx)[recvBufIdx++] = byte;
        if (recvBufIdx == sizeof(vehicle_receive_t)) {
          MoteToBaseMsg * mtb = (MoteToBaseMsg *)call SerialPacket.getPayload(recvAmPtr, sizeof(MoteToBaseMsg));
          mtb->dir = recvBuf.dir;
          mtb->icnum = recvBuf.icnum;
          mtb->speed = recvBuf.speed;
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

  default event message_t* Receive.receive[am_id_t id](message_t* msg, void* payload, uint8_t len) {
    return msg;
  }
  default event void AMSend.sendDone[am_id_t id](message_t* msg, error_t error) {
  }
}
