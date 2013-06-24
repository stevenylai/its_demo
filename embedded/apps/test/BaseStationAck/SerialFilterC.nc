#include "../../Vehicle/Vehicle.h"

module SerialFilterC {
  uses {
    interface Receive as UartReceive[am_id_t id];
    interface ActiveMessageAddress;
  }
  provides {
    interface Receive as UartFilteredReceive[am_id_t id];
  }
} implementation {
  event message_t *UartReceive.receive[am_id_t id](message_t *msg, void *payload, uint8_t len) {
    MoteToBaseMsg * mvm = (MoteToBaseMsg*)payload;
    if (mvm->nodeid != call ActiveMessageAddress.amAddress()) {
      call ActiveMessageAddress.setAddress(call ActiveMessageAddress.amGroup(), mvm->nodeid);
    }
    if (mvm->nodeid != TOS_NODE_ID) {
      TOS_NODE_ID = mvm->nodeid;
    }
    return signal UartFilteredReceive.receive[id](msg, payload, len);
  }
  async event void ActiveMessageAddress.changed() {
  }
}
