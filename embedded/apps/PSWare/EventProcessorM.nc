includes PEvent;

module EventProcessorM {
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
		interface MateStacks as Stacks;
		interface EventInstance;
		interface EventMeta;
		interface EventMatcher;
		interface StdControl as SubControl;
		interface MateContextSynch as Synch;
	}
} implementation {
	uint16_t exceptionHandler;

	command result_t StdControl.init() {
		exceptionHandler=0;
		return call SubControl.init();
	}
	command result_t StdControl.start() {
		return call SubControl.start();
	}
	command result_t StdControl.stop() {
		return call SubControl.stop();
	}

	static void handleException(uint8_t instr, MateContext* context) {
		// Jump to the exception handler
		if (exceptionHandler!=0) {
			dbg(DBG_USR2, "EventOp: Jumping to exception handler at: %d\n", exceptionHandler);
			call Stacks.pushValue(context, 0);
			context->pc = exceptionHandler;
		} else {
			dbg(DBG_USR2, "EventOp:  No exception handler created yet, halting context.\n");
			call Stacks.resetStacks(context);
			call Synch.haltContext(context);
		}
	}
	command result_t ExceptBytecode.execute(uint8_t instr, MateContext* context) {
		uint16_t arg1 = instr&0x03;
		uint16_t arg2 = context->currentCapsule->capsule.code[context->pc++];
		uint16_t real_arg=arg1<<2|arg2;
		exceptionHandler = real_arg;
		dbg(DBG_USR2, "EventOp(except):  creating exception handler at: %d\n", exceptionHandler);
		return SUCCESS;
	}
	/* 	-----------STACK TOP-------------

		-----------offset----------------

		-----------subID,instanceID------

		-----------STACK BOTTOM----------
	*/
	static void pushEventID (MateContext* context, uint8_t subID, uint8_t instanceID) {
		uint16_t convertedSubID=((uint16_t)subID)<<8;
		uint16_t convertedInstanceID=(uint16_t)instanceID;
		call Stacks.pushValue(context, convertedSubID|convertedInstanceID);
	}
	static void popEventID (MateContext* context, uint8_t * subID, uint8_t * instanceID) {
		uint16_t combined=(call Stacks.popOperand(context))->value.var;
		*subID=(uint8_t)(combined>>8);
		*instanceID=(uint8_t)(combined&0x00ff);
	}
	command result_t CreateBytecode.execute(uint8_t instr, MateContext* context) {
		EventInstanceInfo * e;
		uint8_t subID = (uint8_t)(context->currentCapsule->capsule.code[context->pc++]);
		e = call EventInstance.createEvent(subID);
		if (e==NULL) {
			dbg(DBG_USR2, "EventOp(create):  error, list full or unknown event type %d\n", subID);
			handleException(instr, context);
		} else {
			dbg(DBG_USR2, "EventOp(create):  creating event with type %d and instance %d, total event instances: %d\n", e->subID, e->instanceID, (call EventInstance.instanceAmount(EVENT_ID_WILDCARD)));
			pushEventID(context, e->subID, e->instanceID);
			call EventMatcher.markForDetection(e);
		}
		return SUCCESS;
	}
	command result_t RefBytecode.execute(uint8_t instr, MateContext* context) {
		EventInstanceInfo * e;
		uint8_t subID = (uint8_t)(context->currentCapsule->capsule.code[context->pc++]);
		e = call EventMatcher.findEventInstance(subID);
		if (e==NULL) {
			dbg(DBG_USR2, "EventOp(ref):  error, unknown event type %d\n", subID);
			handleException(instr, context);
		} else {
			dbg(DBG_USR2, "EventOp(ref):  referencing event with type %d and instance %d\n", e->subID, e->instanceID);
			pushEventID(context, e->subID, e->instanceID);
		}
		return SUCCESS;
	}
	command result_t OffsetBytecode.execute(uint8_t instr, MateContext* context) {
		uint8_t offset = (uint8_t)(context->currentCapsule->capsule.code[context->pc++]);
		dbg(DBG_USR2, "EventOp(offset):  offset %d\n", offset);
		call Stacks.pushValue(context, offset);
		return SUCCESS;
	}
	command result_t SetBytecode.execute(uint8_t instr, MateContext* context) {
		EventMetaInfo *em;
		EventInstanceInfo e, * e2;
		uint8_t offset, instanceID, subID;
		uint16_t arg;
		offset = (uint8_t)(call Stacks.popOperand(context))->value.var;
		popEventID(context, &subID, &instanceID);
		arg = (call Stacks.popOperand(context))->value.var;
		e.subID=subID;
		e.instanceID=instanceID;
		e2 = call EventInstance.getEventInstanceByHeader(&e);
		em = call EventMeta.getEventMeta(subID);

		if (e2==NULL||em==NULL||offset>=em->length) {
			dbg(DBG_USR2, "EventOp(set):  error in set event %d\n", subID);
			handleException(instr, context);
		} else {
			e2->content[offset]=arg;
			dbg(DBG_USR2, "EventOp(set): set event e(%d, %d)[%d] to %d\n", subID, instanceID, offset, arg);
		}
			
		return SUCCESS;
	}
	command result_t GetBytecode.execute(uint8_t instr, MateContext* context) {
		EventMetaInfo *em;
		EventInstanceInfo e, * e2;
		uint8_t offset, instanceID, subID;
		uint16_t arg;
		offset = (uint8_t)(call Stacks.popOperand(context))->value.var;
		popEventID(context, &subID, &instanceID);
		e.subID=subID;
		e.instanceID=instanceID;
		e2 = call EventInstance.getEventInstanceByHeader(&e);
		em = call EventMeta.getEventMeta(subID);

		if (e2==NULL||em==NULL||offset>=em->length) {
			dbg(DBG_USR2, "EventOp(get):  error in get %d\n", subID);
			handleException(instr, context);
		} else {
			arg=e2->content[offset];
			dbg(DBG_USR2, "EventOp(get): get event e(%d, %d)[%d]=%d\n", subID, instanceID, offset, arg);
			call Stacks.pushValue(context, arg);
		}
		return SUCCESS;
	}
	command result_t EvalBytecode.execute(uint8_t instr, MateContext* context) {
		uint16_t arg1 = instr&0x03;
		uint16_t arg2 = context->currentCapsule->capsule.code[context->pc++];
		uint16_t real_arg=arg1<<2|arg2;

		uint8_t instanceID, subID;
		uint16_t arg;
		arg = (call Stacks.popOperand(context))->value.var;
		popEventID(context, &subID, &instanceID);
		if (arg!=0) {
			dbg(DBG_USR2, "EventOp(eval): event (%d, %d) detected\n", subID, instanceID);
			call EventMatcher.eventDetected(subID, instanceID, TRUE);
		} else {
			call EventMatcher.eventDetected(subID, instanceID, FALSE);
		}
		call Stacks.resetStacks(context);
		return SUCCESS;
	}
	command result_t HousekeepBytecode.execute(uint8_t instr, MateContext* context) {
		call EventMatcher.eventHousekeep();
		context->state = MATE_STATE_HALT;
		context->pc = 0;
		call Synch.haltContext(context);
		return SUCCESS;
	}
	event result_t Synch.makeRunnable(MateContext* context){
		return SUCCESS;
	}
	command uint8_t ExceptBytecode.byteLength() {return 1;}
	command uint8_t CreateBytecode.byteLength() {return 1;}
	command uint8_t RefBytecode.byteLength() {return 1;}
	command uint8_t OffsetBytecode.byteLength() {return 1;}
	command uint8_t SetBytecode.byteLength() {return 1;}
	command uint8_t GetBytecode.byteLength() {return 1;}
	command uint8_t EvalBytecode.byteLength() {return 1;}
	command uint8_t HousekeepBytecode.byteLength() {return 1;}
}
