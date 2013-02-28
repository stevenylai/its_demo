includes iTransMsg;

configuration TrackingC {
	provides {
		interface StdControl;
		interface Tracking;
	}
} implementation {
	components TrackingM, LedsC,
	TimerC,
	GenericCommPromiscuous as Comm;

	StdControl = TrackingM;
	Tracking = TrackingM;

	TrackingM.Leds->LedsC.Leds;
	TrackingM.CommControl->Comm.CommControl;
	TrackingM.Timer->TimerC.Timer[unique("Timer")];
	TrackingM.SendTest->Comm.SendMsg[AM_ITSMSG+9];
	TrackingM.ReceiveRelay->Comm.ReceiveMsg[AM_ITSMSG];
}
