#include <Timer.h>
#include "Vehicle.h"

configuration VehicleBaseAppC {
}
implementation {
  components MainC;
  components LedsC;
  components VehicleBaseC as App;
  components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components SerialActiveMessageC;
  components new AMSenderC(AM_BASETOMOTEMSG);
  components new AMReceiverC(AM_MOTETOBASEMSG);
  components new SerialAMSenderC(AM_MOTETOBASEMSG);
  components new SerialAMReceiverC(AM_BASETOMOTEMSG);

  App.Boot -> MainC;
  App.Leds -> LedsC;
  App.Timer0 -> Timer0;

  App.RadioPacket -> AMSenderC;
  App.RadioAMPacket -> AMSenderC;
  App.RadioAMControl -> ActiveMessageC;
  App.RadioAMSend -> AMSenderC;
  App.RadioReceive -> AMReceiverC;

  App.SerialPacket -> SerialAMSenderC;
  App.SerialAMPacket -> SerialAMSenderC;
  App.SerialAMControl -> SerialActiveMessageC;
  App.SerialAMSend -> SerialAMSenderC;
  App.SerialReceive -> SerialAMReceiverC;
}
