configuration EventMatcherC {
	provides {
		interface StdControl;
		interface EventMatcher;
	} uses {
		interface SystemClock;
		interface SystemEvent;
	}
} implementation {
	components
		EventInstanceC,
		EventMetaC,
		EventRoutingC,
		FusionPointC,
		EventMatcherM;

	StdControl = EventMatcherM.StdControl;
	EventMatcher = EventMatcherM.EventMatcher;
	SystemClock = EventMatcherM.SystemClock;
	SystemEvent = EventMatcherM.SystemEvent;

	EventMatcherM.EventInstance->EventInstanceC.EventInstance;
	//EventMatcherM.ForwardedClock<-EventInstanceC.SystemClock;

	EventMatcherM.EventMeta->EventMetaC.EventMeta;
	EventMatcherM.EventRouting->EventRoutingC.EventRouting;
	EventMatcherM.FusionPoint->FusionPointC.FusionPoint;
}
