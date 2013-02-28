includes ArrayList;
includes PEvent;

module EventInstanceM {
	provides {
		interface StdControl;
		interface EventInstance;
	} uses {
		interface EventMeta;
		interface ArrayList;
		interface SystemClock;
	}
} implementation {
	uint8_t space[EVENT_SPACE];
	command result_t StdControl.init() {
		call ArrayList.init(space, EVENT_SPACE);
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}

	// Assume: instance IDs are always in increasing order
	static uint8_t getNewInstanceID(uint8_t subID) {
		uint8_t i, newID=0;
		EventInstanceInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e = (EventInstanceInfo *)call ArrayList.get(i, NULL);
			if (e->subID==subID)
				if (e->instanceID>=newID) {
					newID=e->instanceID;
					newID++;
				}
		}
		return newID;
	}
	command EventInstanceInfo * EventInstance.createEvent(uint8_t subID) {
		EventInstanceInfo e;
		EventMetaInfo * meta =call EventMeta.getEventMeta(subID);
		int idx=0;
		if (meta==NULL) {
			//dbg(DBG_USR2, "EventInstance: Cannot create event with type: %d because it is unknown!\n", subID);
			return NULL;
		}
		e.subID=subID;
		e.instanceID=getNewInstanceID(subID);
		e.sourceID=TOS_LOCAL_ADDRESS;
		e.time=call SystemClock.getTime();

		idx=call ArrayList.size();
		call ArrayList.insert(idx, &e, EVENT_HEADER_LEN);
		call ArrayList.setSize(idx, EVENT_HEADER_LEN+(meta->length)*sizeof(uint16_t));

		return (EventInstanceInfo * )(call ArrayList.get((call ArrayList.size())-1, NULL));
	}
	command EventInstanceInfo * EventInstance.getEventInstanceByHeader(EventInstanceInfo * eventHeader) {
		uint8_t i;
		EventInstanceInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e = (EventInstanceInfo *)call ArrayList.get(i, NULL);
			if (e->subID==eventHeader->subID && e->instanceID==eventHeader->instanceID)
				return e;
		}
		return NULL;
	}
	command EventInstanceInfo * EventInstance.getEventInstance(uint8_t subID, int idx) {
		uint8_t i, total=0;
		EventInstanceInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e = (EventInstanceInfo *)call ArrayList.get(i, NULL);
			if (subID==EVENT_ID_WILDCARD || e->subID==subID)
				if (total==idx)
					return e;
				else
					total++;
		}
		return NULL;
	}
	command int EventInstance.instanceAmount(uint8_t subID) {
		uint8_t i, total=0;
		EventInstanceInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e = (EventInstanceInfo *)call ArrayList.get(i, NULL);
			if (subID==EVENT_ID_WILDCARD || e->subID==subID)
				total++;
		}
		return total;
	}
	command void EventInstance.deleteEvent(uint8_t subID, uint8_t instanceID) {
		int i;
		EventInstanceInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e = (EventInstanceInfo *)call ArrayList.get(i, NULL);
			if (e->subID==subID && e->instanceID==instanceID) {
				//dbg(DBG_USR2, "EventInstance: deleting event at list entry %d\n", i);
				call ArrayList.delete(i);
				break;
			}
		}
		call ArrayList.dbgPrint();
	}
	command int EventInstance.available(uint8_t subID) {
		return call ArrayList.available();
	}
}

