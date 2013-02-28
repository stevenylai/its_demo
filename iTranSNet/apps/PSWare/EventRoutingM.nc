includes PEvent;

module EventRoutingM {
	provides {
		interface StdControl;
		interface EventRouting;
	} uses {
		interface SendMsg;
		interface ReceiveMsg;
		interface EventInstance;
		interface EventMeta;
		interface MsgBuffer;
		interface FusionPoint;
		interface Leds;
		interface StdControl as SubControl;
	}
} implementation {
	typedef struct {
		uint8_t subID;
		uint16_t fusionPointID;
	} EventForwardEntry;
	typedef struct {
		uint16_t fusionPointID;
		uint16_t parent;
	} FusionPointEntry;
	
	EventForwardEntry table_e[TABLE_E_SIZE];
	FusionPointEntry table_r[TABLE_R_SIZE];

	command result_t StdControl.init() {
		table_r[0].fusionPointID=0;
		table_r[0].parent=0;
		table_r[1].fusionPointID=TOS_UART_ADDR;

		if (TOS_LOCAL_ADDRESS!=0)
			table_r[1].parent=0;
		else
			table_r[1].parent=TOS_UART_ADDR;
		return call SubControl.init();
	}
	command result_t StdControl.start() {
		return call SubControl.start();
	}
	command result_t StdControl.stop() {
		return call SubControl.stop();
	}

	static uint16_t getFusionPoint(uint8_t subID) {
		return table_r[0].parent;
	}
	static uint16_t getParent(uint16_t fusionPoint) {
		int i;
		for (i=0; i<TABLE_R_SIZE; i++) {
			if (table_r[i].fusionPointID==fusionPoint) 
				return table_r[i].parent;
		}
		return TOS_BCAST_ADDR;
	}
	command result_t EventRouting.compositeEventDetected (uint8_t eventID1, uint8_t eventID2) {
		// Update table_e
		return SUCCESS;
	}
	static result_t eventSend(uint16_t target, uint8_t subID, uint8_t instanceID) {
		EventInstanceInfo e;
		EventInstanceInfo * e2;
		EventMetaInfo * em;
		TOS_MsgPtr buffer;
		EventInstanceMsg * msg;
		uint8_t len=sizeof(EventInstanceMsg);

		e.subID=subID;
		e.instanceID=instanceID;
		e2 = call EventInstance.getEventInstanceByHeader(&e);
		em = call EventMeta.getEventMeta(subID);
		buffer = call MsgBuffer.getBuffer();
		if (buffer==NULL || em==NULL || e2==NULL)
			return FAIL;

		msg = (EventInstanceMsg *)buffer->data;
		msg->subID=e2->subID;
		msg->sourceID=e2->sourceID;
		msg->totalChunk=1;
		msg->seq=1;

		/*dbg(DBG_USR2, "EventRouting: Copying from event (%d, %d) to message, len: %d\n",
			e2->subID, e2->instanceID, em->length*sizeof(uint16_t));*/
		memcpy(msg->content, e2->content, em->length*sizeof(uint16_t));

		len=EVENT_INSTANCE_MSG_HEADER_LEN+em->length*sizeof(uint16_t);

		if ((call SendMsg.send(target, sizeof(EventInstanceMsg), buffer))==SUCCESS) {
			//call Leds.yellowToggle();
			//dbg(DBG_USR2, "EventRouting: Event sent successfully, len: %d\n", len);
			return SUCCESS;
		} else {
			//dbg(DBG_USR2, "EventRouting: Event sent failed\n");
			call MsgBuffer.returnBuffer(buffer);
			return FAIL;
		}
	}
	command result_t EventRouting.eventForward (uint8_t subID, uint8_t instanceID) {
		return eventSend(getFusionPoint(subID), subID, instanceID);
	}
	command result_t EventRouting.eventDeliver (uint8_t subID, uint8_t instanceID) {
		return eventSend(getParent(TOS_UART_ADDR), subID, instanceID);
	}
	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr m) {
		EventInstanceMsg * msg;
		EventInstanceInfo * e;
		EventMetaInfo * em;

		if (!(call FusionPoint.isFusionPoint(TOS_LOCAL_ADDRESS))) {
			return m;
		} else if (TOS_LOCAL_ADDRESS==0) {
			if ((call MsgBuffer.checkAvailBuffer()) &&
				(call SendMsg.send(TOS_UART_ADDR, sizeof(EventInstanceMsg), m))==SUCCESS) {
				return call MsgBuffer.getBuffer();
			} else {
				return m;
			}
		}

		msg = (EventInstanceMsg *)m->data;
		e = call EventInstance.createEvent(msg->subID);
		em = call EventMeta.getEventMeta(msg->subID);
		if (e!=NULL && em!=NULL) {
			dbg(DBG_USR2, "Event received from %d, subID: %d, instanceID: %d\n", msg->sourceID, msg->subID, e->instanceID);
			e->sourceID=msg->sourceID;
			memcpy(e->content, msg->content, em->length);
			signal EventRouting.eventReceived(e->subID, e->instanceID);
		}

		return m;
	}
	event result_t SendMsg.sendDone (TOS_MsgPtr m, result_t success) {
		call MsgBuffer.returnBuffer(m);
		signal EventRouting.routingDone();
		return SUCCESS;
	}
}
