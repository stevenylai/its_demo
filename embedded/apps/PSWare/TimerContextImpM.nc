module TimerContextImpM {
	provides {
		interface StdControl;
	} uses {
		interface Timer;
		interface Leds;
	}
} implementation {
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		dbg(DBG_USR1, "Starting the timer0 context\n");
		return call Timer.start(TIMER_REPEAT, 1024);
	}
	command result_t StdControl.stop() {
		return call Timer.stop();
	}
	event result_t Timer.fired() {
		//call Leds.redToggle();
		return SUCCESS;
	}
}
