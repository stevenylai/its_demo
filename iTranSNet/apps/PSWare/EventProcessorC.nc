configuration EventProcessorC {
	provides {
		interface StdControl;
		interface MateBytecode as ExceptBytecode;
		interface MateBytecode as CreateBytecode;
		interface MateBytecode as RefBytecode;
		interface MateBytecode as OffsetBytecode;
		interface MateBytecode as SetBytecode;
		interface MateBytecode as GetBytecode;
		interface MateBytecode as EvalBytecode;
		interface MateBytecode as HousekeepBytecode;
	} uses {
		interface SystemClock;
		interface SystemEvent;
	}
} implementation {
	components
		MStacksProxy,
		MContextSynchProxy,
		EventInstanceC,
		EventRoutingC,
		EventMetaC,
		EventMatcherC,
		EventProcessorM;

	StdControl = EventProcessorM.StdControl;
	CreateBytecode = EventProcessorM.CreateBytecode;
	ExceptBytecode = EventProcessorM.ExceptBytecode;
	RefBytecode = EventProcessorM.RefBytecode;
	OffsetBytecode = EventProcessorM.OffsetBytecode;
	SetBytecode = EventProcessorM.SetBytecode;
	GetBytecode = EventProcessorM.GetBytecode;
	EvalBytecode = EventProcessorM.EvalBytecode;
	HousekeepBytecode = EventProcessorM.HousekeepBytecode;

	SystemClock = EventInstanceC.SystemClock;
	SystemClock = EventMatcherC.SystemClock;
	SystemEvent = EventMatcherC.SystemEvent;
	
	EventProcessorM.EventInstance->EventInstanceC.EventInstance;
	EventProcessorM.EventMeta->EventMetaC.EventMeta;
	EventProcessorM.EventMatcher->EventMatcherC.EventMatcher;
	EventProcessorM.Stacks->MStacksProxy.MateStacks;
	EventProcessorM.Synch->MContextSynchProxy.MateContextSynch;

	EventProcessorM.SubControl->EventInstanceC.StdControl;
	EventProcessorM.SubControl->EventRoutingC.StdControl;
	EventProcessorM.SubControl->EventMetaC.StdControl;
	EventProcessorM.SubControl->EventMatcherC.StdControl;
}
