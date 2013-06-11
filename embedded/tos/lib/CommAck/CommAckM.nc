includes CommAck;

module CommAckM {
	provides {
		interface SendMsg[uint8_t id];
		interface ReceiveMsg[uint8_t id];
		//interface PacketReceiveControl[uint8_t id];
		interface StdControl;
	}
	uses {
		interface SendMsg as SendNormal;
		interface ReceiveMsg as ReceiveNormal;
		interface CommControl;
		interface Timer;
		interface Leds;
		interface StdControl as SubControl;
	}
} implementation {
	uint8_t state;
	TOS_Msg sendBuffer;
	TOS_Msg receiveBuffer;
	TOS_MsgPtr sendBufferPtr;
	TOS_MsgPtr receiveBufferPtr;
	int8_t retrial;

	PendingMsg pending;

	command result_t StdControl.init() {
		state=IDLE;
		receiveBufferPtr=&receiveBuffer;
		sendBufferPtr=&sendBuffer;
		retrial=0;
		
		return call SubControl.init();
	}
	command result_t StdControl.start() {
		if (TOS_LOCAL_ADDRESS==0) {
			call CommControl.setPromiscuous(TRUE);
		}
		return call SubControl.start();
	}
	command result_t StdControl.stop() {
		call Timer.stop();
		return call SubControl.stop();
	}
	void dbgPacket(TOS_MsgPtr data) {
		uint8_t i;

		for(i = 0; i < sizeof(TOS_Msg); i++) {
			dbg_clear(DBG_USR2, "%02hhx ", ((uint8_t *)data)[i]);
		}
		dbg(DBG_USR2, "\n");
	}
	void static initSendBuffer() {
		MsgACK * pWriting = (MsgACK *)(&(sendBufferPtr->data[pending.length-TOSH_HEADER_ACK_LENGTH]));
		pWriting->am_type=pending.am_type;
		pWriting->type=MSG_SEND;
		pWriting->source=TOS_LOCAL_ADDRESS;
		memcpy(sendBufferPtr->data, pending.msg->data, pending.length-TOSH_HEADER_ACK_LENGTH);
	}
	command result_t SendMsg.send[uint8_t id](uint16_t address, uint8_t length, TOS_MsgPtr msg) {
		if (state!=IDLE||length>TOSH_DATA_ACK_LENGTH) {
			dbg(DBG_USR2, "Message sent failure, state: %d, length: %d\n", state, length);
			return FAIL;
		} else {
			pending.am_type=id;
			pending.msg=msg;
			pending.address=address;
			pending.length=length+TOSH_HEADER_ACK_LENGTH;

			initSendBuffer();

			state=SEND;
			call Timer.start(TIMER_ONE_SHOT, TIMEOUT);
		}
		call SendNormal.send(pending.address, pending.length, &sendBuffer);
		retrial=0;
		dbg(DBG_USR2, "Sending packet with am: %d to: %d, packet: ", pending.am_type, pending.address); dbgPacket(pending.msg);
		return SUCCESS;
	}

	event result_t Timer.fired() {
		if (state==SEND) {
			if (MAX_RETRIAL==0 || retrial<MAX_RETRIAL) {
				dbg(DBG_USR2, "Timeout! Resending (am: %d)...\n", pending.am_type);
				call Leds.redToggle();
				initSendBuffer();
				call SendNormal.send(pending.address, pending.length, &sendBuffer);
				retrial++;
				return call Timer.start(TIMER_ONE_SHOT, TIMEOUT);
			} else {
				dbg(DBG_USR2, "Send done (am: %d): FAIL!\n", pending.am_type);
				state=IDLE;
				return signal SendMsg.sendDone[pending.am_type](pending.msg, FAIL);
			}
		} else
			return SUCCESS;
	}

	static void extractMsg (TOS_MsgPtr m) {
		//MsgACK * pReading = (MsgACK *)m->data;
		uint8_t real_length;

		real_length=m->length-TOSH_HEADER_ACK_LENGTH;
		/*if (real_length>0) {
			memcpy(receiveBufferPtr->data, m->data, real_length);
			memcpy(m->data, receiveBufferPtr->data, real_length);
		}*/
		m->length=real_length;
	}
	event TOS_MsgPtr ReceiveNormal.receive(TOS_MsgPtr m) {
		MsgACK * pReading, * pWriting;
		uint16_t sender;
		uint8_t type, am_type;

		extractMsg(m);
		pReading = (MsgACK *)(&(m->data[m->length]));
		sender=pReading->source;
		type=pReading->type;
		am_type=pReading->am_type;

		// Expecting an ACK
		if (state==SEND && type==MSG_ACK) {
			if (m->addr==TOS_LOCAL_ADDRESS) {
				state=IDLE;
				dbg(DBG_USR2, "ACK received from %d. Send done (am: %d): SUCCESS!\n", sender, pending.am_type);
				signal SendMsg.sendDone[pending.am_type](pending.msg, SUCCESS);
			}
		} else if (state==IDLE && type==MSG_SEND) {
			// Can be avoided by buffer swapping?
			memcpy(receiveBufferPtr, m, sizeof(TOS_Msg));
			pending.msg=receiveBufferPtr;
			pending.am_type=am_type;
			state=RECEIVE;
			pWriting=(MsgACK *)(sendBufferPtr->data);
			pWriting->am_type=am_type;
			pWriting->type=MSG_ACK;
			pWriting->source=TOS_LOCAL_ADDRESS;
			dbg(DBG_USR2, "DATA received from: %d, am: %d\n", sender, am_type);

			// Only one node sends ACK
			if (TOS_LOCAL_ADDRESS==0 &&
				(call SendNormal.send(sender, TOSH_HEADER_ACK_LENGTH, &sendBuffer))==SUCCESS) {
				// Don't set IDLE till sendDone
				//dbg(DBG_USR2, "Sending ACK to %d\n", sender);
			} else {
				state=IDLE;
				return signal ReceiveMsg.receive[pending.am_type](pending.msg);
			}
		}
		return m;
	}
	event result_t SendNormal.sendDone(TOS_MsgPtr msg, result_t success) {
		if (state==RECEIVE) {
			state=IDLE;
			receiveBufferPtr=signal ReceiveMsg.receive[pending.am_type](pending.msg);
		}
		return SUCCESS;
	}
	default event TOS_MsgPtr ReceiveMsg.receive[uint8_t id](TOS_MsgPtr m) {
		return m;
	}
	default event result_t SendMsg.sendDone[uint8_t id](TOS_MsgPtr msg, result_t success) {
		return SUCCESS;
	}
}
