configuration ActiveMessageAckC {
  provides {
    interface SplitControl;

    interface AMSend[am_id_t id];
    interface Receive[am_id_t id];
    interface Receive as Snoop[am_id_t id];

    interface Packet;
    interface AMPacket;
  } uses {
    interface Boot;
  }
} implementation {
  components ActiveMessageAckP, MsgListC;
  components ActiveMessageC;
  
  SplitControl = ActiveMessageC.SplitControl;
  Snoop = ActiveMessageC.Snoop;
  Packet = ActiveMessageC.Packet;
  AMPacket = ActiveMessageC.AMPacket;

  AMSend = ActiveMessageAckP.AckSend;
  Receive = ActiveMessageAckP.AckReceive;
  Boot = ActiveMessageAckP.Boot;

  ActiveMessageAckP.MsgList -> MsgListC;
  ActiveMessageAckP.RadioPacket -> ActiveMessageC.Packet;
  ActiveMessageAckP.RadioAMPacket -> ActiveMessageC.AMPacket;
  ActiveMessageAckP.RadioSend -> ActiveMessageC.AMSend;
  ActiveMessageAckP.RadioReceive -> ActiveMessageC.Receive;
  
}
