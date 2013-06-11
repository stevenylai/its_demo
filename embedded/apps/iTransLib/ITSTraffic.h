#ifndef _ITSTRAFFIC_H_
#define _ITSTRAFFIC_H_




enum{
  AM_ITSTRAFFICMSG = 20,
};
typedef struct ITSTrafficMsg {
  uint8_t vid;
  uint8_t rid;
  uint8_t jnc;
  uint8_t dir;
  uint8_t sta;
  uint8_t loc;
  uint16_t seq;
} __attribute__ ((packed)) ITSTrafficMsg;




#endif
