module TrafficLightBasicM {
	provides {
		interface StdControl;
		interface TrafficLightControl;
	} uses {
		interface HPLUART as UART;
	}
} implementation {
	uint8_t UART_receivebuf[RECEIVE_BUFFER_LEN*2];
	uint8_t UART_receivecounter;
	uint8_t UART_sendbuf[SEND_BUFFER_LEN*2];
	uint8_t UART_sendcounter;
	uint8_t trafficInfo[4][2];

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
	task void processTrafficLight() {
		uint8_t id, color, remain_t;
		atomic {
			id=UART_receivebuf[3]>>2;
			color=UART_receivebuf[3] & 0x03;
			remain_t=UART_receivebuf[4];
		}
		if (id>SOUTH || id%4!=0)
			return;
		if (trafficInfo[id/4][0]!=color) {
			signal TrafficLightControl.lightChanged(id, color, remain_t);
		}
		trafficInfo[id/4][0]=color;
		trafficInfo[id/4][1]=remain_t;
	}
	command result_t TrafficLightControl.get (uint8_t id, uint8_t * color, uint8_t * time) {
		*color=trafficInfo[id/4][0];
		*time=trafficInfo[id/4][1];
		return SUCCESS;
	}

	async event result_t UART.get(uint8_t data) {
		if (TOS_LOCAL_ADDRESS==0) {
			return SUCCESS;
		}
		if (data==0xff) {
			UART_receivecounter=0;
		}
		UART_receivebuf[UART_receivecounter++]=data;
		if (UART_receivecounter>=RECEIVE_BUFFER_LEN) {
			post processTrafficLight();
			UART_receivecounter=0;
		}
		return SUCCESS;
	}
	async event result_t UART.putDone() {
		return SUCCESS;
	}
}
