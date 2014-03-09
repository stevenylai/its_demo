#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

typedef nx_struct TrafficLightMsg {
  nx_uint8_t dir;
  nx_uint8_t color;
  nx_uint16_t remain;
} TrafficLightMsg;

enum {
  COLOR_GREEN=1,
  COLOR_YELLOW=2,
  COLOR_RED=3,
  DIR_NORTH=4,
  DIR_SOUTH=12,
  DIR_EAST=0,
  DIR_WEST=8,

  AM_TRAFFICLIGHTMSG = 0x0C,
  TIMER_PERIOD_MILLI = 250
};

#endif
