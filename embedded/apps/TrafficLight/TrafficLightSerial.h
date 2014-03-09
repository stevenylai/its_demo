#ifndef TRAFFICLIGHT_SERIAL_H
#define TRAFFICLIGHT_SERIAL_H
#include "TrafficLight.h"

typedef nx_struct traffic_light_receive {
  nx_uint8_t preamble;
  nx_uint8_t length;
  nx_uint8_t id;
  nx_uint8_t dir;
  nx_uint8_t remain;
} traffic_light_receive_t;
typedef nx_struct traffic_light_send {
  nx_uint8_t preamble;
  nx_uint8_t id;
  nx_uint8_t dir;
  nx_uint8_t remain;
} traffic_light_send_t;
enum {
  TRAFFICLIGHT_PREAMBLE = 0xFF,
  TRAFFICLIGHT_DEFAULT_SPEED = 25,
  AM_TRAFFICLIGHT_RECEIVE = AM_TRAFFICLIGHTMSG,
  AM_TRAFFICLIGHT_SEND = AM_TRAFFICLIGHTMSG,
  RECEIVE_QUEUE_LEN = 4,
  //STOP_TIMEOUT = 4,
};

struct traffic_light_receive_queue {
  traffic_light_receive_t buffer[RECEIVE_QUEUE_LEN];
  int head;
  int tail;
};

static void queue_clear(struct traffic_light_receive_queue * queue, int queue_len) {
  queue->head = queue->tail = 0;
}
static bool queue_empty(struct traffic_light_receive_queue * queue, int queue_len) {
  return queue->head == queue->tail;
}
static void enqueue(struct traffic_light_receive_queue * queue, int queue_len, traffic_light_receive_t *item) {
  if ((queue->tail + 1) % queue_len == queue->head) { // Queue is full so make room first
    queue->head = (queue->head + 1) % queue_len;
  }
  queue->buffer[queue->tail] = *item;
  queue->tail = (queue->tail + 1) % queue_len;
}
static error_t dequeue(struct traffic_light_receive_queue * queue, int queue_len, traffic_light_receive_t *item) {
  if (queue_empty(queue, queue_len))
    return FAIL;
  *item = queue->buffer[queue->head];
  queue->head = (queue->head + 1) % queue_len;
  return SUCCESS;
}
#endif
