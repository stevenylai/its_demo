configuration TimerContextImpC {
	provides interface StdControl;
}
implementation {
	components SystemEventC, TimerContextImpM, Timer0Context, LedsC;
	StdControl = TimerContextImpM;
	TimerContextImpM.Timer -> SystemEventC;
	TimerContextImpM.Timer -> Timer0Context;
	TimerContextImpM.Leds -> LedsC;
}
