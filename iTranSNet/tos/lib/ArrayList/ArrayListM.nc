includes ArrayList;

module ArrayListM {
	provides {
		interface StdControl;
		interface ArrayList[uint8_t type];
	}
} implementation {
	uint8_t count[ARRAY_LIST_NUM];
	uint8_t currentLength[ARRAY_LIST_NUM];
	uint8_t maxLength[ARRAY_LIST_NUM];
	void * list [ARRAY_LIST_NUM];

	command result_t StdControl.init() {
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}

	command result_t ArrayList.init[uint8_t type](void * space, uint8_t len) {
		list[type]=space;
		maxLength[type]=len;
		currentLength[type]=0;
		count[type]=0;
		return SUCCESS;
	}

	static void * seek (uint8_t type, int idx) {
		uint8_t i, length;
		uint8_t * seekPtr=(uint8_t *)list[type];

		for (i=0; i<idx; i++) {
			length=*seekPtr;
			seekPtr=seekPtr+length+1;
		}
		return (void *)seekPtr;
	}

	static void rshift (uint8_t type, int idx, uint8_t offset) {
		uint8_t * oldPtr, * newPtr, * seekPtr;
		uint8_t length; // total shift amount
		int i;

		oldPtr=(uint8_t *)seek(type, idx);
		newPtr=oldPtr+offset;

		seekPtr=oldPtr;
		length=*seekPtr+1;
		for (i=idx+1; i<count[type]; i++) {
			seekPtr=(uint8_t *)seek(type, i);
			length=length+*seekPtr+1;
		}
		//dbg(DBG_USR2, "ArrayList: shift entry %d for %d (oldPtr %d, newPtr %d, length %d)\n", idx, offset, oldPtr, newPtr, length);
		for (i=length-1; i>=0; i--)
			newPtr[i]=oldPtr[i];
	}

	static void lshift (uint8_t type, int idx, uint8_t offset) {
		uint8_t * oldPtr, * newPtr, * seekPtr;
		uint8_t length; // total shift amount
		int i;

		oldPtr=(uint8_t *)seek(type, idx);
		newPtr=oldPtr-offset;

		seekPtr=oldPtr;
		length=*oldPtr+1;
		for (i=idx+1; i<count[type]; i++) {
			seekPtr=(uint8_t *)seek(type, i);
			length=length+*seekPtr+1;
		}

		for (i=0; i<length; i++)
			newPtr[i]=oldPtr[i];
	}
	command result_t ArrayList.insert[uint8_t type](int idx, void * entry, uint8_t len) {
		uint8_t * pos;

		if (currentLength[type]+len+1>=maxLength[type] || idx>count[type] || idx<0) {
			return FAIL;
		}

		pos=(uint8_t *)seek(type, idx);

		//dbg(DBG_USR2, "ArrayList: inserting at %d/%d\n", idx, count[type]);
		if (idx<count[type]) {
			rshift(type, idx, len+1);
		}
		*pos=len;
		pos++;
		memcpy(pos, entry, len);

		currentLength[type]=currentLength[type]+len+1;
		count[type]++;
		return SUCCESS;
	}
	command result_t ArrayList.setSize[uint8_t type](int idx, uint8_t newLen) {
		uint8_t * pos;

		if (idx>count[type]-1 || idx<0) {
			return FAIL;
		}

		pos=(uint8_t *)seek(type, idx);

		if (currentLength[type]+newLen-(*pos)>=maxLength[type]) {
			return FAIL;
		}

		//dbg(DBG_USR2, "ArrayList: Changing length at %d/%d\n", idx, count[type]);
		if (newLen>(*pos) && idx<count[type]-1) {
			rshift(type, idx+1, newLen-(*pos));
		} else if (newLen<(*pos) && idx<count[type]-1) {
			lshift(type, idx+1, (*pos)-newLen);
		}
		currentLength[type]=currentLength[type]+newLen-(*pos);
		*pos=newLen;

		return SUCCESS;
	}
	command result_t ArrayList.delete[uint8_t type](int idx) {
		uint8_t * pos, len;

		if (idx>count[type]-1 || idx<0)
			return FAIL;

		pos=(uint8_t *)seek(type, idx);
		len=*pos;
		if (idx<count[type]-1) {
			lshift(type, idx+1, len+1);
		}
		currentLength[type]=currentLength[type]-len-1;
		count[type]--;

		return SUCCESS;
	}
	command void * ArrayList.get[uint8_t type](int idx, uint8_t * len) {
		uint8_t * pos;

		if (idx>count[type]-1 || idx<0)
			return NULL;

		pos=(uint8_t *)seek(type, idx);
		if (len!=NULL)
			*len=*pos;
		pos++;
		return pos;
	}
	command uint8_t ArrayList.available[uint8_t type]() {
		return maxLength[type]-currentLength[type];
	}
	command uint8_t ArrayList.size[uint8_t type]() {
		return count[type];
	}
	/*command int ArrayList.search[uint8_t type](void * entry) {
		int i;
		uint8_t * pos;
		for (i=0; i<count[type]; i++) {
			pos=(uint8_t *)seek(type, i);
			if ((signal ArrayList.compare[type](entry, pos))==0)
				return i;
		}
		return -1;
	}*/

	command void * ArrayList.refAbsoluteAddress [uint8_t type] (int offset) {
		uint8_t * start = (uint8_t *)list[type];
		uint8_t * end = start+maxLength[type]-1;

		if (start+offset<end) {
			return (void *)(start+offset);
		} else {
			return NULL;
		}
	}

	command int ArrayList.getAbsoluteAddress [uint8_t type] (void * addr) {
		uint8_t * start = (uint8_t *)list[type];
		uint8_t * end = start+maxLength[type]-1;

		if ((uint8_t *)addr>=start && (uint8_t *)addr<=end) {
			return (uint8_t *)addr-start;
		} else {
			return -1;
		}
	}
	
	command void ArrayList.dbgPrint [uint8_t type] () {
		int i;
		dbg(DBG_USR2, "Array List [%d]: no. of entries: %d, max: %d, used: %d. Contents:\n", type, count[type], maxLength[type], currentLength[type]);
		for (i=0; i<count[type]; i++) {
			uint8_t * ptr = seek(type, i);
			uint8_t len=ptr[0];
			int j;

			dbg_clear(DBG_USR2, "Entry %d (len: %d):", i, len);
			for (j=1; j<len+1; j++) {
				dbg_clear(DBG_USR2, " 0x%hx", ptr[j]);
			}
			dbg_clear(DBG_USR2, "\n");
		}
	}
}
