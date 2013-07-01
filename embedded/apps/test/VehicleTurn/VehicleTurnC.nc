#include <Timer.h>
#include "Vehicle.h"
#include "VehicleTurn.h"

configuration VehicleTurnC {
}
implementation {
  components MainC, LedsC, VehicleTurnP;
  components new TimerMilliC() as Timer;

  components ActiveMessageC, SerialActiveMessageC;

  components new SerialAMSenderC(AM_BASETOMOTEMSG) as SerialSend;
  components new SerialAMReceiverC(AM_MOTETOBASEMSG) as SerialReceive;
  components new AMReceiverC(AM_VEHICLETURNMSG) as RadioReceive;

  VehicleTurnP.Boot -> MainC;
  VehicleTurnP.Leds -> LedsC;
  VehicleTurnP.Timer -> Timer;

  VehicleTurnP.RadioControl -> ActiveMessageC;
  VehicleTurnP.SerialControl -> SerialActiveMessageC;

  VehicleTurnP.SerialSend -> SerialSend;
  VehicleTurnP.SerialReceive -> SerialReceive;
  VehicleTurnP.RadioReceive -> RadioReceive;

  VehicleTurnP.SerialPacket -> SerialActiveMessageC;
}
