#ifndef VEHICLE_H
#define VEHICLE_H

typedef nx_struct BaseToMoteMsg {
  nx_uint16_t nodeid;
  nx_uint8_t dir;
  nx_uint16_t speed;
  //nx_uint8_t cmd;
  //nx_uint16_t data;
} BaseToMoteMsg;

typedef nx_struct MoteToBaseMsg {
  nx_uint8_t dir;
  nx_uint8_t icnum;
  nx_uint16_t speed;
} MoteToBaseMsg;

typedef nx_struct MoteToVehicleMsg {
  nx_uint8_t cmd;
  nx_uint16_t data;
} MoteToVehicleMsg;

typedef nx_struct VehicleToMoteMsg {
  nx_uint8_t dir;
  nx_uint8_t IC_NO;
  nx_uint16_t speed;
} VehicleToMoteMsg;

enum {
  AM_MOTETOBASEMSG = 6,
  AM_MOTETOVEHICLEMSG = 8,
  AM_BASETOMOTEMSG = 10,
  AM_VEHICLETOMOTEMSG = 12,
  TIMER_PERIOD_MILLI = 250
};

#endif
