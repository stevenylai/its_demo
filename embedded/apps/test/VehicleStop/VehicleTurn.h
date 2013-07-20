#ifndef VEHICLE_TURN_H
#define VEHICLE_TURN_H

typedef nx_struct VehicleTurnMsg {
  nx_uint8_t turnPoint;
  nx_uint32_t delay;
} VehicleTurnMsg;
enum {
  AM_VEHICLETURNMSG = 0x0B,
};
#endif
