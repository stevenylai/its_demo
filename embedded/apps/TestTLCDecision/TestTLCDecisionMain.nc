includes TLCDecision;

configuration TestTLCDecisionMain {
} implementation {
	components Main, TLCDecisionC, TestTLCDecisionC;

	Main.StdControl -> TLCDecisionC;
	Main.StdControl -> TestTLCDecisionC;
}
