#include "VehicleSerial.h"

configuration Uart2RadioC {
} implementation {
  components MainC, Uart2RadioP;
  components NoLedsC as LedsC;
  components new TimerMilliC() as Timer;
  components ActiveMessageAckC as Radio;
  components SerialActiveMessageC as Serial;

  Uart2RadioP.Boot -> MainC.Boot;
  Uart2RadioP.Leds -> LedsC;
  Uart2RadioP.Timer -> Timer;
  Uart2RadioP.RadioControl -> Radio;
  Uart2RadioP.SerialControl -> Serial;

  Uart2RadioP.SerialPacket -> Serial;
  Uart2RadioP.SerialAMPacket -> Serial;
  Uart2RadioP.SerialAMSend -> Serial.AMSend[AM_VEHICLEMSG];

  Uart2RadioP.RadioPacket -> Radio;
  Uart2RadioP.RadioAMPacket -> Radio;
  Uart2RadioP.RadioAMSend -> Radio.AMSend[AM_VEHICLEMSG];
  Uart2RadioP.RadioReceive -> Radio.Receive[AM_VEHICLEMSG];
}
