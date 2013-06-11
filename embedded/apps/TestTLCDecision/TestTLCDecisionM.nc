module TestTLCDecisionM {
	provides {
		interface StdControl;
	} uses {
		interface TLCDecision;
	}
} implementation {
	uint8_t caseSeltected;
	uint8_t caseLength;
	
	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call TLCDecision.nextDecision (33, &caseSeltected, &caseLength);		
		dbg(DBG_USR1, "Decision Made: %d, %d\n", caseSeltected, caseLength);
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
}
