module TrafficLightM {
	provides {
		interface StdControl;
		interface TrafficLightControl;
	} uses {
		interface HPLUART as UART;
		interface TLCDecision;
		interface Timer;
		//interface SendMsg as SendTestMsg; 
	}
} implementation {
	TOS_Msg gMsgBuffer;
	TOS_MsgPtr msgBuffer;
	uint8_t UART_receivebuf[RECEIVE_BUFFER_LEN*2];
	uint8_t UART_receivecounter;
	uint8_t UART_sendbuf[SEND_BUFFER_LEN*2];
	uint8_t UART_sendcounter;
	uint8_t trafficInfo[4][2];
	uint8_t caseSeltected;
	uint8_t caseLength;
	uint8_t UARTMlength = 4;
	uint8_t UARTno1;
	uint8_t UARTno2;
	uint8_t UARTMsg[4][4];
		
	task void mapCase2Msg();
	task void conflictGreenLight();

	command result_t StdControl.init() {
		uint8_t i;
		msgBuffer=&gMsgBuffer;
		call UART.init();
		atomic UART_receivecounter=UART_sendcounter=0;
		
		for (i=0;i<UARTMlength;i++){
			UARTMsg[i][0] = 0xff;
			UARTMsg[i][1] = (TOS_LOCAL_ADDRESS<<2)|0x02;  
		}
		
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call Timer.start(TIMER_ONE_SHOT, 100);  
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
		//////////////////////////////for simultaneous green lights////////////////////////////////
			post conflictGreenLight();
		//////////////////////////////for simultaneous green lights////////////////////////////////
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
	
	task void conflictGreenLight() {
		uint8_t i;
		uint8_t checkValue;
		uint8_t checkValue_green;
		uint8_t checkValue_red;
		checkValue_green = 0;
		checkValue_red = 0;
		checkValue = 0;
		
		for (i=0;i<4;i++){
			if (trafficInfo[i][0]==GREEN){
				checkValue_green = checkValue_green +1;
			}
			if (trafficInfo[i][0]==YELLOW){
				checkValue = 1;
				break;
			}
			if (trafficInfo[i][0]==RED){
				checkValue_red = checkValue_red +1;
			}			
		}		
		
		if ((checkValue==1)|| (checkValue_green > 2)||(checkValue_red > 2)){
			UARTno1 = 0;
			UARTno2 = 0;
			call UART.put(UARTMsg[UARTno1][UARTno2]);
 		}
	}
	
	event result_t Timer.fired() {  
		uint8_t i;
		call TLCDecision.nextDecision (TOS_LOCAL_ADDRESS-32, &caseSeltected, &caseLength);			
		
			msgBuffer->data[0]=caseSeltected;
			msgBuffer->data[1]=caseLength;
//			call SendTestMsg.send(0, 2, msgBuffer);
		
		if (caseSeltected == 1) {
			UARTMsg[0][2]=0xc1;
			UARTMsg[1][2]=0xd3;
			UARTMsg[2][2]=0xe1;
			UARTMsg[3][2]=0xf3;
		}
		if (caseSeltected == 2) {
			UARTMsg[0][2]=0xc3;
			UARTMsg[1][2]=0xd1;
			UARTMsg[2][2]=0xe3;
			UARTMsg[3][2]=0xf1;
		}
		for (i=0;i<UARTMlength;i++){
			UARTMsg[i][3] = caseLength;
		}
		UARTno1 = 0;
		UARTno2 = 0;
		call UART.put(UARTMsg[UARTno1][UARTno2]);
		
  	return SUCCESS;
  }   
 
  async event result_t UART.putDone()
  {	
 	
  	UARTno2++;
  	if (UARTno1<4){
  		if (UARTno2<UARTMlength) {
  		call UART.put(UARTMsg[UARTno1][UARTno2]);}
  		else	{
  			if (UARTno1<3){
  				UARTno1++;
  				UARTno2 =0;
  				call UART.put(UARTMsg[UARTno1][UARTno2]);}
  			else {call Timer.start(TIMER_ONE_SHOT, caseLength*1000-200);	}
  		}
  	}
  
   	return SUCCESS;
  }
	/*event result_t SendTestMsg.sendDone(TOS_MsgPtr msg, result_t success) {
		return SUCCESS;
	}*/
}
