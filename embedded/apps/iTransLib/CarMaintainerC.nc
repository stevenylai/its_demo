includes CarCmd;
includes ITSCmd;

configuration CarMaintainerC {
	provides {
		interface StdControl;
		interface CarMaintainer;
	}
}
implementation {
	components SimpleTime, TimerC, TimeUtilC,
		Sounder, LedsC,
		GenericCommPromiscuous as Comm,
		CmdReceiverC, SimpleSensorReaderC, CarParkC,
#ifdef MULTIHOP
  	MultiHopRouter as multihopM, // Routing components
#else
  	SingleHopRouter as multihopM, 
#endif
		CarMaintainerM;

	StdControl = CarMaintainerM.StdControl;
	CarMaintainer = CarMaintainerM;

	CarMaintainerM.Time -> SimpleTime;
  CarMaintainerM.TimeUtil -> TimeUtilC;
  CarMaintainerM.CommControl -> Comm;
  CarMaintainerM.SendMsg -> Comm.SendMsg[AM_CARCMDMSG];
	CarMaintainerM.SendControlMsg -> Comm.SendMsg[AM_SENSORCONTROLMSG];
  CarMaintainerM.ReceiveMsg -> Comm.ReceiveMsg[AM_CARCMDMSG];
  CarMaintainerM.SendTimer -> TimerC.Timer[unique("Timer")];
  CarMaintainerM.CollisionTimer -> TimerC.Timer[unique("Timer")];
  CarMaintainerM.SendToBase -> multihopM.Send[AM_ITSMSG];

	CarMaintainerM.SensorInfo -> CmdReceiverC;
	CarMaintainerM.ReaderControl -> SimpleSensorReaderC;
	CarMaintainerM.CarPark -> CarParkC;
  // Modules used to make sound
  CarMaintainerM.ChirpTimer -> TimerC.Timer[unique("Timer")];
  CarMaintainerM.ChirpControl -> Sounder;
  
  // Modules to make light
  CarMaintainerM.Leds -> LedsC;
}
