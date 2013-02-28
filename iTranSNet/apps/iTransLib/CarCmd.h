#include <TosTime.h>

#ifndef CAR_CMD_INC
#define CAR_CMD_INC

struct car {
	uint16_t carID;
	uint16_t length;
	uint16_t speed;
};

enum {
	MSG_TYPE_INFORM = 0,
	MSG_TYPE_REPORT = 1,
	MSG_TYPE_WARN = 2,
	MSG_TYPE_PROCESSED = 3,
	MSG_TYPE_CONTROL = 4 // For sensors on the roads to send control information to the car
};/*
enum {
	CAR_STOP	= 0x31,
	CAR_MOVE_SLOW = 0x32,
	CAR_MOVE_FAST	= 0x33,
	CAR_TURN_LEFT	= 0x34,
	CAR_TURN_RIGHT	= 0x35};
*/
typedef struct CarCmdMsg {
	struct car c;
	// Used to calculate the car's speed
	tos_time_t startTime;
	tos_time_t endTime;
	uint16_t distance;
	bool reportBack;
	uint16_t sourceID;
		
	// Added 1 more field
	uint8_t msgType;
} __attribute__ ((packed)) CarCmdMsg;

enum {
  AM_CARCMDMSG = 22
};
/*
// added for demonstration purpose:
typedef struct CarControlMsg {
	uint16_t sensorID;
	uint8_t sensorType;
	uint8_t operationMode;
} __attribute__ ((packed)) CarControlMsg;
*/
#endif
