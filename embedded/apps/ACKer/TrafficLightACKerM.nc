module TrafficLightACKerM {
	provides {
		interface StdControl;
	} uses {
		interface CommControl;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call CommControl.setPromiscuous(TRUE);
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
}

