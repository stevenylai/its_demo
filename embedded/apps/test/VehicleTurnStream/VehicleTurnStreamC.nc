//#include <Timer.h>
#include "Vehicle.h"
#include "VehicleTurn.h"

configuration VehicleTurnStreamC {
}
implementation {
  components MainC, VehicleTurnStreamP;
  components new TimerMilliC() as Timer;
  //components NoLedsC as LedsC;
  components LedsC;

  components ActiveMessageC, SerialActiveMessageC;
  components VehicleAmC;
  components new AMReceiverC(AM_VEHICLETURNMSG) as RadioReceive;

  VehicleTurnStreamP.Boot -> MainC;
  VehicleTurnStreamP.Leds -> LedsC;
  VehicleTurnStreamP.Timer -> Timer;

  VehicleTurnStreamP.RadioControl -> ActiveMessageC;
  VehicleTurnStreamP.SerialControl -> VehicleAmC;

  VehicleTurnStreamP.SerialSend -> VehicleAmC.AMSend[AM_BASETOMOTEMSG];
  VehicleTurnStreamP.SerialReceive -> VehicleAmC.Receive[AM_MOTETOBASEMSG];

  VehicleTurnStreamP.RadioReceive -> RadioReceive;

  VehicleTurnStreamP.SerialPacket -> SerialActiveMessageC;
}
