configuration VehicleDataC {
  provides {
    interface SplitControl;
    interface VehicleData;
  }
} implementation {
  components VehicleDataP, SerialActiveMessageC as Serial, PlatformSerialC;
  components LedsC;

  SplitControl = VehicleDataP;
  SplitControl = Serial;
  VehicleData = VehicleDataP;

  VehicleDataP.UartStream -> PlatformSerialC;
  VehicleDataP.Leds -> LedsC;
}
