#ifndef TLC_DECISION
#define TLC_DECISION
typedef struct RcvMsg {
  uint8_t vid;
  uint8_t rid;
  uint8_t jnc;
  uint8_t dir;
  uint8_t sta;
  uint8_t loc;
  uint16_t seq;
}__attribute__ ((packed)) RcvMsg;


#endif

