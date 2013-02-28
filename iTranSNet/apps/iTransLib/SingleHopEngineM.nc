includes MultiHop;

#ifndef MHOP_QUEUE_SIZE
#define MHOP_QUEUE_SIZE	16
#endif

module SingleHopEngineM {
	provides
	{
		interface Send[uint8_t id];
		interface StdControl;
		interface Intercept[uint8_t id];
		interface Intercept as Snoop[uint8_t id];
		interface RouteControl;
	}
	uses
	{
		interface SendMsg[uint8_t id];
		interface ReceiveMsg[uint8_t id];
		
		interface Leds;

		interface StdControl as SubControl;
		interface RouteControl as RouteSelectCntl;
		interface RouteSelect;
		
		interface CommControl;
		interface StdControl as CommStdControl;
	}
}
implementation
{
	enum {
		FWD_QUEUE_SIZE = MHOP_QUEUE_SIZE, // Forwarding Queue
		EMPTY = 0xff
	};
	
	/* Internal storage and scheduling state */
	TOS_Msg FwdBuffers[FWD_QUEUE_SIZE];
	TOS_Msg *FwdBufList[FWD_QUEUE_SIZE];
	
	uint8_t iFwdBufHead, iFwdBufTail;
	
	int timer_rate, timer_ticks;
	TOS_Msg gReportMsg;
	
	static void initialize() {
		int n;
		
		for (n=0; n < FWD_QUEUE_SIZE; n++) {
			FwdBufList[n] = &FwdBuffers[n];
		} 
		
		iFwdBufHead = iFwdBufTail = 0;
	}
  
	command result_t StdControl.init() {
		initialize();
		call CommStdControl.init();
		return call SubControl.init();
	}
	
	command result_t StdControl.start() {
		call CommStdControl.start();
		call SubControl.start();
		return call CommControl.setPromiscuous(TRUE);
	}
	
	command result_t StdControl.stop() {
		call SubControl.stop();
		// XXX message doesn't get received if we stop then start radio
		return call CommStdControl.stop();
	}
  
	command result_t Send.send[uint8_t id](TOS_MsgPtr pMsg, uint16_t PayloadLen)
	{
		uint16_t usMHLength = offsetof(TOS_MHopMsg,data) + PayloadLen;
		
		if (usMHLength > TOSH_DATA_LENGTH) {
			call Leds.yellowToggle();
			return FAIL;
		}
		
		call RouteSelect.initializeFields(pMsg,id);
		
		if (call RouteSelect.selectRoute(pMsg,id) != SUCCESS) {
			call Leds.yellowToggle();
			return FAIL;
		}
		
		if (call SendMsg.send[id](pMsg->addr, usMHLength, pMsg) != SUCCESS) {
			dbg(DBG_ROUTE, "Send failed!\n");
			call Leds.yellowToggle();
			return FAIL;
		}
		
		dbg(DBG_ROUTE, "Send succeeded!\n");
		call Leds.greenToggle();
		return SUCCESS;
	}
	
	command void *Send.getBuffer[uint8_t id](TOS_MsgPtr pMsg, uint16_t* length)
	{
		TOS_MHopMsg *pMHMsg = (TOS_MHopMsg *)pMsg->data;
		
		*length = TOSH_DATA_LENGTH - offsetof(TOS_MHopMsg,data);
		
		return (&pMHMsg->data[0]);
	}

	static TOS_MsgPtr mForward(TOS_MsgPtr pMsg, uint8_t id) {
		TOS_MsgPtr	pNewBuf = pMsg;
		
		if (((iFwdBufHead + 1) % FWD_QUEUE_SIZE) == iFwdBufTail) // Queue full
			return pNewBuf;
		
		if ((call RouteSelect.selectRoute(pMsg,id)) != SUCCESS)
			return pNewBuf;
		
		// Failures at the send level do not cause the seq. number space to be 
		// rolled back properly.  This is somewhat broken.
		if (call SendMsg.send[id](pMsg->addr,pMsg->length,pMsg) == SUCCESS) {
			pNewBuf = FwdBufList[iFwdBufHead];
			FwdBufList[iFwdBufHead] = pMsg;
			iFwdBufHead++; iFwdBufHead %= FWD_QUEUE_SIZE;
		}
		
		return pNewBuf;
	}
	event TOS_MsgPtr ReceiveMsg.receive[uint8_t id](TOS_MsgPtr pMsg) {
		TOS_MHopMsg		*pMHMsg = (TOS_MHopMsg *)pMsg->data;
		uint16_t		PayloadLen = pMsg->length - offsetof(TOS_MHopMsg,data);
		
		// Ordinary message requiring forwarding
		if (pMsg->addr == TOS_LOCAL_ADDRESS) { // Addressed to local node
			if ((signal Intercept.intercept[id](pMsg,&pMHMsg->data[0],PayloadLen)) == SUCCESS) {
				pMsg = mForward(pMsg,id);
			}
		}
		else {
			// Snoop the packet for permiscuous applications
			signal Snoop.intercept[id](pMsg,&pMHMsg->data[0],PayloadLen);
		}
		
		return pMsg;
	}
	event result_t SendMsg.sendDone[uint8_t id](TOS_MsgPtr pMsg, bool success) {
		if (pMsg == FwdBufList[iFwdBufTail]) { // Msg was from forwarding queue
			iFwdBufTail++; iFwdBufTail %= FWD_QUEUE_SIZE;
		} else {
			signal Send.sendDone[id](pMsg, success);
		} 
		return SUCCESS;
	}
	
	command uint16_t RouteControl.getParent() {
		return call RouteSelectCntl.getParent();
	}
	
	command uint8_t RouteControl.getQuality() {
		return call RouteSelectCntl.getQuality();
	}
	
	command uint8_t RouteControl.getDepth() {
		return call RouteSelectCntl.getDepth();
	}
	
	command uint8_t RouteControl.getOccupancy() {
		uint16_t uiOutstanding = (uint16_t)iFwdBufTail - (uint16_t)iFwdBufHead;
		uiOutstanding %= FWD_QUEUE_SIZE;
		return (uint8_t)uiOutstanding;
	}
	
	command uint16_t RouteControl.getSender(TOS_MsgPtr msg) {
		TOS_MHopMsg	 *pMHMsg = (TOS_MHopMsg *)msg->data;
		return pMHMsg->sourceaddr;
	}
	
	command result_t RouteControl.setUpdateInterval(uint16_t Interval) {
		return call RouteSelectCntl.setUpdateInterval(Interval);
	}
	
	command result_t RouteControl.manualUpdate() {
		return call RouteSelectCntl.manualUpdate();
	}
	
	default event result_t Send.sendDone[uint8_t id](TOS_MsgPtr pMsg, result_t success) {
		dbg(DBG_ROUTE, "Send done!\n");
		return SUCCESS;
	}
	
	default event result_t Intercept.intercept[uint8_t id](TOS_MsgPtr pMsg, void* payload, 
			uint16_t payloadLen) {
		return SUCCESS;
	}
	
	default event result_t Snoop.intercept[uint8_t id](TOS_MsgPtr pMsg, void* payload, 
			uint16_t payloadLen) {
		return SUCCESS;
	}
}
