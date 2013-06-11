#ifndef P_EVENT
#define P_EVENT

#define META_EVENT_SPACE 50
#define EVENT_SPACE 100
#define INVALID_ID 0xff
#include "TosTime.h"
#include "MateConstants.h"

enum {
	EVENT_META_UPDATE=0,
	EVENT_META_DELETE=1,
	EVENT_META_SUBSCRIBE=2,
	EVENT_HEADER_LEN=sizeof(uint16_t)*2+sizeof(uint8_t)*2,
	EVENT_INSTANCE_MSG_HEADER_LEN=sizeof(uint16_t)+sizeof(uint8_t)*3,
	EVENT_ID_WILDCARD=255,
	EVENT_OPTION_CREATED=0,
	EVENT_OPTION_DETECTED=1,
	EVENT_OPTION_UNDETECTED=2,
	EVENT_OPTION_AGGREGATE=3,
	EVENT_OPTION_SENDING=4,
	TABLE_R_SIZE=2,
	TABLE_E_SIZE=1,
};

typedef struct {
	uint16_t sourceID;
	uint16_t time;
	uint8_t subID;
	uint8_t instanceID;
	uint16_t content[1];
} __attribute__ ((packed)) EventInstanceInfo;

typedef struct EventInstanceMsg{
	uint16_t sourceID;
	uint8_t subID;
	uint8_t totalChunk;
	uint8_t seq;
	uint8_t padding; // For compatibility between micaz and telosb
	uint16_t content[10];
} EventInstanceMsg;

typedef struct {
	uint8_t subID;
	uint8_t type;
	uint8_t lifetime;
	uint8_t rate;
	uint8_t length;
} __attribute__ ((packed)) EventMetaInfo;

typedef struct EventMetaMsg {
	uint8_t type;
	uint8_t eventType;
	uint8_t subID;
	uint8_t lifetime;
	uint8_t rate;
	uint8_t length;
} EventMetaMsg;

typedef struct {
	uint8_t subID;
	uint8_t refCount;
	//uint16_t start;
	tos_time_t start;
} EventHeader;
typedef struct {
	EventHeader header;
	void * body;
} EventBody;

#endif
