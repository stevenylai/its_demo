module ITransNetDriverTestM {
	provides {
		interface StdControl;
	} uses {
		interface SendMsg;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event result_t SendMsg.sendDone (TOS_MsgPtr m, result_t success) {
		return SUCCESS;
	}
}
