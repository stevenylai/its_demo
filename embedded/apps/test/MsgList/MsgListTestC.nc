configuration MsgListTestC {
} implementation {
  components MainC, ActiveMessageC, new TimerMilliC() as Timer;
  components MsgListTestP, MsgListC;
  components LedsC;

  MsgListTestP.Boot -> MainC.Boot;
  MsgListTestP.AMSend -> ActiveMessageC.AMSend[3];
  MsgListTestP.Timer -> Timer;
  MsgListTestP.Leds -> LedsC;
  MsgListTestP.MsgList -> MsgListC;
}
