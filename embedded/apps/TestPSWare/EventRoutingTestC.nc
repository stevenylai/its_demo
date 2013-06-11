configuration EventRoutingTestC{
} implementation {
	components
		GenericComm as Comm,
		TimerC,
		MsgBufferM,
		ArrayListM,
		FusionPointC,
		EventInstanceC,
		EventRoutingC,
		EventMetaC,
		SystemEventC,
		EventRoutingTestM,
		Main;

	Main.StdControl -> ArrayListM.StdControl;
	Main.StdControl -> MsgBufferM.StdControl;
	Main.StdControl -> FusionPointC.StdControl;
	Main.StdControl -> EventInstanceC.StdControl;
	Main.StdControl -> EventMetaC.StdControl;
	Main.StdControl -> EventRoutingTestM.StdControl;
	Main.StdControl -> SystemEventC.StdControl;
	Main.StdControl -> Comm;
	Main.StdControl -> TimerC;

	EventInstanceC.SystemClock -> SystemEventC.SystemClock;
	EventRoutingTestM.EventInstance -> EventInstanceC.EventInstance;
	EventRoutingTestM.EventRouting -> EventRoutingC.EventRouting;
	EventRoutingTestM.Timer -> TimerC.Timer[unique("Timer")];
}

