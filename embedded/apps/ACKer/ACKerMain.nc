includes TrafficLight;
includes CommAck;

configuration ACKerMain {
} implementation {
	components Main,
	CommAckC,
	VehicleACKerC,
	TrafficLightACKerC,
	TimerC,
	GenericCommPromiscuous as Comm;

	Main.StdControl -> Comm;
	Main.StdControl -> TimerC;
	Main.StdControl -> CommAckC;
	Main.StdControl -> VehicleACKerC;
	Main.StdControl -> TrafficLightACKerC;
}
