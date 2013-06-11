includes AM;
includes MultiHop;

module SingleHopLEPSM {
	
	provides {
		interface StdControl;
		interface RouteSelect;
		interface RouteControl;
	}
}
implementation {
  int16_t gCurrentSeqNo;
  
	command result_t StdControl.init() {
		gCurrentSeqNo=0;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	command bool RouteSelect.isActive() {
		return TRUE;
	}
	command result_t RouteSelect.initializeFields(TOS_MsgPtr Msg, uint8_t id) {
		TOS_MHopMsg *pMHMsg = (TOS_MHopMsg *)&Msg->data[0];
		
		pMHMsg->sourceaddr = pMHMsg->originaddr = TOS_LOCAL_ADDRESS;
		pMHMsg->hopcount = 1;
		
		return SUCCESS;
	}
	command result_t RouteSelect.selectRoute(TOS_MsgPtr Msg, uint8_t id) {
		TOS_MHopMsg *pMHMsg = (TOS_MHopMsg *)&Msg->data[0];

		pMHMsg->sourceaddr = TOS_LOCAL_ADDRESS;
		pMHMsg->hopcount = 1;
		pMHMsg->seqno = gCurrentSeqNo++;
		if (TOS_LOCAL_ADDRESS!=0) {
			Msg->addr = 0;
		} else {
			Msg->addr=TOS_UART_ADDR;
		}
    
		return SUCCESS;
  }
	command uint8_t* RouteSelect.getBuffer(TOS_MsgPtr Msg, uint16_t* Len) {
	}
	command uint16_t RouteControl.getParent() {
		if (TOS_LOCAL_ADDRESS!=0)
			return 0;
		else
			return TOS_UART_ADDR;
	}
	
	command uint8_t RouteControl.getQuality() {
		return 0;
	}
	
	command uint8_t RouteControl.getDepth() {
		if (TOS_LOCAL_ADDRESS!=0)
			return 1;
		else
			return 0;
	}
	
	command uint8_t RouteControl.getOccupancy() {
		return 0;
	}
	
	command uint16_t RouteControl.getSender(TOS_MsgPtr msg) {
		TOS_MHopMsg		*pMHMsg = (TOS_MHopMsg *)msg->data;
		return pMHMsg->sourceaddr;
	}
	
	command result_t RouteControl.setUpdateInterval(uint16_t Interval) {
		return SUCCESS;
	}
	
	command result_t RouteControl.manualUpdate() {
		return SUCCESS;
	}
}
