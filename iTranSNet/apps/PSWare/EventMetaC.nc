includes ArrayList;
includes PEvent;

configuration EventMetaC {
	provides {
		interface StdControl;
		interface EventMeta;
	}
} implementation {
	components
		GenericCommPromiscuous as Comm,
		ArrayListM,
		MsgBufferM,
		LedsC,
		EventMetaM;

	StdControl = EventMetaM.StdControl;
	EventMeta = EventMetaM.EventMeta;

	EventMetaM.ArrayList->ArrayListM.ArrayList[ARRAY_LIST_EVENT_META];
	EventMetaM.ReceiveMsg->Comm.ReceiveMsg[AM_EVENTMETAMSG];
	EventMetaM.SendMsg->Comm.SendMsg[AM_EVENTMETAMSG];
	EventMetaM.MsgBuffer->MsgBufferM.MsgBuffer;
	EventMetaM.Leds->LedsC.Leds;
}
