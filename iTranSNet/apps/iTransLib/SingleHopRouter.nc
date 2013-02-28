includes MultiHop;

configuration SingleHopRouter
{
	provides
	{
		interface Send[uint8_t id];
    interface Intercept[uint8_t id];
    interface Intercept as Snoop[uint8_t id];
		interface StdControl;
    interface RouteControl;
	}
	uses
	{
		interface ReceiveMsg[uint8_t id];
	}
}
implementation {
	components
		SingleHopEngineM, SingleHopLEPSM, GenericCommPromiscuous as Comm, QueuedSend, LedsC;

	Send = SingleHopEngineM;
	Intercept = SingleHopEngineM.Intercept;
	Snoop = SingleHopEngineM.Snoop;
	
	RouteControl = SingleHopEngineM;
	StdControl = SingleHopEngineM;
	
	ReceiveMsg = SingleHopEngineM;
	
	SingleHopEngineM.SendMsg -> QueuedSend.SendMsg;
	SingleHopEngineM.CommStdControl -> Comm;
	SingleHopEngineM.CommControl -> Comm;
	
	SingleHopEngineM.Leds -> LedsC;
	
	SingleHopEngineM.SubControl -> SingleHopLEPSM.StdControl;
	SingleHopEngineM.SubControl -> QueuedSend.StdControl;
	SingleHopEngineM.RouteSelectCntl -> SingleHopLEPSM.RouteControl;
	SingleHopEngineM.RouteSelect -> SingleHopLEPSM.RouteSelect;
}
/* Seems that the 'SingleHopRouter' package won't work with Deluge
if the name is not chosen properly.
Previously, I used names: OneHopSend, OneHopSendM and OneHopLEPSM
and when compiled with Deluge, the base station cannot inject any packet.
A lot of 'write errors' were popped up.
Guess I need to get familiar with NesC compiler.*/

/* Program flow of the MultiHopRouter:
Sender:
Timer.fired()
TimerTask() {
	updateTable
	{ for (all entries in routing table)
		updateEst()
		{ use formula to calculate 'receiveEst' according to the number of messages received and missed and reset 'missed', 'received'}
	}
	chooseParent;
	SendRouteTask()
	{ broadcast the best 'receiveEst'}
}

Receiver:
ReceiveMsg.receive()
{
	updateNbrCounters(sender's address, seqno, &iNbr)
	{ Mainly update the table for:
		missed, received, lastSeqno}
	(Some Operations on RoutePacket):
	{ Mainly update the table for that addr:
		parent, hop,
	 Update the table for est between this node and that address:
		sendEst, liveliness;}
}*/
