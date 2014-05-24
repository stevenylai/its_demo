configuration ActiveMessageAckC {
  provides {
    interface SplitControl;

    interface AMSend[am_id_t id];
    interface Receive[am_id_t id];
    //interface Receive as Snoop[am_id_t id];

    interface Packet;
    interface AMPacket;
  }
} implementation {
  components ActiveMessageAckP, MsgListC;
  components ActiveMessageC;
  //components NoLedsC as LedsC;
  components LedsC;
  
  SplitControl = ActiveMessageAckP.SplitControl;
  //Snoop = ActiveMessageC.Snoop;
  Packet = ActiveMessageC.Packet;
  AMPacket = ActiveMessageC.AMPacket;

  AMSend = ActiveMessageAckP.AckSend;
  Receive = ActiveMessageAckP.AckReceive;

  ActiveMessageAckP.Leds -> LedsC;
  ActiveMessageAckP.MsgList -> MsgListC;
  ActiveMessageAckP.RadioControl -> ActiveMessageC.SplitControl;
  ActiveMessageAckP.RadioPacket -> ActiveMessageC.Packet;
  ActiveMessageAckP.RadioAMPacket -> ActiveMessageC.AMPacket;
  ActiveMessageAckP.RadioSend -> ActiveMessageC.AMSend;
  ActiveMessageAckP.RadioReceive -> ActiveMessageC.Receive;
  
}
