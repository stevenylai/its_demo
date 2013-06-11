configuration AckByIDC {
	provides {
		interface SendMsg;
		interface ReceiveMsg;
		interface StdControl;
	} uses {
		interface SendMsg as SendNormal;
		interface ReceiveMsg as ReceiveNormal;
	}
} implementation {
	components CommAckC, AckByIDM;

	SendMsg=CommAckC.SendMsg;
	ReceiveMsg=CommAckC.ReceiveMsg;
	StdControl=CommAckC.StdControl;

	SendNormal=CommAckC.SendNormal;
	ReceiveNormal=CommAckC.ReceiveNormal;

	CommAckC.PacketReceiveControl<-AckByIDM.PacketReceiveControl;
}
