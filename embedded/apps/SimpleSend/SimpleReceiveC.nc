#include "SimpleSend.h"

configuration SimpleReceiveC {
} implementation {
  components MainC, SimpleReceiveP, ActiveMessageAckC;
  components LedsC;

  SimpleReceiveP.Boot -> MainC.Boot;
  ActiveMessageAckC.Boot -> MainC.Boot;

  SimpleReceiveP.SplitControl -> ActiveMessageAckC.SplitControl;
  SimpleReceiveP.Receive -> ActiveMessageAckC.Receive[AM_SIMPLE_SEND];
  SimpleReceiveP.AMPacket -> ActiveMessageAckC.AMPacket;
  SimpleReceiveP.Leds -> LedsC;
}
