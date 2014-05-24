#ifndef MSG_LIST_H
#define MSG_LIST_H

#include "AM.h"
#define ACK_QUEUE_LEN 8
#define RESEND_TICK 3

typedef struct msg_info {
  message_t msg;
  am_id_t am_id;
  am_addr_t dest;
  uint8_t len;
  uint8_t retrial;
  uint8_t tick;
} msg_info_t;

struct msg_info_list {
  msg_info_t msgs[ACK_QUEUE_LEN];
  uint8_t capacity;
  uint8_t used;
};

#endif
