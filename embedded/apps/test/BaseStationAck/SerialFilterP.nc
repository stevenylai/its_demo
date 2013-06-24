configuration SerialFilterP {
  provides {
    interface SplitControl;
    interface Receive [am_id_t id];
    interface AMSend [am_id_t id];
    interface Packet;
    interface AMPacket;
  }
} implementation {
  components SerialActiveMessageC as Serial, ActiveMessageAddressC, SerialFilterC;
  SplitControl = Serial;
  AMSend = Serial;
  Receive = SerialFilterC;
  Packet = Serial;
  AMPacket = Serial;

  SerialFilterC.UartReceive -> Serial.Receive;
  SerialFilterC.ActiveMessageAddress -> ActiveMessageAddressC;
}
