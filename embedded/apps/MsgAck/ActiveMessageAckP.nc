#include "ActiveMessage.h"
#include "ActiveMessageAck.h"

module ActiveMessageAckP {
  uses {
    interface Boot;
    interface MsgList;
    
    interface AMSend as RadioSend[am_id_t id];
    interface Receive as RadioReceive[am_id_t id];
    interface Receive as RadioSnoop[am_id_t id];
    interface Packet as RadioPacket;
    interface AMPacket as RadioAMPacket;
  } provides {
    interface AMSend as AckSend[am_id_t id];
    interface Receive as AckReceive[am_id_t id];
    interface Receive as AckSnoop[am_id_t id];
    interface Packet as AckPacket;
    interface AMPacket as AckAMPacket;
  }
} implementation {
  bool msgBusy;
  uint8_t seq;

  event void Boot.booted() {
    call MsgList.init();
    msgBusy = FALSE;
    seq = 0;
  }

  event bool MsgList.resend(msg_info_t * msgInfo) {
  }

  command error_t AckSend.send[am_id_t id](am_addr_t addr, message_t* msg, uint8_t len) {
    bool msgFull = call MsgList.full();
    if (msgFull)
      return FAIL;
    else {
      uint8_t * payload = (uint8_t *)call RadioPacket.getPayload(msg, len + 1);
      if (!payload)
        return FAIL;
      memmove(payload + 1, payload, len);
      payload[0] = MESSAGE_TYPE_SEND << 7 & (seq++);
      call RadioAMPacket.setType(msg, id);
      call RadioAMPacket.setDestination(msg, addr);
      call RadioPacket.setPayloadLength(msg, len + 1);
      if (!msgBusy)
        call RadioSend[id](addr, msg, len + 1);
      return call MsgList.add(msg);
    }
  }

  command error_t AckSend.cancel[am_id_t id](message_t* msg) {
    call MsgList.remove(msg);
    return SUCCESS;
  }

  command uint8_t AckSend.maxPayloadLength[am_id_t id]() {
  }

  command void* AckSend.getPayload[am_id_t id](message_t* msg, uint8_t len) {
  }
}
