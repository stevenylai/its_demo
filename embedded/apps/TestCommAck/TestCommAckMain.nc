includes CommAck;

configuration TestCommAckMain {
} implementation {
	components Main, CommAckC, TestCommAckC, GenericCommPromiscuous as Comm, TimerC;

	Main.StdControl -> CommAckC;
	Main.StdControl -> TestCommAckC;
	Main.StdControl -> Comm;
	Main.StdControl -> TimerC;
}
