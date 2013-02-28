configuration SystemEventC {
	provides {
		interface StdControl;
		interface Timer;
		interface SystemEvent;
		interface SystemClock;
	}
} implementation {
	components SystemEventM, EventInstanceC, EventMetaC, TimerC, LedsC;

	StdControl = SystemEventM.StdControl;
	Timer = SystemEventM.Timer;
	SystemEvent = SystemEventM.SystemEvent;
	SystemClock = SystemEventM.SystemClock;

	SystemEventM.EventInstance->EventInstanceC.EventInstance;
	SystemEventM.EventMeta->EventMetaC.EventMeta;
	SystemEventM.ClockTimer->TimerC.Timer[unique("Timer")];
	SystemEventM.Leds->LedsC.Leds;
}
