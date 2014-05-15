#include "SimpleSend.h"

configuration SimpleSendC {
} implementation {
  components MainC, SimpleSendP, ActiveMessageAckC;
  components new TimerMilliC() as Timer;
  components LedsC;

  SimpleSendP.Boot -> MainC.Boot;
  SimpleSendP.SplitControl -> ActiveMessageAckC.SplitControl;
  SimpleSendP.Timer -> Timer;
  SimpleSendP.AMSend -> ActiveMessageAckC.AMSend[AM_SIMPLE_SEND];
  SimpleSendP.Packet -> ActiveMessageAckC.Packet;
  SimpleSendP.AMPacket -> ActiveMessageAckC.AMPacket;
  SimpleSendP.Leds -> LedsC;

  ActiveMessageAckC.Boot -> MainC.Boot;
}
