includes PEvent;

interface EventMeta {
	command EventMetaInfo * getEventMeta(uint8_t subID);
	command bool isSubscribed(uint8_t subID);
	command bool isComposite(uint8_t subID);
	command bool isAggregate(uint8_t subID);
}
