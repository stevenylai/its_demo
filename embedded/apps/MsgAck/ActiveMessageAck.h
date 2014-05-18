#ifndef ACTIVE_MESSAGE_ACK_H
#define ACTIVE_MESSAGE_ACK_H

#include "MsgList.h"
enum {
  MESSAGE_TYPE_SEND = 0,
  MESSAGE_TYPE_ACK = 1,
  ACK_HEAD_LEN = 1,
  MSG_QUEUE_LEN = 8,
};

struct msg_queue {
  msg_info_t buffer[MSG_QUEUE_LEN];
  uint8_t head;
  uint8_t tail;
};

static void queue_clear(struct msg_queue * queue) {
  queue->head = queue->tail = 0;
}
static bool queue_full(struct msg_queue * queue) {
  return (queue->tail + 1) % MSG_QUEUE_LEN == queue->head;
}
static bool queue_empty(struct msg_queue * queue) {
  return queue->head == queue->tail;
}
static void enqueue(struct msg_queue * queue, msg_info_t *item) {
  if (queue_full(queue)) { // Queue is full so make room first
    queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
  }
  memcpy(queue->buffer + queue->tail, item, sizeof(msg_info_t));
  queue->tail = (queue->tail + 1) % MSG_QUEUE_LEN;
}
static error_t dequeue(struct msg_queue * queue, msg_info_t *item) {
  if (queue_empty(queue))
    return FAIL;
  memcpy(item, queue->buffer + queue->head, sizeof(msg_info_t));
  queue->head = (queue->head + 1) % MSG_QUEUE_LEN;
  return SUCCESS;
}

#endif
