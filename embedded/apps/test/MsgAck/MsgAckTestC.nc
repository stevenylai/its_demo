configuration MsgAckTestC {
} implementation {
  components MainC, new TimerMilliC() as Timer;
  components MsgAckTestP;
  components new AMSenderC(3);
  components new AMReceiverC(3);
  //components ActiveMessageAckC as ActiveMessageC;
  components ActiveMessageC;

  MsgAckTestP.Boot -> MainC.Boot;
  MsgAckTestP.SplitControl -> ActiveMessageC.SplitControl;

  MsgAckTestP.Timer -> Timer;
  MsgAckTestP.AMSend -> AMSenderC;
  MsgAckTestP.Receive -> AMReceiverC;
  MsgAckTestP.AMPacket -> ActiveMessageC.AMPacket;
  MsgAckTestP.Packet -> ActiveMessageC.Packet;
}
