includes PEvent;

interface EventInstance {
	command EventInstanceInfo * createEvent(uint8_t subID);
	command int instanceAmount(uint8_t subID);
	command void deleteEvent(uint8_t subID, uint8_t instanceID);
	command EventInstanceInfo * getEventInstance(uint8_t subID, int idx);
	command EventInstanceInfo * getEventInstanceByHeader(EventInstanceInfo * eventHeader);
	command int available(uint8_t subID);
}
