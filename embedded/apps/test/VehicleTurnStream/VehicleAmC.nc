configuration VehicleAmC {
  provides {
    interface Packet;
    interface AMPacket;

    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  components VehicleAmP, SerialActiveMessageC as Serial;
  components PlatformSerialC;
  components SerialStartC;

  SplitControl = VehicleAmP;
  SplitControl = Serial;
  Receive = VehicleAmP;
  AMSend = VehicleAmP;

  Packet = Serial;
  AMPacket = Serial;

  VehicleAmP.UartStream -> PlatformSerialC;
  VehicleAmP.SerialPacket -> Serial;
}
