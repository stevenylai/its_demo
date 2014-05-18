#include "SimpleSend.h"

configuration SimpleReceiveC {
} implementation {
  components MainC, SimpleReceiveP;
  //components ActiveMessageC;
  components ActiveMessageAckC as ActiveMessageC;
  components LedsC;

  SimpleReceiveP.Boot -> MainC.Boot;
  ActiveMessageC.Boot -> MainC.Boot;
  SimpleReceiveP.SplitControl -> ActiveMessageC.SplitControl;

  SimpleReceiveP.Receive -> ActiveMessageC.Receive[AM_SIMPLE_SEND];
  SimpleReceiveP.AMPacket -> ActiveMessageC.AMPacket;
  SimpleReceiveP.Leds -> LedsC;
}
