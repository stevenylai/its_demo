#include "SimpleTransceive.h"

configuration SimpleTransceiveC {
} implementation {
  components MainC, SimpleTransceiveP;
  //components ActiveMessageC;
  components ActiveMessageAckC as ActiveMessageC;
  components new TimerMilliC() as Timer;
  //components LedsC;
  components NoLedsC as LedsC;

  SimpleTransceiveP.Boot -> MainC.Boot;
  SimpleTransceiveP.SplitControl -> ActiveMessageC.SplitControl;

  SimpleTransceiveP.AMSend -> ActiveMessageC.AMSend[AM_SIMPLE_TRANSCEIVE];
  SimpleTransceiveP.Receive -> ActiveMessageC.Receive[AM_SIMPLE_TRANSCEIVE];
  SimpleTransceiveP.Packet -> ActiveMessageC.Packet;
  SimpleTransceiveP.AMPacket -> ActiveMessageC.AMPacket;

  SimpleTransceiveP.Timer -> Timer;
  SimpleTransceiveP.Leds -> LedsC;
}
