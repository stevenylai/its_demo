configuration MsgListC {
  provides interface MsgList;
} implementation {
  components MsgListP, ActiveMessageC;
  components new TimerMilliC();

  MsgList = MsgListP;
  MsgListP.AMPacket -> ActiveMessageC;
  MsgListP.Timer -> TimerMilliC;
}
