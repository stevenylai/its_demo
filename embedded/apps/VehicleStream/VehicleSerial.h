#ifndef VEHICLE_SERIAL_H
#define VEHICLE_SERIAL_H
#include "Vehicle.h"
typedef nx_struct vehicle_receive {
  nx_uint8_t preamble;
  nx_uint8_t length;
  nx_uint8_t id;
  nx_uint8_t speed;
  nx_uint8_t dir;
  nx_uint8_t icnum;
} vehicle_receive_t;
typedef nx_struct vehicle_send {
  nx_uint8_t preamble;
  nx_uint8_t id;
  nx_uint8_t speed;
  nx_uint8_t dir;
  nx_uint8_t icnum;
} vehicle_send_t;
enum {
  VEHICLE_PREAMBLE = 0xFF,
  VEHICLE_DEFAULT_SPEED = 25,
  AM_VEHICLE_RECEIVE = AM_VEHICLEMSG,
  AM_VEHICLE_SEND = AM_VEHICLEMSG,
  RECEIVE_QUEUE_LEN = 4,
  STOP_TIMEOUT = 4,
};
struct vehicle_receive_queue {
  vehicle_receive_t buffer[RECEIVE_QUEUE_LEN];
  int head;
  int tail;
};

static void queue_clear(struct vehicle_receive_queue * queue, int queue_len) {
  queue->head = queue->tail = 0;
}
static bool queue_empty(struct vehicle_receive_queue * queue, int queue_len) {
  return queue->head == queue->tail;
}
static void enqueue(struct vehicle_receive_queue * queue, int queue_len, vehicle_receive_t *item) {
  if ((queue->tail + 1) % queue_len == queue->head) { // Queue is full so make room first
    queue->head = (queue->head + 1) % queue_len;
  }
  queue->buffer[queue->tail] = *item;
  queue->tail = (queue->tail + 1) % queue_len;
}
static error_t dequeue(struct vehicle_receive_queue * queue, int queue_len, vehicle_receive_t *item) {
  if (queue_empty(queue, queue_len))
    return FAIL;
  *item = queue->buffer[queue->head];
  queue->head = (queue->head + 1) % queue_len;
  return SUCCESS;
}
#endif
