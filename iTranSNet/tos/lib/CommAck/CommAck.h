#ifndef COMM_ACK
#define COMM_ACK
#include "AM.h"

#define MSG_SEND 0xff
#define MSG_ACK 0xfe
#define MSG_BCAST 0xfd
#define MAX_RETRIAL 10

enum {
	IDLE,
	SEND,
	BROADCAST,
	RECEIVE,
	TOSH_HEADER_ACK_LENGTH = 4,
	TOSH_DATA_ACK_LENGTH = (TOSH_DATA_LENGTH-TOSH_HEADER_ACK_LENGTH),
	BCAST_TARGET=100,
	BCAST_COUNT=4,
	AM_MSGACK=2,
#ifdef PLATFORM_PC
	TIMEOUT=16
#else
	TIMEOUT=16
#endif
};
typedef struct Receiver {
	uint16_t receiver;
	bool received;
} Receiver;
typedef struct PendingMsg {
	TOS_MsgPtr msg;
	uint8_t am_type;
	uint8_t length;
	uint16_t address;
} PendingMsg;
typedef struct MsgACK {
	uint8_t am_type;
	uint8_t type;
	uint16_t source;
	//int8_t data[TOSH_DATA_ACK_LENGTH];
} __attribute__ ((packed)) MsgACK;

#endif
