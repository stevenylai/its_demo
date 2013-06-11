configuration PSWareTestC{
} implementation {
	components
		EventInstanceC, EventMetaC,
		SystemClockC as PSWareDriver,
		//ITransNetDriverC as PSWareDriver,
		ArrayListM, MsgBufferM,
		TimerC, GenericComm as Comm, Main;

	//Main.StdControl -> VM;
	Main.StdControl -> PSWareDriver;
	Main.StdControl -> EventInstanceC;
	Main.StdControl -> EventMetaC;
	Main.StdControl -> ArrayListM;
	Main.StdControl -> MsgBufferM;
	Main.StdControl -> TimerC;
	Main.StdControl -> Comm;

	EventInstanceC.SystemClock -> PSWareDriver;
}
