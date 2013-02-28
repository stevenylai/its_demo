module EventMetaMsgTestM {
	provides {
		interface StdControl;
	} uses {
		interface ReceiveMsg;
		interface Leds;
	}
} implementation {
	command result_t StdControl.init() {
		return call Leds.init();
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event TOS_MsgPtr ReceiveMsg.receive (TOS_MsgPtr m) {
		call Leds.redToggle();
		return m;
	}
}
