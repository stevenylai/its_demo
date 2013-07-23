configuration VehicleAmC {
  provides {
    interface Packet;
    interface AMPacket;

    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  components VehicleAmP, SerialActiveMessageC as Serial, ActiveMessageAddressC, PlatformSerialC;
  components SerialStartC;
  //components LedsC;
  components NoLedsC as LedsC;

  SplitControl = VehicleAmP;
  SplitControl = Serial;
  Receive = VehicleAmP;
  AMSend = VehicleAmP;

  Packet = Serial;
  AMPacket = Serial;

  VehicleAmP.Leds -> LedsC;
  VehicleAmP.UartStream -> PlatformSerialC;
  VehicleAmP.SerialPacket -> Serial;
  VehicleAmP.SerialAMPacket -> Serial;
  VehicleAmP.ActiveMessageAddress -> ActiveMessageAddressC;
}
