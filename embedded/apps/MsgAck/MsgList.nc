#include "MsgList.h"

interface MsgList {
  command void init();
  command bool full();
  command bool empty();
  command uint8_t size();
  command error_t add(am_id_t am_id, am_addr_t dest, message_t * msg, uint8_t len);
  command void removeByMsg(message_t * msg);
  command void removeByInfo(am_addr_t dest, am_id_t am_id);
  command msg_info_t * get(uint8_t idx);
  event bool resend(msg_info_t * msgInfo);
}
