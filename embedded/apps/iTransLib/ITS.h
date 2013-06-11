#ifndef ITS_H_
#define ITS_H_

//#include "CarCmd.h"
//#include "Constants.h"
//#include "ITSCmd.h" // For the operation codes

// Constants used in this FYP
#define MAX_SENSOR_NUM 3
#define SENSOR_REACTION_TIME 1000
#define MAXQUEUE 3
#define CHIRP_TIME 1000

enum {
	// Used in the reading field
	SENSOR_UNCOVERED = 0,
	SENSOR_COVERED = 1
};
typedef struct ITSMsg {
	uint8_t vid;
	uint8_t roadnum;
	uint8_t roadjunc;
	uint8_t direction;	
	uint8_t status;
	uint8_t sid;
	/*
	uint16_t sensorID;
	uint8_t reading;
	uint8_t operationMode;
	uint8_t numCarPassed;
	*/
} __attribute__ ((packed)) ITSMsg;


typedef struct WarnMsg {
	uint8_t vid;
	uint8_t warningNo;
} __attribute__ ((packed)) WarnMsg;


enum {
  AM_ITSMSG = 22,
};

#endif
