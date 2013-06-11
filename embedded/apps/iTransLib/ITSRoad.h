#ifndef  ITS_ROAD_H_
#define  ITS_ROAD_H_

enum {
	AM_ITSROADSENSEMSG=7,
};

typedef struct ITSRoadSenseMsg {
  uint8_t loc;
  uint16_t data;
} __attribute__ ((packed)) ITSRoadSenseMsg;
#endif

