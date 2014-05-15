#include "SimpleSend.h"

configuration SimpleSendC {
} implementation {
  components MainC, SimpleSendP, ActiveMessageAckC;
  components new TimerMilliC() as Timer;

  SimpleSendP.Boot -> MainC.Boot;
  SimpleSendP.Timer -> Timer;
  SimpleSendP.AMSend -> ActiveMessageAckC.AMSend[AM_SIMPLE_SEND];
  SimpleSendP.Packet -> ActiveMessageAckC.Packet;
  SimpleSendP.AMPacket -> ActiveMessageAckC.AMPacket;
}
