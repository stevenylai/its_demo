includes PEvent;

module SystemEventM {
	provides {
		interface StdControl;
		interface Timer;
		interface SystemEvent;
		interface SystemClock;
	} uses {
		interface Timer as ClockTimer;
		interface EventInstance;
		interface EventMeta;
		interface Leds;
	}
} implementation {
	uint8_t eventType;
	EventInstanceInfo * system;
	uint16_t clock;

	static void createSystemEvent () {
		uint8_t i;
		EventMetaInfo * em = call EventMeta.getEventMeta(eventType);
		if (em!=NULL) {
			system = call EventInstance.createEvent(eventType);
			system->content[0]=1;
			system->content[1]=2;
			system->content[2]=3;

			dbg(DBG_USR2, "SystemEvent: creating system event (%d, %d) with content:", system->subID, system->instanceID);
			for (i=0; i<em->length; i++) {
				dbg_clear(DBG_USR2, " %d", system->content[i]);
			}
			dbg_clear(DBG_USR2, "\n");
			call Leds.greenOn();
		}
	}
	command result_t StdControl.init() {
		eventType=0;
		clock=0;
		system=NULL;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	task void ClockEventTask() {
		clock++;
		if (system==NULL) {
			createSystemEvent();
			return;
		}
		// update the (non-static) attributes (light, sound, etc)
	}
	command bool SystemEvent.isSystemEvent (EventInstanceInfo * e) {
		return system->subID==e->subID && system->instanceID==e->instanceID;
	}
	event result_t ClockTimer.fired() {
		post ClockEventTask();
		return signal Timer.fired();
	}
	command uint16_t SystemClock.getTime() {
		return clock;
	}
	command result_t Timer.start(char type, uint32_t interval) {
		return call ClockTimer.start(type, interval);
	}
	command result_t Timer.stop() {
		return call ClockTimer.stop();
	}
}
