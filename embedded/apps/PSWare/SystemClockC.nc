configuration SystemClockC {
	provides {
		interface StdControl;
		interface SystemClock;
	}
} implementation {
	components SystemClockM, TimerC;

	StdControl = SystemClockM.StdControl;
	SystemClock = SystemClockM.SystemClock;

	SystemClockM.Timer->TimerC.Timer[unique("Timer")];
}
