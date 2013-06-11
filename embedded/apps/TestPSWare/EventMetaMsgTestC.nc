includes ArrayList;
includes PEvent;

configuration EventMetaMsgTestC {
} implementation {
	components
		Main,
		GenericCommPromiscuous as Comm,
		LedsC,
		EventMetaMsgTestM;

	Main.StdControl -> Comm;
	Main.StdControl -> EventMetaMsgTestM.StdControl;

	EventMetaMsgTestM.Leds->LedsC.Leds;
	EventMetaMsgTestM.ReceiveMsg->Comm.ReceiveMsg[AM_EVENTMETAMSG];
}
