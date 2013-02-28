includes PEvent;

interface EventMatcher {
	command void markForDetection(EventInstanceInfo * marked);
	command EventInstanceInfo * findEventInstance(uint8_t subID);
	command result_t eventDetected(uint8_t subID, uint8_t instanceID, bool detectionResult);
	command void eventHousekeep();
}
