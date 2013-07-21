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

  VehicleStopP.SerialSend -> VehicleAmC.AMSend[AM_VEHICLEMSG];
  VehicleStopP.SerialReceive -> VehicleAmC.Receive[AM_VEHICLEMSG];
  VehicleStopP.SerialPacket -> SerialActiveMessageC;
}
