module VehicleACKerM {
	provides {
		interface StdControl;
	} uses {
		interface MacControl;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call MacControl.enableAck();
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
}
