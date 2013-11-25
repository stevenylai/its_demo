configuration VehicleDataC {
  provides {
    interface SplitControl;
    interface VehicleData;
  }
} implementation {
  components VehicleDataP, SerialActiveMessageC as Serial, PlatformSerialC;
  components LedsC;
  //components NoLedsC as LedsC;

  SplitControl = VehicleDataP;
  SplitControl = Serial;
  VehicleData = VehicleDataP;

  VehicleDataP.UartStream -> PlatformSerialC;
  VehicleDataP.Leds -> LedsC;
}
