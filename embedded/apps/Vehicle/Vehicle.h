#ifndef VEHICLE_H
#define VEHICLE_H

typedef nx_struct MoteToBaseMsg {
  nx_uint8_t dir;
  nx_uint8_t icnum;
  nx_uint16_t speed;
} MoteToBaseMsg;

typedef nx_struct BaseToMoteMsg {
  nx_uint8_t cmd;
  nx_uint16_t data;
} BaseToMoteMsg;

enum {
  AM_MOTETOBASEMSG = 0x0C,
  AM_BASETOMOTEMSG = 0x0A,
  TIMER_PERIOD_MILLI = 250
};

#endif
