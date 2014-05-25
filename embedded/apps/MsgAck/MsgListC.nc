configuration MsgListC {
  provides interface MsgList;
} implementation {
  components MsgListP, ActiveMessageC;
  components new TimerMilliC();
  //components LedsC;
  components NoLedsC as LedsC;

  MsgList = MsgListP;
  MsgListP.AMPacket -> ActiveMessageC;
  MsgListP.Timer -> TimerMilliC;
  MsgListP.Leds -> LedsC;
}
