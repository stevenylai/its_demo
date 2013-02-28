configuration VehicleACKerC {
	provides {
		interface StdControl;
	}
} implementation {
	components CC2420RadioM,
	//CommAckC, GenericCommPromiscuous as Comm,
	VehicleACKerM;

	StdControl = VehicleACKerM;

	VehicleACKerM.MacControl-> CC2420RadioM;
	/*CommAckC.SendNormal->Comm.SendMsg[44];
	CommAckC.ReceiveNormal->Comm.ReceiveMsg[44];*/
}
