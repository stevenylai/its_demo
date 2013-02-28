includes Surge;
includes MultiHop;

configuration Test {
}
implementation {
	components Main, TimerC, TestM, GenericCommPromiscuous as Comm, OneHopSend, LedsC;
	
	Main.StdControl -> TimerC;
	Main.StdControl -> TestM;
	Main.StdControl -> Comm;
	Main.StdControl -> OneHopSend;
  
	TestM.Timer -> TimerC.Timer[unique("Timer")];
	TestM.Leds -> LedsC;
	TestM.Send -> OneHopSend.Send[AM_MULTIHOPMSG];
	TestM.SendMsg -> Comm.SendMsg[AM_SURGEMSG];
	TestM.ReceiveMsg -> Comm.ReceiveMsg[AM_SURGEMSG];
	OneHopSend.ReceiveMsg[AM_MULTIHOPMSG] -> Comm.ReceiveMsg[AM_MULTIHOPMSG];
}
