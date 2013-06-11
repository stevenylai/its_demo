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
  components SerialActiveMessageC;
  components new AMSenderC(AM_MOTETOBASEMSG);
  components new AMReceiverC(AM_BASETOMOTEMSG);
  components new SerialAMSenderC(AM_MOTETOVEHICLEMSG);
  components new SerialAMReceiverC(AM_VEHICLETOMOTEMSG);

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
