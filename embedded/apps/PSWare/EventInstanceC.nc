configuration EventInstanceC {
	provides {
		interface StdControl;
		interface EventInstance;
	} uses {
		interface SystemClock;
	}
} implementation {
	components EventInstanceM,
		EventMetaC,
		ArrayListM;

	StdControl = EventInstanceM.StdControl;
	EventInstance = EventInstanceM.EventInstance;
	SystemClock = EventInstanceM.SystemClock;

	EventInstanceM.EventMeta->EventMetaC.EventMeta;
	EventInstanceM.ArrayList->ArrayListM.ArrayList[ARRAY_LIST_EVENT];
}
