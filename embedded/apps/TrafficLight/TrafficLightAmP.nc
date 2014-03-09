#include "TrafficLightSerial.h"
module TrafficLightAmP {
  uses {
    interface Packet as SerialPacket;
    interface AMPacket as SerialAMPacket;
    interface ActiveMessageAddress;
    interface TrafficLightData;
    interface Leds;
  } provides {
    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  message_t * sendMsg;
  TrafficLightMsg sendBuf;
  bool sending;

  am_id_t ignoredAm;
  message_t * ignoredMsg;

  message_t recvAm;
  message_t * recvAmPtr;
  TrafficLightMsg * recvPayload;

  task void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    recvPayload = (TrafficLightMsg *)call SerialPacket.getPayload(recvAmPtr = &recvAm, sizeof(TrafficLightMsg));
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
    call SerialAMPacket.setDestination(recvAmPtr, 0);
    call SerialAMPacket.setType(recvAmPtr, AM_TRAFFICLIGHT_RECEIVE);
    call SerialAMPacket.setGroup(recvAmPtr, call SerialAMPacket.localGroup());
    call SerialPacket.setPayloadLength(recvAmPtr, sizeof(TrafficLightMsg));
    recvAmPtr = signal Receive.receive[AM_TRAFFICLIGHT_RECEIVE](recvAmPtr, call SerialPacket.getPayload(recvAmPtr, sizeof(TrafficLightMsg)), sizeof(TrafficLightMsg));
    recvPayload = (TrafficLightMsg *)call SerialPacket.getPayload(recvAmPtr, sizeof(TrafficLightMsg));
  }
  event TrafficLightMsg * TrafficLightData.receive(TrafficLightMsg *msg) {
    recvPayload->dir = msg->dir;
    recvPayload->color = msg->color;
    recvPayload->remain = msg->remain;
    post receiveMsgTask();
    return msg;
  }
  event void TrafficLightData.sendDone(TrafficLightMsg *msg, error_t err) {
    signal AMSend.sendDone[AM_TRAFFICLIGHT_SEND](sendMsg, err);
    sending = FALSE;
  }
  task void sendMsgIgnoredTask() {
    signal AMSend.sendDone[ignoredAm](ignoredMsg, SUCCESS); 
  }
  command error_t AMSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    TrafficLightMsg * m;
    if (id != AM_TRAFFICLIGHT_SEND) {
      ignoredAm = id;
      ignoredMsg = msg;
      post sendMsgIgnoredTask();
      return SUCCESS;
    }
    if (sending)
      return FAIL;
    m = (TrafficLightMsg *)call SerialPacket.getPayload(msg, sizeof(TrafficLightMsg));
    sendBuf.dir = m->dir;
    sendBuf.color = m->color;
    sendBuf.remain = m->remain;
    sendMsg = msg;
    sending = TRUE;
    return call TrafficLightData.send(&sendBuf);
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
