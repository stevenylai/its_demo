#include "../../Vehicle/Vehicle.h"

module SerialFilterP {
  uses {
    interface Receive as UartReceive[am_id_t id];
    interface ActiveMessageAddress;
    interface AMPacket;
  } provides {
    interface Receive as UartFilteredReceive[am_id_t id];
  }
} implementation {
  event message_t *UartReceive.receive[am_id_t id](message_t *msg, void *payload, uint8_t len) {
    bool filtered = FALSE;

    if (call AMPacket.type(msg) == AM_MOTETOBASEMSG) {
      call AMPacket.setSource(msg, call ActiveMessageAddress.amAddress()); // Set the source to the node itself
      call AMPacket.setDestination(msg, 0); // Set the destination to the sink
      if (len != sizeof(MoteToBaseMsg)) {
        filtered = TRUE;
      } else {
        MoteToBaseMsg * mvm = (MoteToBaseMsg*)payload;
        if (!mvm->icnum) // icnum not init'd - ignore the message
          filtered = TRUE;
      }
    }

    if (filtered) 
      return msg;
    else
      return signal UartFilteredReceive.receive[id](msg, payload, len);
  }
  async event void ActiveMessageAddress.changed() {
  }
}
