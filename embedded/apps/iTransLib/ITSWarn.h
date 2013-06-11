#ifndef ITS_WARN_H
#define ITS_WARN_H

typedef struct ITSWarnMsg {
	uint8_t vid;
	uint8_t warningNo;
} __attribute__ ((packed)) ITSWarnMsg;


enum {
  AM_ITSWARNMSG = 41,
};

#endif
