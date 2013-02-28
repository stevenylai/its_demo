includes Tracking;

configuration TestTrackingLibMain {
} implementation {
	components Main, TrackingC, TestTrackingLibC;

	Main.StdControl -> TrackingC;
	Main.StdControl -> TestTrackingLibC;
}
