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

  DIR_NORTH=1,
  DIR_SOUTH=3,
  DIR_EAST=0,
  DIR_WEST=2,
  DIR_TOTAL = 4,

  AM_TRAFFICLIGHTMSG = 0x0D,
  TIMER_PERIOD_MILLI = 250
};

#endif
