includes Tracking;
includes TrafficLight;
includes CommAck;

configuration TrafficLightMain {
} implementation {
	components Main, TrackingC, LightInformC, TrafficLightC,
	CommAckC,
	TimerC,
	GenericCommPromiscuous as Comm;

	Main.StdControl -> TrackingC;
	Main.StdControl -> TimerC;
	Main.StdControl -> LightInformC;
	Main.StdControl -> Comm;
	Main.StdControl -> CommAckC;
	Main.StdControl -> TrafficLightC;
}
