includes PEvent;

module SystemClockM {
	provides {
		interface StdControl;
		interface SystemClock;
	} uses {
		interface Timer;
	}
} implementation {
	uint16_t clock;

	command result_t StdControl.init() {
		clock=0;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call Timer.start(TIMER_REPEAT, 1024);
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		call Timer.stop();
		return SUCCESS;
	}
	event result_t Timer.fired() {
		clock++;
		return SUCCESS;
	}
	command uint16_t SystemClock.getTime() {
		return clock;
	}
}

