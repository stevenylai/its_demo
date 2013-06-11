#define MAX_BUFFER 2
module MsgBufferM {
	provides {
		interface StdControl;
		interface MsgBuffer;
	}
} implementation {
	struct MsgBuffer {
		TOS_Msg space;
		TOS_MsgPtr ptr;
		bool inUse;
	};
	struct MsgBuffer buffer[MAX_BUFFER];
	command result_t StdControl.init() {
		int i;
		for (i=0; i<MAX_BUFFER; i++) {
			buffer[i].inUse=FALSE;
			buffer[i].ptr=&(buffer[i].space);
		}
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	command bool MsgBuffer.checkAvailBuffer() {
		int i;
		for (i=0; i<MAX_BUFFER; i++) {
			if (buffer[i].inUse==FALSE) {
				return TRUE;
			}
		}
		return FALSE;
	}
	command TOS_MsgPtr MsgBuffer.getBuffer() {
		int i;
		for (i=0; i<MAX_BUFFER; i++) {
			if (buffer[i].inUse==FALSE) {
				buffer[i].inUse=TRUE;
				return buffer[i].ptr;
			}
		}
		return NULL;
	}
	command void MsgBuffer.returnBuffer(TOS_MsgPtr avail) {
		int i;
		for (i=0; i<MAX_BUFFER; i++) {
			if (buffer[i].inUse==TRUE) {
				buffer[i].inUse=FALSE;
				buffer[i].ptr=avail;
				break;
			}
		}
	}
}
