#define TEST_SIZE 5
includes PEvent;
module ArrayListTestM {
	provides {
		interface StdControl;
	} uses {
		interface ArrayList;
	}
} implementation {
	uint8_t space[100];
	EventInstanceInfo e [TEST_SIZE];
	command result_t StdControl.init() {
		int i;
		call ArrayList.init(space, 100);
		for (i=0; i<TEST_SIZE; i++) {
			e[i].sourceID=TOS_LOCAL_ADDRESS;
			e[i].subID=1;
			e[i].time=i;
			e[i].instanceID=i;
			e[i].content[0]=TOS_LOCAL_ADDRESS;
		}
		return SUCCESS;
	}
	static void testInsert () {
		int i;
		for (i=0; i<TEST_SIZE; i++) {
			call ArrayList.insert(0, &e[i], EVENT_HEADER_LEN+1*sizeof(uint16_t));
		}
	}
	static void testDelete () {
		call ArrayList.delete(1);
	}
	static void testAddressing () {
		uint16_t *data;
		int addr;
		data = call ArrayList.get(1, NULL);

		addr = call ArrayList.getAbsoluteAddress(data);
		dbg(DBG_USR2, "Address %d: %d\n", addr, data[0]);

		data = call ArrayList.refAbsoluteAddress(addr);
		dbg(DBG_USR2, "Address %d: %d\n", addr, data[0]);
	}
	static void printAll () {
		uint16_t *data;
		uint8_t size, i;
		data = call ArrayList.get(1, NULL);
		for (i=0; i<size; i++)
			dbg_clear(DBG_USR2, "%d ", data[i]);
		dbg_clear(DBG_USR2, "\n");
	}
	command result_t StdControl.start() {
		testInsert();
		call ArrayList.dbgPrint();
		//testAddressing();
		//printAll();
		testDelete();
		call ArrayList.dbgPrint();

		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
}
