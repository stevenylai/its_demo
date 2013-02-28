includes TLCDecision;

configuration TLCDecisionC {
	provides {
		interface TLCDecision;
	}
} implementation {
	components TLCDecisionM, TrackingC, TrafficLightC, 
	// HPLUARTC as UartComm, 
	GenericCommPromiscuous as Comm;

	TLCDecision = TLCDecisionM;

	TLCDecisionM.Tracking->TrackingC.Tracking;
	TLCDecisionM.TrafficLightControl->TrafficLightC.TrafficLightControl;
//	TLCDecisionM.UART->UartComm.UART;
}
