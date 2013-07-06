#ifndef VEHICLE_SERIAL_H
#define VEHICLE_SERIAL_H
#include "Vehicle.h"
typedef nx_struct vehicle_receive {
  nx_uint8_t preemble;
  nx_uint8_t length;
  nx_uint8_t id;
  nx_uint8_t speed;
  nx_uint8_t dir;
  nx_uint8_t icnum;
} vehicle_receive_t;
typedef nx_struct vehicle_send {
  nx_uint8_t preemble;
  nx_uint8_t id;
  nx_uint8_t speed;
  nx_uint8_t dir;
  nx_uint8_t icnum;
} vehicle_send_t;
enum {
  VEHICLE_PREEMBLE = 0xFF,
  VEHICLE_DEFAULT_SPEED = 25,
  AM_VEHICLE_RECEIVE = AM_BASETOMOTEMSG,
  AM_VEHICLE_SEND = AM_MOTETOBASEMSG
};
#endif
