configuration EventRoutingC {
	provides {
		interface StdControl;
		interface EventRouting;
	}
} implementation {
	components
		GenericCommPromiscuous as Comm,
		LedsC,
		MsgBufferM,
		FusionPointC,
		EventInstanceC,
		EventMetaC,
		EventRoutingM;

	StdControl = EventRoutingM.StdControl;
	EventRouting = EventRoutingM.EventRouting;

	EventRoutingM.SendMsg->Comm.SendMsg[AM_EVENTINSTANCEMSG];
	EventRoutingM.ReceiveMsg->Comm.ReceiveMsg[AM_EVENTINSTANCEMSG];
	EventRoutingM.MsgBuffer->MsgBufferM.MsgBuffer;
	EventRoutingM.Leds->LedsC.Leds;
	EventRoutingM.EventInstance->EventInstanceC.EventInstance;
	EventRoutingM.EventMeta->EventMetaC.EventMeta;
	EventRoutingM.FusionPoint->FusionPointC.FusionPoint;

	EventRoutingM.SubControl->FusionPointC.StdControl;
}
