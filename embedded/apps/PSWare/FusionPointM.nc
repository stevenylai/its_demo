module FusionPointM {
	provides {
		interface StdControl;
		interface FusionPoint;
	}
} implementation {
	bool isFusionPoint;
	command result_t StdControl.init() {
		if (TOS_LOCAL_ADDRESS==0) {
			isFusionPoint=TRUE;
		} else {
			isFusionPoint=FALSE;
		}
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	command bool FusionPoint.isFusionPoint(uint16_t id) {
		return isFusionPoint;
	}
}
