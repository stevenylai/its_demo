includes ITS;
includes ITSCmd;
includes CarCmd;
//#define MULTIHOP
includes MultiHop;

configuration ITS {
}
implementation {
  components 
  	Main, TimerC, SimpleTime, Photo,
  	// FYP related modules
  	CmdReceiverC, CarMaintainerC, CarParkC,
#ifdef MULTIHOP
  	MultiHopRouter as multihopM, // Routing components
#else
  	SingleHopRouter as multihopM, 
#endif
#ifndef PLATFORM_PC
		DelugeC,
#endif
    GenericCommPromiscuous as Comm;

#ifndef PLATFORM_PC
  Main.StdControl -> DelugeC;
#endif
  Main.StdControl -> CmdReceiverC.StdControl;
  Main.StdControl -> Comm;
  //multihopM.CommControl -> Comm;

	// Routing to base station components
	Main.StdControl -> multihopM.StdControl;
	multihopM.ReceiveMsg[AM_ITSMSG] -> Comm.ReceiveMsg[AM_ITSMSG];
	//Main.StdControl -> QueuedSend.StdControl; // Is it necessary?
  
  Main.StdControl -> Photo;
  Main.StdControl -> SimpleTime;
  Main.StdControl -> TimerC;
  Main.StdControl -> CarMaintainerC;
  Main.StdControl -> CarParkC;
}
