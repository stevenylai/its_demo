includes ArrayList;
includes PEvent;

module EventMetaM {
	provides {
		interface StdControl;
		interface EventMeta;
	} uses {
		interface Leds;
		interface ArrayList;
		interface ReceiveMsg;
		interface SendMsg;
		interface MsgBuffer;
	}
} implementation {
	uint8_t space[META_EVENT_SPACE];
	command result_t StdControl.init() {
		call ArrayList.init(space, META_EVENT_SPACE);
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	static int compare(void * a, void * b) {
		EventMetaInfo * a1, * b1;
		a1=(EventMetaInfo *)a;
		b1=(EventMetaInfo *)b;

		if (a1->subID>b1->subID)
			return -1;
		else if (a1->subID<b1->subID)
			return 1;
		else
			return 0;
	}
	static int search(EventMetaInfo *info) {
		int i;
		EventMetaInfo * e;
		for (i=0; i<(call ArrayList.size()); i++) {
			e=(EventMetaInfo *)call ArrayList.get(i, NULL);
			//dbg(DBG_USR2, "EventMeta: Searching the event meta list (%d): %d\n", i, e->subID);
			if (compare(info, e)==0) {
				//dbg(DBG_USR2, "EventMeta: Found event type at (%d): %d\n", i, e->subID);
				return i;
			}
		}
		return -1;
	}
	static void processMeta(EventMetaMsg * metaMsg) {
		EventMetaInfo info;
		int idx;

		info.subID=metaMsg->subID;
		info.type=metaMsg->eventType;
		info.lifetime=metaMsg->lifetime;
		info.rate=metaMsg->rate;
		info.length=metaMsg->length;

		idx = search (&info);

		if (metaMsg->type==EVENT_META_UPDATE||metaMsg->type==EVENT_META_SUBSCRIBE) {
			if (idx<0) {
				dbg(DBG_USR2, "EventMeta: Created new meta for event type: %d, length: %d\n", info.subID, info.length);
				call ArrayList.insert(0, &info, sizeof(EventMetaInfo));
			} else {
				EventMetaInfo * old=(EventMetaInfo *)(call ArrayList.get(idx, NULL));
				dbg(DBG_USR2, "EventMeta: Updated meta for event type: %d, length: %d\n", info.subID, info.length);
				memcpy(old, &info, sizeof(EventMetaInfo));
			}
		} else if (metaMsg->type==EVENT_META_DELETE) {
			if (idx>=0) {
				call ArrayList.delete(idx);
			}
		}
	}
	command EventMetaInfo * EventMeta.getEventMeta(uint8_t subID) {
		EventMetaInfo info;
		int idx;

		info.subID=subID;

		idx = search (&info);
		if (idx<0) {
			return NULL;
		} else {
			return (EventMetaInfo *)(call ArrayList.get(idx, NULL));
		}
	}
	uint8_t getType(uint8_t allOption, uint8_t idx) {
		uint8_t mask=0xff>>idx;
		return (allOption&mask)>>(8-idx-1);
	}
	command bool EventMeta.isSubscribed(uint8_t subID) {
		EventMetaInfo info;
		EventMetaInfo * e;
		uint8_t type;
		int idx;
		info.subID=subID;
		idx = search (&info);
		if (idx<0) {
			return FALSE;
		} else {
			e = (EventMetaInfo *)(call ArrayList.get(idx, NULL));
			if (e==NULL)
				return FALSE;
			else {
				type=getType(e->type, 0);
				if (type==EVENT_SUBSCRIBED)
					return TRUE;
			}
		}
		return FALSE;
	}
	command bool EventMeta.isComposite(uint8_t subID) {
		EventMetaInfo info;
		EventMetaInfo * e;
		uint8_t type;
		int idx;
		info.subID=subID;
		idx = search (&info);
		if (idx<0) {
			return FALSE;
		} else {
			e = (EventMetaInfo *)(call ArrayList.get(idx, NULL));
			if (e==NULL)
				return FALSE;
			else {
				type=getType(e->type, 1);
				if (type==EVENT_COMPOSITE)
					return TRUE;
			}
		}
		return FALSE;
	}
	command bool EventMeta.isAggregate(uint8_t subID) {
		EventMetaInfo info;
		EventMetaInfo * e;
		uint8_t type;
		int idx;
		info.subID=subID;
		idx = search (&info);
		if (idx<0) {
			return FALSE;
		} else {
			e = (EventMetaInfo *)(call ArrayList.get(idx, NULL));
			if (e==NULL)
				return FALSE;
			else {
				type=getType(e->type, 2);
				if (type==EVENT_AGGREGATE)
					return TRUE;
			}
		}
		return FALSE;
	}
	event TOS_MsgPtr ReceiveMsg.receive (TOS_MsgPtr m) {
		EventMetaMsg * metaMsg=(EventMetaMsg *)m->data;
		dbg(DBG_USR2, "EventMeta: EventMeta message received!\n");
		processMeta(metaMsg);

		// Forwarding - subscription dissemination
		if (TOS_LOCAL_ADDRESS==0) {
			if ((call MsgBuffer.checkAvailBuffer()) &&
				(call SendMsg.send(TOS_BCAST_ADDR, m->length, m))==SUCCESS) {
				return call MsgBuffer.getBuffer();
			} else {
				dbg(DBG_USR2, "EventMeta: Event meta data dissemination failed for event: %d\n", metaMsg->subID);
				return m;
			}
		} else {
			return m;
		}
	}
	event result_t SendMsg.sendDone (TOS_MsgPtr m, result_t success) {
		call MsgBuffer.returnBuffer(m);
		return SUCCESS;
	}
}
