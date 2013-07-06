configuration VehicleAmC {
  provides {
    interface SplitControl;
    interface Receive [am_id_t id];
    interface AMSend [am_id_t id];
    interface Packet;
    interface AMPacket;
  }
} implementation {
  components SerialActiveMessageC as Serial, ActiveMessageAddressC, VehicleAmP;
  //components LedsC;
  components NoLedsC as LedsC;
  SplitControl = Serial;
  AMSend = Serial;
  Packet = Serial;
  AMPacket = Serial;
  Receive = VehicleAmP;

  VehicleAmP.Leds -> LedsC;
  VehicleAmP.UartReceive -> Serial.Receive;
  VehicleAmP.AMPacket -> Serial.AMPacket;
  VehicleAmP.ActiveMessageAddress -> ActiveMessageAddressC;
}
