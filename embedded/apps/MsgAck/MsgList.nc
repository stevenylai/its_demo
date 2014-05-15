#include "MsgList.h"

interface MsgList {
  command void init();
  command bool full();
  command bool empty();
  command uint8_t size();
  command error_t add(message_t * msg, uint8_t len);
  command void remove(message_t * msg);
  command msg_info_t * get(uint8_t idx);
  event bool resend(msg_info_t * msgInfo);
}
