#include "VehicleSerial.h"

module VehicleDataP {
  uses {
    interface UartStream;
    interface Leds;
    interface Timer<TMilli> as Timer;
  } provides {
    interface SplitControl;
    interface VehicleData;
  }
} implementation {
  vehicle_receive_t recvBuf;
  uint8_t recvBufIdx;
  struct vehicle_receive_queue recvQueue;

  VehicleMsg recvMsgBuf, *recvMsg, *sendMsg;

  vehicle_send_t sendBuf;
  error_t sendError;

  int counter;

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

  task void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    atomic {
      recvBuf.id = TOS_NODE_ID;
      recvBuf.speed = 0;
      recvBuf.dir = 0;
      recvBuf.icnum = 0;
      recvBufIdx = sizeof(vehicle_receive_t);
      recvMsg = &recvMsgBuf;
      queue_clear(&recvQueue, RECEIVE_QUEUE_LEN);

      sendBuf.preamble = 0xFF; // Always fixed
      sendBuf.id = TOS_NODE_ID;
      counter = 0;
    }
    call Timer.startPeriodic(1000);
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  task void receiveQueueTask() {
    vehicle_receive_t item;
    atomic {
      if (dequeue(&recvQueue, RECEIVE_QUEUE_LEN, &item) == SUCCESS) {
        recvMsg->speed = item.speed;
        recvMsg->icnum = item.icnum;
        recvMsg->dir = item.dir;
        recvMsg = signal VehicleData.receive(recvMsg);
      }
      if (!queue_empty(&recvQueue, RECEIVE_QUEUE_LEN))
        post receiveQueueTask();
    }
  }
  event void Timer.fired() {
    atomic {
      if (++counter > STOP_TIMEOUT) {
        enqueue(&recvQueue, RECEIVE_QUEUE_LEN, &recvBuf);
        counter = 0;
        post receiveQueueTask();
      }
    }
  }

  command error_t VehicleData.send(VehicleMsg *msg) {
    atomic {
      sendBuf.id = recvBuf.id;
      sendBuf.speed = msg->speed;
      sendBuf.dir = msg->dir;
      sendBuf.icnum = msg->icnum;
      sendError = call UartStream.send((uint8_t *)&sendBuf, sizeof(vehicle_send_t));
    }
    sendMsg = msg;
    atomic return sendError;
  }
  task void sendMsgDoneTask() {
    error_t tmpError;
    atomic tmpError = sendError;
    signal VehicleData.sendDone(sendMsg, tmpError);
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    atomic sendError = error;
    post sendMsgDoneTask();
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
  async event void UartStream.receivedByte( uint8_t byte ) {
    atomic {
      if (byte == VEHICLE_PREAMBLE)
        recvBufIdx = 0;
      if (recvBufIdx < sizeof(vehicle_receive_t)) {
        ((uint8_t *)&recvBuf)[recvBufIdx++] = byte;
        if (recvBufIdx == sizeof(vehicle_receive_t)) {
          if (recvBuf.speed)
            counter = 0;
          call Leds.led1Toggle();
          enqueue(&recvQueue, RECEIVE_QUEUE_LEN, &recvBuf);
          post receiveQueueTask();
        }
      } else { /* Ignored */ }
    }
  } // UartStream.receivedByte
}
