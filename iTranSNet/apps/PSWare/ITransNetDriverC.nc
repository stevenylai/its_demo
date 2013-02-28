includes Mate;
includes ITS;

configuration ITransNetDriverC {
	provides {
		interface StdControl;
		interface SystemEvent;
		interface SystemClock;
	}
} implementation {
	components ITransNetDriverM, TimerC, GenericCommPromiscuous as Comm, LedsC;
	components MContextSynchProxy as ContextSynch, MateEngine as VM, MCapsuleStoreProxy as Store;
	components EventInstanceC, EventMetaC;
	#ifndef PLATFORM_PC
	components CC2420RadioM;
	#endif

	StdControl = ITransNetDriverM;
	SystemEvent = ITransNetDriverM;
	SystemClock = ITransNetDriverM;
	
	ITransNetDriverM.ClockTimer -> TimerC.Timer[unique("Timer")];
	ITransNetDriverM.Synch -> ContextSynch;
	ITransNetDriverM.EngineControl -> VM.EngineControl[MATE_CAPSULE_TIMER0];
	//ITransNetDriverM <- VM.SubControl;
	ITransNetDriverM.CapsuleStore -> Store.CapsuleStore[MATE_CAPSULE_TIMER0];
	ITransNetDriverM.Analysis -> ContextSynch;

	#ifndef PLATFORM_PC
	ITransNetDriverM.MacControl-> CC2420RadioM;
	#endif

	ITransNetDriverM.EventInstance->EventInstanceC.EventInstance;
	ITransNetDriverM.EventMeta->EventMetaC.EventMeta;
	ITransNetDriverM.ReceiveMsg->Comm.ReceiveMsg[AM_ITSMSG];
	ITransNetDriverM.CommControl->Comm.CommControl;
	ITransNetDriverM.Leds->LedsC.Leds;
}
