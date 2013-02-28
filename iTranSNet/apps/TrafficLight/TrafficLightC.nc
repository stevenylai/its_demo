configuration TrafficLightC {
	provides {
		interface StdControl;
		interface TrafficLightControl;
	}
} implementation {
	components	HPLUARTC as UartComm,
		//GenericCommPromiscuous as Comm,
		TLCDecisionC,
		TimerC,
		TrafficLightM;
		//TrafficLightBasicM as TrafficLightM;

	StdControl=TrafficLightM.StdControl;
	TrafficLightControl=TrafficLightM.TrafficLightControl;
	TrafficLightM.UART->UartComm.UART;
	TrafficLightM.TLCDecision->TLCDecisionC.TLCDecision;
	TrafficLightM.Timer->TimerC.Timer[unique("Timer")];
	//TrafficLightM.SendTestMsg->Comm.SendMsg[AM_TEST];
}
