#include <Timer.h>
#include "Vehicle.h"
#include "VehicleTurn.h"

configuration VehicleTurnStreamC {
}
implementation {
  components MainC, LedsC, VehicleTurnStreamP;
  components new TimerMilliC() as Timer;

  components ActiveMessageC, SerialActiveMessageC;

  components new SerialAMSenderC(AM_BASETOMOTEMSG) as SerialSend;
  components new SerialAMReceiverC(AM_MOTETOBASEMSG) as SerialReceive;
  components new AMReceiverC(AM_VEHICLETURNMSG) as RadioReceive;

  VehicleTurnStreamP.Boot -> MainC;
  VehicleTurnStreamP.Leds -> LedsC;
  VehicleTurnStreamP.Timer -> Timer;

  VehicleTurnStreamP.RadioControl -> ActiveMessageC;
  VehicleTurnStreamP.SerialControl -> SerialActiveMessageC;

  VehicleTurnStreamP.SerialSend -> SerialSend;
  VehicleTurnStreamP.SerialReceive -> SerialReceive;
  VehicleTurnStreamP.RadioReceive -> RadioReceive;

  VehicleTurnStreamP.SerialPacket -> SerialActiveMessageC;
}
