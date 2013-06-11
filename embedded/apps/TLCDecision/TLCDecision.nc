includes TLCDecision;

interface TLCDecision {
	command result_t nextDecision (uint8_t intersectionId, uint8_t * nextcase, uint8_t * caselength);
}
