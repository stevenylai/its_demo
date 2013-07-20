#include "Vehicle.h"

configuration VehicleStopC {
}
implementation {
  components MainC, VehicleStopP;
  components new TimerMilliC() as Timer;
  //components NoLedsC as LedsC;
  components LedsC;

  components ActiveMessageC, SerialActiveMessageC;
  components VehicleAmC;

  VehicleStopP.Boot -> MainC;
  VehicleStopP.Leds -> LedsC;
  VehicleStopP.Timer -> Timer;

  VehicleStopP.SerialControl -> VehicleAmC;

  VehicleStopP.SerialSend -> VehicleAmC.AMSend[AM_BASETOMOTEMSG];
  VehicleStopP.SerialReceive -> VehicleAmC.Receive[AM_MOTETOBASEMSG];
  VehicleStopP.SerialPacket -> SerialActiveMessageC;
}
