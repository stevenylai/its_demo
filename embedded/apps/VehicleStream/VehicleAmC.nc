configuration VehicleAmC {
  provides {
    interface Packet;
    interface AMPacket;

    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  components VehicleAmP, ActiveMessageAddressC, SerialActiveMessageC as Serial;
  components SerialStartC;
  components VehicleDataC;
  components LedsC;
  //components NoLedsC as LedsC;

  SplitControl = VehicleAmP;
  SplitControl = VehicleDataC;
  SplitControl = Serial;
  Receive = VehicleAmP;
  AMSend = VehicleAmP;

  Packet = Serial;
  AMPacket = Serial;

  VehicleAmP.Leds -> LedsC;
  VehicleAmP.SerialPacket -> Serial;
  VehicleAmP.SerialAMPacket -> Serial;
  VehicleAmP.ActiveMessageAddress -> ActiveMessageAddressC;
  VehicleAmP.VehicleData -> VehicleDataC;
}
