configuration TrafficLightDataC {
  provides {
    interface SplitControl;
    interface TrafficLightData;
  }
} implementation {
  components TrafficLightDataP, SerialActiveMessageC as Serial, PlatformSerialC;
  components new TimerMilliC();
  components LedsC;
  //components NoLedsC as LedsC;

  SplitControl = TrafficLightDataP;
  SplitControl = Serial;
  TrafficLightData = TrafficLightDataP;

  TrafficLightDataP.UartStream -> PlatformSerialC;
  TrafficLightDataP.Leds -> LedsC;
  TrafficLightDataP.Timer -> TimerMilliC;
}
