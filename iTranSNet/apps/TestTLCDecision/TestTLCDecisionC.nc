configuration TestTLCDecisionC {
	provides {
		interface StdControl;
	}
} implementation {
	components TestTLCDecisionM, TLCDecisionC;

	StdControl = TestTLCDecisionM;
	TestTLCDecisionM.TLCDecision->TLCDecisionC.TLCDecision;
}
