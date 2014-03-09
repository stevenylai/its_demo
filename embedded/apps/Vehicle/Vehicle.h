#ifndef VEHICLE_H
#define VEHICLE_H

typedef nx_struct VehicleMsg {
  nx_uint8_t dir;
  nx_uint8_t icnum;
  nx_uint16_t speed;
} VehicleMsg;

/*typedef nx_struct BaseToMoteMsg {
  nx_uint8_t cmd;
  nx_uint16_t data;
} BaseToMoteMsg;*/

enum {
  AM_VEHICLEMSG = 0x0C,
  TIMER_PERIOD_MILLI = 250
};

#endif
