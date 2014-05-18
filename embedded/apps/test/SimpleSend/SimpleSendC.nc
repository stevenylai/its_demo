#include "SimpleSend.h"

configuration SimpleSendC {
} implementation {
  components MainC, SimpleSendP;
  //components ActiveMessageC;
  components ActiveMessageAckC as ActiveMessageC;
  components new TimerMilliC() as Timer;
  components LedsC;

  SimpleSendP.Boot -> MainC.Boot;
  ActiveMessageC.Boot -> MainC.Boot;
  SimpleSendP.SplitControl -> ActiveMessageC.SplitControl;

  SimpleSendP.AMSend -> ActiveMessageC.AMSend[AM_SIMPLE_SEND];
  SimpleSendP.Packet -> ActiveMessageC.Packet;
  SimpleSendP.AMPacket -> ActiveMessageC.AMPacket;

  SimpleSendP.Timer -> Timer;
  SimpleSendP.Leds -> LedsC;
}
