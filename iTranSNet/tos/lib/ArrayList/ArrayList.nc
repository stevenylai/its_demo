interface ArrayList {
	command result_t init(void * space, uint8_t len);
	command result_t insert(int idx, void * entry, uint8_t len);
	command result_t delete(int idx);
	command void * get(int idx, uint8_t * len);
	command result_t setSize(int idx, uint8_t newLen);
	command uint8_t size();
	command uint8_t available();
	command void dbgPrint();
	command int getAbsoluteAddress(void * addr);
	command void * refAbsoluteAddress(int offset);
}
