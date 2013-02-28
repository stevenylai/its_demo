#ifndef RSU_RELAY
#define RSU_RELAY
#define TRAFFIC_INTERSECTION_OFFSET 32

enum {
	GREEN=1,
	YELLOW=2,
	RED=3,
	NORTH=4,
	SOUTH=12,
	EAST=0,
	WEST=8,
	RECEIVE_BUFFER_LEN=5,
	SEND_BUFFER_LEN=6
};

enum {
	AM_TRAFLEDCTROL1 = 1,
	AM_TRAFLEDCTROL2 = 70,
	AM_TRAFFIC=2,
	AM_TEST= 4,
};

uint8_t interJunct2CarJunct(uint8_t newID) {
	if (newID==8)
		return 1;
	else if (newID==12)
		return 2;
	else if (newID==0)
		return 3;
	else if (newID==4)
		return 4;
	return 0;
}
uint8_t carJunct2InterJunct(uint8_t oldID) {
	if (oldID==1)
		return 8;
	else if (oldID==2)
		return 12;
	else if (oldID==3)
		return 0;
	else if (oldID==4)
		return 4;
	return 0;
}
uint8_t senorID2InterID (uint8_t sensorID) {
	return sensorID-TRAFFIC_INTERSECTION_OFFSET;
}
uint8_t InterID2senorID (uint8_t interID) {
	return interID+TRAFFIC_INTERSECTION_OFFSET;
}
#endif
