generic configuration VehicleAmSenderC (am_id_t amId) {
  provides {
    interface AMSend;
    interface Packet;
    interface AMPacket;
    interface PacketAcknowledgements as Acks;
  }
} implementation {
  components 
  components SerialActiveMessageC as AM;
  Packet = AM;
  AMPacket = AM;
  Acks = AM;
}
