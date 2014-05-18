configuration MsgListC {
  provides interface MsgList;
} implementation {
  components MsgListP, ActiveMessageC;
  components new TimerMilliC(), LedsC;

  MsgList = MsgListP;
  MsgListP.AMPacket -> ActiveMessageC;
  MsgListP.Timer -> TimerMilliC;
  MsgListP.Leds -> LedsC;
}
