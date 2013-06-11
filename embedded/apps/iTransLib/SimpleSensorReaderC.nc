includes ITS;

configuration SimpleSensorReaderC {
	provides interface StdControl;
}
implementation {
  components TimerC, Photo,
#ifdef MULTIHOP
  	MultiHopRouter as multihopM, // Routing components
#else
  	SingleHopRouter as multihopM, 
#endif
		CarMaintainerC, CmdReceiverC,
		SimpleSensorReaderM;

	StdControl = SimpleSensorReaderM;

	SimpleSensorReaderM.Timer -> TimerC.Timer[unique("Timer")];
  SimpleSensorReaderM.ADC -> Photo;
  SimpleSensorReaderM.SendToBase -> multihopM.Send[AM_ITSMSG];

	SimpleSensorReaderM.CarMaintainer -> CarMaintainerC;
	SimpleSensorReaderM.SensorInfo -> CmdReceiverC;
}
