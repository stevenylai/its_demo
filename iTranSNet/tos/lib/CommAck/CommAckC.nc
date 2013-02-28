configuration CommAckC {
	provides {
		interface SendMsg[uint8_t id];
		interface ReceiveMsg[uint8_t id];
		interface StdControl;
	}
	uses {
		interface SendMsg as SendNormal;
		interface ReceiveMsg as ReceiveNormal;
	}
} implementation {
	components TimerC, LedsC, CommAckM, GenericCommPromiscuous as Comm;

	StdControl=CommAckM.StdControl;
	SendMsg=CommAckM.SendMsg;
	ReceiveMsg=CommAckM.ReceiveMsg;

	SendNormal=CommAckM.SendNormal;
	ReceiveNormal=CommAckM.ReceiveNormal;

	CommAckM.Timer->TimerC.Timer[unique("Timer")];
	CommAckM.Leds->LedsC.Leds;

	CommAckM.SubControl->TimerC.StdControl;
	CommAckM.CommControl->Comm.CommControl;
}
