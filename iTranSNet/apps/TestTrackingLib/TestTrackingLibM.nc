module TestTrackingLibM {
	provides {
		interface StdControl;
	} uses {
		interface Tracking;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		/*dbg(DBG_USR2, "%d\n", call Tracking.countAllCarsOnIntersection(1, 1));
		dbg(DBG_USR2, "%d\n", call Tracking.countAllCarsOnIntersection(1, 2));
		dbg(DBG_USR2, "%d\n", call Tracking.countAllCarsOnIntersection(1, 3));
		dbg(DBG_USR2, "%d\n", call Tracking.countAllCarsOnIntersection(1, 4));*/
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event result_t Tracking.carUpdated (Car * currentCar, Car * previousCar) {
		return SUCCESS;
	}
}
