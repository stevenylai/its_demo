module TestCarUARTM {
	provides {
		interface StdControl;
	} uses {
		interface Leds;
		interface ReceiveMsg;
		interface HPLUART as UART;
	}
} implementation {
	uint8_t UART_receivebuf[RECEIVE_BUFFER_LEN*2];
	uint8_t UART_receivecounter;
	uint8_t UART_sendbuf[SEND_BUFFER_LEN*2];
	uint8_t UART_sendcounter;
	uint8_t UART_sendtotal;

	command result_t StdControl.init() {
		call UART.init();
		atomic UART_receivecounter=UART_sendcounter=0;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		call UART.stop();
		return SUCCESS;
	}
	task void sendUART () {
		uint8_t idx;
		atomic idx=UART_sendcounter;
		call UART.put(UART_sendbuf[idx]);
	}

	task void processUARTData() {
		uint8_t feedback;
		atomic {
			// Feedback is used to test the communication between node and the car
			feedback=UART_receivebuf[0];
		}

		/************* Put UART *************/
		if (feedback==FEEDBACK_BYTE) {
			atomic {
				UART_sendbuf[0] = 0xff;
				UART_sendbuf[1] = FEEDBACK_BYTE;
				UART_sendcounter = 0;
				UART_sendtotal = 2;
			}
			call Leds.greenToggle();
			post sendUART();
		}

		// Reset counter
		atomic {
			UART_receivecounter=0;
		}
	}

	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr m) {
		uint8_t i;
		atomic {
			UART_sendbuf[0] = 0xff;
			for (i=0; i<m->length && i<SEND_BUFFER_LEN; i++) {
				UART_sendbuf[i+1]=m->data[i];
			}
			UART_sendcounter = 0;
			UART_sendtotal = i+1;
		}
		post sendUART();
		return m;
	}

	async event result_t UART.get(uint8_t data) {
		if (TOS_LOCAL_ADDRESS==0) {
			return SUCCESS;
		}

		// 0xff: start of the actual data
		if (data==0xff) {
			if (UART_receivecounter>0)
				post processUARTData();
		} else {
			UART_receivebuf[UART_receivecounter++]=data;
		}

		// Buffer overflowing handling?
		if (UART_receivecounter>=RECEIVE_BUFFER_LEN) {
			post processUARTData();
			UART_receivecounter=0;
		}
		return SUCCESS;
	}

	async event result_t UART.putDone() {
		atomic {
			UART_sendcounter++;
			if (UART_sendcounter<UART_sendtotal) {
				post sendUART();
			}
		}
		return SUCCESS;
	}
}

