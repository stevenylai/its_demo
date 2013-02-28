#define TIMER_RATE 1000

includes Surge;
includes MultiHop;

module TestM
{
	provides
	{
		interface StdControl;
	}
	uses
	{
		interface Timer;
		interface SendMsg;
		interface ReceiveMsg;
		interface Leds;
		interface Send;
	}
}
implementation {
	TOS_Msg gReportMsg;
	
	task void msgTask();
	static TOS_MsgPtr mForward(TOS_MsgPtr pMsg);
	
	command result_t StdControl.init() {
		return SUCCESS;
	}
	
	command result_t StdControl.start() {
		return call Timer.start(TIMER_REPEAT, TIMER_RATE);
	}
	
	command result_t StdControl.stop() {
		return call Timer.stop();
	}
	
	event result_t Timer.fired() {
		post msgTask();
		
		//dbg(DBG_USR2, "Timer fired.\n");
		return SUCCESS;
	}
	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr pMsg) {
		dbg(DBG_USR2, "Test: Received Message!\n");
		call Leds.greenToggle();
		//gReportMsg=*pMsg;
		pMsg = mForward(pMsg);
		return pMsg;
	}
	event result_t SendMsg.sendDone(TOS_MsgPtr msg, result_t success)
	{
		if (success == SUCCESS)
			call Leds.greenToggle();
		else
			call Leds.yellowToggle();
		return success;
	}
	
	task void msgTask()
	{
		//uint16_t Len;
		//SurgeMsg * smsg = (SurgeMsg *)call Send.getBuffer(&gReportMsg,&Len);
		
		//uint16_t usMHLength = offsetof(TOS_MHopMsg,data) + sizeof (SurgeMsg);
		TOS_MHopMsg * mhmsg = (TOS_MHopMsg *)(gReportMsg.data);
		SurgeMsg * smsg = (SurgeMsg *)(mhmsg->data);
		
		mhmsg -> sourceaddr = 2;
		
		smsg -> sensorID=3;
		smsg -> reading = 4;
		smsg -> operationMode = 5;
		if (TOS_LOCAL_ADDRESS == 1)
		{
			dbg(DBG_USR2, "Test: Timer fired, send message!\n");
			//gReportMsg.length = usMHLength;
			call SendMsg.send(0, offsetof(TOS_MHopMsg,data) + sizeof (SurgeMsg), &gReportMsg);
		}
	}
	static TOS_MsgPtr mForward(TOS_MsgPtr pMsg)
	{
		TOS_MsgPtr	pNewBuf = pMsg;
		TOS_MHopMsg * mhmsg = (TOS_MHopMsg *)(gReportMsg.data);
		TOS_MHopMsg * mhmsg2 = (TOS_MHopMsg *)(pMsg->data);
		*mhmsg=*mhmsg2;
		call SendMsg.send(TOS_UART_ADDR,pMsg->length,&gReportMsg);
		return pNewBuf;
		//call SendMsg.send(TOS_UART_ADDR, offsetof(TOS_MHopMsg,data) + sizeof (SurgeMsg), pMsg);
	}
	event result_t Send.sendDone(TOS_MsgPtr msg, result_t success)
	{
		return success;
	}
}
