configuration EventInstanceTestC{
} implementation {
	components
		EventInstanceTestM,
		EventInstanceC, EventMetaC, SystemClockC,
		ArrayListM, MsgBufferM,
		TimerC, GenericComm as Comm, Main;

	Main.StdControl -> EventInstanceTestM;
	Main.StdControl -> EventInstanceC;
	Main.StdControl -> EventMetaC;
	Main.StdControl -> SystemClockC;
	Main.StdControl -> ArrayListM;
	Main.StdControl -> MsgBufferM;
	Main.StdControl -> TimerC;
	Main.StdControl -> Comm;

	EventInstanceC.SystemClock -> SystemClockC.SystemClock;
}
