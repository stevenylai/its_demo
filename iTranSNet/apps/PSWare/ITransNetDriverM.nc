/* Minor modification based on the TIMER0 context so that the context will be resumed upon the reception of messages */
includes AM;
includes Mate;
includes MateConstants;

module ITransNetDriverM {
	provides {
		interface StdControl;
		interface SystemEvent;
		interface SystemClock;
	} uses {
		interface EventInstance;
		interface EventMeta;
		interface ReceiveMsg;
		interface CommControl;
		interface Leds;
		#ifndef PLATFORM_PC
		interface MacControl;
		#endif

		interface Timer as ClockTimer;			
		interface MateContextSynch as Synch;
		interface MateAnalysis as Analysis;
		interface MateEngineControl as EngineControl;
		interface MateCapsuleStore as CapsuleStore;
	}
} implementation {
	MateContext clockContext;
	bool capsuleInstalled;

	uint8_t eventType;
	EventInstanceInfo * system;
	uint16_t clock;

	command result_t StdControl.init() {
		result_t rval;
		clockContext.which = MATE_CONTEXT_TIMER0;
		clockContext.state = MATE_STATE_HALT;

		dbg(DBG_USR3, "Registering capsule from ITransNetDriver\n");
		rval = call CapsuleStore.initializeCapsule();
		clockContext.rootCapsule = call CapsuleStore.getCapsule();
		clockContext.currentCapsule = clockContext.rootCapsule;

		{
			int pc = 0;
			
			clockContext.rootCapsule->capsule.code[pc++] = OPhalt;
			clockContext.rootCapsule->capsule.options = 0;
			clockContext.rootCapsule->capsule.version = 0;
			capsuleInstalled=FALSE;
		}

		call Analysis.analyzeCapsuleVars(clockContext.rootCapsule);
		call EngineControl.registerCapsule(clockContext.rootCapsule);
		call Leds.init();

		eventType=0;
		clock=0;
		system=NULL;

		return SUCCESS;
	}

	command result_t StdControl.start() {
		call CommControl.setPromiscuous(TRUE);
		#ifndef PLATFORM_PC
		//call MacControl.enableAck();
		#endif
		return call ClockTimer.start(TIMER_REPEAT, 1024);
	}

	command result_t StdControl.stop() {
		return call ClockTimer.stop();
	}

	static void createSystemEvent () {
		uint8_t i;
		EventMetaInfo * em = call EventMeta.getEventMeta(eventType);
		if (em!=NULL) {
			system = call EventInstance.createEvent(eventType);
			system->content[0]=0;
			system->content[1]=0;
			system->content[2]=0;
			system->content[2]=0;

			dbg(DBG_USR2, "SystemEvent: creating system event (%d, %d) with content:", system->subID, system->instanceID);
			for (i=0; i<em->length; i++) {
				dbg_clear(DBG_USR2, " %d", system->content[i]);
			}
			dbg_clear(DBG_USR2, "\n");
			call Leds.greenOn();
		}
	}

	task void startContextTask() {
		if (clockContext.state == MATE_STATE_HALT && capsuleInstalled) {
			call Leds.yellowToggle();
			call Synch.initializeContext(&clockContext);
			call Synch.resumeContext(&clockContext, &clockContext);
		} else {
			dbg(DBG_USR1, "VM: Timer 0 context not halted. Currently in state %i.\n", clockContext.state);
			// Can log a clock miss error here, but probably
			// not a good idea
		}
	}

	task void ClockEventTask() {
		clock++;
		if (system==NULL) {
			createSystemEvent();
		}

		/************** For Testing **************/
		if (system!=NULL) {
			system->content[0]=TOS_LOCAL_ADDRESS;
			system->content[1]=system->content[3]=0;
			system->content[2]=system->content[2]+1;
		}
		post startContextTask();
		/************** For Testing **************/
	}

	event result_t ClockTimer.fired() {
		dbg(DBG_USR1, "VM: Timer 0 timer fired, posting ClockEventTask.\n");
		post ClockEventTask();
		return SUCCESS;
	}

	event result_t Synch.makeRunnable(MateContext* context) {
		return SUCCESS;
	}

	event void CapsuleStore.capsuleChanged(MateCapsuleBuffer* buf) {
		atomic {
			capsuleInstalled=TRUE;
		}
		clockContext.rootCapsule = buf;
		clockContext.currentCapsule = clockContext.rootCapsule;
		call Synch.initializeContext(&clockContext);
	}
	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr m) {
		uint8_t roadID, posID, carID, status;

		carID = m->data[0];
		roadID = m->data[1];
		posID = m->data[2];
		status = m->data[4];

		if (system!=NULL) {
			system->content[0]=carID;
			system->content[1]=roadID;
			system->content[2]=posID;
			system->content[3]=status;
		}

		post startContextTask();

		return m;
	}
	command bool SystemEvent.isSystemEvent (EventInstanceInfo * e) {
		return system->subID==e->subID && system->instanceID==e->instanceID;
	}
	command uint16_t SystemClock.getTime() {
		return clock;
	}
}
