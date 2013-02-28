configuration TestTrackingLibC {
	provides {
		interface StdControl;
	}
} implementation {
	components TestTrackingLibM, TrackingC;

	StdControl = TestTrackingLibM;
	TestTrackingLibM.Tracking->TrackingC.Tracking;
}
