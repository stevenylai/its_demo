includes PEvent;

module EventRoutingTestM {
	provides {
		interface StdControl;
	} uses {
		interface Timer;
		interface EventRouting;
		interface EventInstance;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		if (TOS_LOCAL_ADDRESS>0) {
			call Timer.start(TIMER_ONE_SHOT, 1024);
		}
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event result_t Timer.fired() {
		uint8_t * content;
		EventInstanceInfo * e = call EventInstance.createEvent(1);
		if (e==NULL) {
			return call Timer.start(TIMER_ONE_SHOT, 1024);
		}
		content = (uint8_t *)e->content;
		e->sourceID=TOS_LOCAL_ADDRESS;
		content[0]=0;
		content[1]=1;
		content[2]=2;
		call EventRouting.eventForward(e->subID, e->instanceID);
		dbg(DBG_USR2, "Created and fowarded event: %d!\n", e->subID);
		return SUCCESS;
	}
	event result_t EventRouting.eventReceived(uint8_t subID, uint8_t instanceID) {
		return SUCCESS;
	}
	event void EventRouting.routingDone() {
	}
}
