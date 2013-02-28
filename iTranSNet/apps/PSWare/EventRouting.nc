interface EventRouting {
	command result_t eventForward (uint8_t subID, uint8_t instanceID);
	command result_t eventDeliver (uint8_t subID, uint8_t instanceID);
	command result_t compositeEventDetected (uint8_t subID1, uint8_t subID2);
	event result_t eventReceived(uint8_t subID, uint8_t instanceID);
	event void routingDone();
}
