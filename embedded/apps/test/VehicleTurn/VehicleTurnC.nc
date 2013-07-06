#include "Vehicle.h"
#include "VehicleTurn.h"

configuration VehicleTurnC {
}
implementation {
  components MainC, VehicleTurnP;
  components new TimerMilliC() as Timer;
  //components NoLedsC as LedsC;
  components LedsC;

  components ActiveMessageC, SerialActiveMessageC;
  components VehicleAmC;
  components new AMReceiverC(AM_VEHICLETURNMSG) as RadioReceive;

  VehicleTurnP.Boot -> MainC;
  VehicleTurnP.Leds -> LedsC;
  VehicleTurnP.Timer -> Timer;

  VehicleTurnP.RadioControl -> ActiveMessageC;
  VehicleTurnP.SerialControl -> VehicleAmC;

  VehicleTurnP.SerialSend -> VehicleAmC.AMSend[AM_BASETOMOTEMSG];
  VehicleTurnP.SerialReceive -> VehicleAmC.Receive[AM_MOTETOBASEMSG];
  VehicleTurnP.SerialPacket -> SerialActiveMessageC;

  VehicleTurnP.RadioReceive -> RadioReceive;
}
