configuration CmdReceiverC {
	provides {
		interface StdControl;
		interface SensorInfo;
	}
}
implementation {
	components SimpleTime, TimeUtilC,
		LedsC,
		GenericCommPromiscuous as Comm, Bcast,
		SimpleSensorReaderC,
		CmdReceiverM;

	StdControl = CmdReceiverM.StdControl;
	SensorInfo = CmdReceiverM;

	CmdReceiverM.Leds -> LedsC;
	CmdReceiverM.TimeSet -> SimpleTime;
	CmdReceiverM.TimeUtil -> TimeUtilC;

	CmdReceiverM.ReaderControl -> SimpleSensorReaderC;
	// Routing protocol of flooding
  CmdReceiverM.CmdReceive -> Bcast.Receive[AM_ITSCMDMSG];
  Bcast.ReceiveMsg[AM_ITSCMDMSG] -> Comm.ReceiveMsg[AM_ITSCMDMSG];

	CmdReceiverM.SubControl -> Bcast;
}
