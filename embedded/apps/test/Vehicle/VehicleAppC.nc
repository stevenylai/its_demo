#include <Timer.h>
#include "Vehicle.h"

configuration VehicleAppC {
}
implementation {
  components MainC;
  components LedsC;
  components VehicleC as App;
  components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components new AMSenderC(AM_MOTETOBASEMSG);
  components new AMReceiverC(AM_BASETOMOTEMSG);

  App.Boot -> MainC;
  App.Leds -> LedsC;
  App.Timer0 -> Timer0;
  App.RadioSplitControl -> ActiveMessageC;

  App.RadioAckowledgement -> AMSenderC;
  App.RadioPacket -> AMSenderC;
  App.RadioSend -> AMSenderC;
  App.RadioReceive -> AMReceiverC;
}
