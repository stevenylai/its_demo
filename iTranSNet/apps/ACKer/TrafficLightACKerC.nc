configuration TrafficLightACKerC {
	provides {
		interface StdControl;
	}
} implementation {
	components TrafficLightACKerM, CommAckC, GenericCommPromiscuous as Comm;

	StdControl = TrafficLightACKerM;

	TrafficLightACKerM.CommControl->Comm.CommControl;
	CommAckC.SendNormal->Comm.SendMsg[AM_TRAFFIC];
	CommAckC.ReceiveNormal->Comm.ReceiveMsg[AM_TRAFFIC];
}

