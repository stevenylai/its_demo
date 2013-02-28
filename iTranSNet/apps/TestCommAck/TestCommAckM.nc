module TestCommAckM {
	provides {
		interface StdControl;
	} uses {
		interface SendMsg;
		interface ReceiveMsg;
		interface Timer;
	}
} implementation {
	TOS_Msg gMsgBuffer;
	command result_t StdControl.init() {
		gMsgBuffer.data[0]=0;
		gMsgBuffer.data[1]=1;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call Timer.start(TIMER_REPEAT, 10240);
		return SUCCESS;
	}
	event result_t Timer.fired() {
		if (TOS_LOCAL_ADDRESS>1) {
			gMsgBuffer.data[0]++;
			gMsgBuffer.data[1]++;
			call SendMsg.send(1, 2, &gMsgBuffer);
		}
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event result_t SendMsg.sendDone(TOS_MsgPtr msg, result_t success) {
		return SUCCESS;
	}
	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr m) {
		dbg(DBG_USR2, "Message received: %d, %d\n", m->data[0], m->data[1]);
		return m;
	}
}
