configuration SerialFilterC {
  provides {
    interface SplitControl;
    interface Receive [am_id_t id];
    interface AMSend [am_id_t id];
    interface Packet;
    interface AMPacket;
  }
} implementation {
  components SerialActiveMessageC as Serial, ActiveMessageAddressC, SerialFilterP;
  SplitControl = Serial;
  AMSend = Serial;
  Receive = SerialFilterP;
  Packet = Serial;
  AMPacket = Serial;

  SerialFilterP.UartReceive -> Serial.Receive;
  SerialFilterP.AMPacket -> Serial.AMPacket;
  SerialFilterP.ActiveMessageAddress -> ActiveMessageAddressC;
}
