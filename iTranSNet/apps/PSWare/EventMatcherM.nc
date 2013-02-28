includes PEvent;

module EventMatcherM {
	provides {
		interface StdControl;
		interface EventMatcher;
	} uses {
		interface EventInstance;
		interface EventMeta;
		interface EventRouting;
		interface FusionPoint;
		interface SystemClock;
		interface SystemEvent;
	}
} implementation {
	EventInstanceInfo * detectingEvent;
	command result_t StdControl.init() {
		detectingEvent=NULL;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	command void EventMatcher.markForDetection(EventInstanceInfo * marked) {
		detectingEvent=marked;
	}
	static EventInstanceInfo * getLatestInstance (uint8_t subID) {
		int i, total;
		EventInstanceInfo *e=NULL;
		total = call EventInstance.instanceAmount(subID);
		for (i=0; i<total; i++) {
			e=call EventInstance.getEventInstance(subID, i);
		}
		return e;
	}
	command EventInstanceInfo * EventMatcher.findEventInstance(uint8_t subID) {
		if (detectingEvent!=NULL && subID==detectingEvent->subID)
			return detectingEvent;
		else
			// HACK: Just get the latest one ...
			return getLatestInstance(subID);
	}
	command result_t EventMatcher.eventDetected(uint8_t subID, uint8_t instanceID, bool detected) {
		if (detected) {
			if (call EventMeta.isSubscribed(subID)) {
				call EventRouting.eventDeliver (subID, instanceID);
			} else {
				call EventRouting.eventForward (subID, instanceID);
			}
		} else {
			call EventInstance.deleteEvent(subID, instanceID);
		}
		detectingEvent=NULL;


		return SUCCESS;
	}
	command void EventMatcher.eventHousekeep() {
		int i;
		EventInstanceInfo *e;
		EventMetaInfo *em;
		dbg(DBG_USR2, "EventMatcher: housekeeping at time %d ", (call SystemClock.getTime()));
		for (i=(call EventInstance.instanceAmount(EVENT_ID_WILDCARD))-1; i>=0; i--) {
			e=call EventInstance.getEventInstance(EVENT_ID_WILDCARD, i);
			em=call EventMeta.getEventMeta(e->subID);
			if (e==NULL||em==NULL) {
				continue;
			} else if (call SystemEvent.isSystemEvent (e)) {
				continue;
			// Assume: event lifetime will always be less than 255 time units
			} else if ((uint8_t)((call SystemClock.getTime())-e->time)>em->lifetime) {
				if (!(call EventMeta.isAggregate(em->subID))) {
					dbg_clear(DBG_USR2, "Deleting event (%d, %d) ", e->subID, e->instanceID);
					call EventInstance.deleteEvent(e->subID, e->instanceID);
				}
			}
		}
		dbg_clear(DBG_USR2, "\n");
	}
	event void EventRouting.routingDone() {
		return;
	}
	event result_t EventRouting.eventReceived(uint8_t subID, uint8_t instanceID) {
		return SUCCESS;
	}
}
