#include "TrafficLightSerial.h"

module TrafficLightDataP {
  uses {
    interface UartStream;
    interface Leds;
    interface Timer<TMilli> as Timer;
  } provides {
    interface SplitControl;
    interface TrafficLightData;
  }
} implementation {
  traffic_light_receive_t recvBuf;
  uint8_t recvBufIdx;
  struct traffic_light_receive_queue recvQueue;

  TrafficLightMsg recvMsgBuf, *recvMsg, *sendMsg;

  traffic_light_send_t sendBuf;
  error_t sendError;
  int lightColor[DIR_TOTAL];
  int aliveTimer;

  task void startDoneTask() {
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask() {
    signal SplitControl.stopDone(SUCCESS);
  }
  command error_t SplitControl.start() {
    int i;
    atomic {
      for (i = 0; i < DIR_TOTAL; i++)
        lightColor[i] = 0;
      recvBuf.id = TOS_NODE_ID;
      recvBuf.dir = 0;
      recvBuf.remain = 0;
      recvBufIdx = sizeof(traffic_light_receive_t);
      recvMsg = &recvMsgBuf;
      queue_clear(&recvQueue, RECEIVE_QUEUE_LEN);

      sendBuf.preamble = TRAFFICLIGHT_PREAMBLE; // Always fixed
      sendBuf.id = recvBuf.id;
      aliveTimer = 0;
    }
    call Timer.startPeriodic(250);
    post startDoneTask();
    return SUCCESS;
  }
  command error_t SplitControl.stop() {
    post stopDoneTask();
    return SUCCESS;
  }
  task void receiveQueueTask() {
    traffic_light_receive_t item;
    atomic {
      if (dequeue(&recvQueue, RECEIVE_QUEUE_LEN, &item) == SUCCESS) {
        recvMsg->dir = item.dir >> 4 & 0x03;
        recvMsg->color = item.dir & 0x03;
        recvMsg->remain = item.remain;
        recvMsg = signal TrafficLightData.receive(recvMsg);
      }
      if (!queue_empty(&recvQueue, RECEIVE_QUEUE_LEN))
        post receiveQueueTask();
    }
  }

  command error_t TrafficLightData.send(TrafficLightMsg *msg) {
    atomic {
      sendBuf.dir = 0xC0 | msg->dir << 4  | msg->color ;
      sendBuf.remain = msg->remain;
      sendError = call UartStream.send((uint8_t *)&sendBuf, sizeof(traffic_light_send_t));
    }
    sendMsg = msg;
    atomic return sendError;
  }
  task void sendMsgDoneTask() {
    error_t tmpError;
    atomic tmpError = sendError;
    signal TrafficLightData.sendDone(sendMsg, tmpError);
  }
  event void Timer.fired() {
    atomic aliveTimer++;
  }
  async event void UartStream.sendDone( uint8_t* buf, uint16_t len, error_t error ) {
    atomic sendError = error;
    post sendMsgDoneTask();
  }
  async event void UartStream.receiveDone( uint8_t* buf, uint16_t len, error_t error ) {
  }
  async event void UartStream.receivedByte( uint8_t byte ) {
    atomic {
      if (byte == TRAFFICLIGHT_PREAMBLE)
        recvBufIdx = 0;
      if (recvBufIdx < sizeof(traffic_light_receive_t)) {
        ((uint8_t *)&recvBuf)[recvBufIdx++] = byte;
        if (recvBufIdx == sizeof(traffic_light_receive_t)) {
          uint8_t real_dir = recvBuf.dir >> 4 & 0x03;
          uint8_t real_color = recvBuf.dir & 0x03;
          sendBuf.id = recvBuf.id;
          if (aliveTimer >= ALIVE_TIMEOUT || (real_dir < DIR_TOTAL && lightColor[real_dir] != real_color)) {
            enqueue(&recvQueue, RECEIVE_QUEUE_LEN, &recvBuf);
            post receiveQueueTask();
            lightColor[real_dir] = real_color;
            aliveTimer = 0;
          }
        }
      } else { /* Ignored */ }
    } // atomic
  } // UartStream.receivedByte
}
