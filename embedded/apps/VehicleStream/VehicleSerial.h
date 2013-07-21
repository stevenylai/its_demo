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
  AM_VEHICLE_SEND = AM_VEHICLEMSG
};
#endif
