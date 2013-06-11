#ifndef ITS_CMD_INC
#define ITS_CMD_INC

//#include "Constants.h"
#define MAX_SENSOR_NUM 3
#define SENSOR_REACTION_TIME 1000
#define MAXQUEUE 3
#define CHIRP_TIME 1000
enum {
	// Used in the sensorType field
	SENSOR_TYPE_UNKNOWN = 0,
	SENSOR_TYPE_END = 1,
	SENSOR_TYPE_START = 2,
	SENSOR_TYPE_NORM = 3,
	SENSOR_TYPE_SIMPLE = 4,
	SENSOR_TYPE_ONLY = 8,
	SENSOR_TYPE_PARK = 9,
	SENSOR_TYPE_CAR = 10,
	// Used in the operationMode field
	OPER_EVERY_MSG = 5,
	OPER_SUMMARY_MSG = 6,
	OPER_LIGHT = 7,
	OPER_OCCUPIED = 12,
	OPER_UNOCCUPIED = 13,

	OPER_START	= 0x31,
	OPER_COLLISION = 0x32,
	OPER_NO_COLLISION	= 0x33,
	OPER_STOP = 0x34,
	OPER_TURN_RIGHT	= 0x35,
	OPER_TURN_LEFT	= 0x36
};

struct Sensor{
	uint16_t sensorID;
	uint16_t distance;
};

// For Java Mig
#ifndef __TOS_TIME__
#define __TOS_TIME__
typedef struct {
    uint32_t high32;
    uint32_t low32;
}tos_time_t;
#endif

typedef struct ITSCmdMsg {
	uint16_t sensorID;
	uint8_t sensorType;
	uint8_t operationMode;
	tos_time_t initTime;
	struct Sensor sensors[MAX_SENSOR_NUM];
} __attribute__ ((packed)) ITSCmdMsg;

typedef struct SensorControlMsg {
	uint16_t sensorID;
	uint8_t sensorType;
	uint8_t operationMode;
} __attribute__ ((packed)) SensorControlMsg;

enum {
  AM_ITSCMDMSG = 18, // For receiving command from server
	AM_SENSORCONTROLMSG = 19 // For use in CarMaintainerC
};

enum {
	AM__BCASTMSG=18
};
#include "Bcast.h"
#endif
