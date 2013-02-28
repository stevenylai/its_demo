configuration LightInformC {
	provides {
		interface StdControl;
	}
} implementation {
	components LightInformM, TrafficLightC, TrackingC, 
		LedsC,
		CommAckC,
		GenericCommPromiscuous as Comm;

	StdControl = LightInformM;

	LightInformM.Tracking->TrackingC.Tracking;
	LightInformM.Leds->LedsC.Leds;

	LightInformM.SendTraffic->CommAckC.SendMsg[AM_TRAFFIC];
	CommAckC.SendNormal->Comm.SendMsg[AM_TRAFFIC];
	CommAckC.ReceiveNormal->Comm.ReceiveMsg[AM_TRAFFIC];

	LightInformM.TrafficLightControl->TrafficLightC.TrafficLightControl;
}
