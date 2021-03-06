#ifndef ACTIVE_MESSAGE_ACK_H
#define ACTIVE_MESSAGE_ACK_H

#include "MsgList.h"
enum {
  MESSAGE_TYPE_SEND = 0x0,
  MESSAGE_TYPE_ACK = 0x80,
  ACK_HEAD_LEN = 1,
  MSG_QUEUE_LEN = 4,
};

struct msg_queue {
  msg_info_t buffer[MSG_QUEUE_LEN];
  uint8_t head;
  uint8_t tail;
};

#endif
