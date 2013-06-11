configuration TestCommAckC {
	provides {
		interface StdControl;
	}
} implementation {
	components TestCommAckM, CommAckC, GenericCommPromiscuous as Comm, TimerC;

	StdControl = TestCommAckM;

	TestCommAckM.Timer->TimerC.Timer[unique("Timer")];
	TestCommAckM.SendMsg->CommAckC.SendMsg[2];
	TestCommAckM.ReceiveMsg->CommAckC.ReceiveMsg[2];

	CommAckC.SendNormal->Comm.SendMsg[1];
	CommAckC.ReceiveNormal->Comm.ReceiveMsg[1];
}
