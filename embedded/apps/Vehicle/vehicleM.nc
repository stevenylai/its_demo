includes Definition;
includes AM;

#define CLISSIONSTATUS_NULL			0
#define CLISSIONSTATUS_FREE			1
#define CLISSIONSTATUS_CLISSION		2
#define CLISSIONSTATUS_WAITING		3

#define TURNLEFT                    1
#define FORWARD                     0

#define GIVENSPEED                  25
#define TIME_OUT_VALUE              5

#define MAX_BUFFER_SZ                 50
#define MESSAGE_LENGTH              8
#define INVALID_JUNCTION 0xff
#define INVALID_ROAD  0xff

//#define TEST_VEHICLE

#ifdef TEST_VEHICLE
	#define TIME_UNIT_VALUE             1000 // 1250
#else
	#define TIME_UNIT_VALUE             1200 // 1250
#endif
module vehicleM
{
  provides interface StdControl;
  uses
  {
    interface Leds;
	
    interface StdControl as CommControl;
    
    interface ReceiveMsg as ReceiveTrafficMsg;
    interface ReceiveMsg as ReceiveTestMsg;
    interface SendMsg as SendResultMsg;

	interface SendMsg as SendWarnMsg;
	interface SendMsg as SendStasMsg;
	interface ReceiveMsg as ReceiveStasMsg;
    
    interface HPLUART as UART;
    
    interface Timer;
    interface Timer as mtimer;
	interface MacControl;
  }
}

implementation
{
	uint8_t UART_spointer;
	uint8_t UART_sendbuf[4];
	uint8_t UART_snumber;

	uint8_t UART_receivebuf[5];
	uint8_t UART_receivecounter;

	uint8_t currentIC;
	uint8_t currentdir;
	uint8_t currentspeed;

	uint8_t gSpeedPending;	
	uint8_t allroadstatusbuff[MAX_BUFFER_SZ][6];
	uint8_t allroadstatuspointer;
	
	uint8_t selfroadnumber, selfroadjunction, selfdirection, selflocation, selfstatus;
	uint8_t selfseq;
		
	uint8_t sendnumber;
	uint32_t mtimercnt;
	uint32_t mtimeoutpt;
	
	int32_t mcrosstimercnt;
	int32_t mcrosstimeout;
	uint8_t mhornstatus;
	
	uint8_t mWarning;
	ITSStatisticsMsg mStaTbl;	
	TOS_Msg  Msgdata;
	TOS_Msg  gVehStatsMsg;
	TOS_Msg  gVehWarnMsg;

	uint8_t gPktSending;
	uint8_t mSeqNo;
	uint8_t signal_stopped;
	uint8_t elapseallcollisions();
///////////////////////////////////////////////////////////////////
  void carcontrol(unsigned char speed)
  {
  	 //call Leds.yellowToggle();
  	 UART_sendbuf[0] = 0xff;
  	 UART_sendbuf[1] = TOS_LOCAL_ADDRESS;
  	 UART_sendbuf[2] = speed;
  	 //UART_sendbuf[3] = 0xF8;
  	 UART_sendbuf[4] = 0x00;
  	 UART_snumber = 5;
  	 UART_spointer = 0;
  	 call UART.put(UART_sendbuf[UART_spointer]);
  }
  void turncontrol(uint8_t turn, uint8_t loc)
  {
  
     UART_sendbuf[0] = 0xff;
  	 UART_sendbuf[1] = TOS_LOCAL_ADDRESS;
  	 UART_sendbuf[2] = 25;
  	 UART_sendbuf[3] = turn;
  	 UART_sendbuf[4] = loc;
  	 UART_snumber = 5;
  	 UART_spointer = 0;
  	 call UART.put(UART_sendbuf[UART_spointer]);
  }

  void lightcontrol(uint8_t cmd)
  {
	 if(cmd == 1)
		UART_sendbuf[3] = 0x48;
	else
	{
		UART_sendbuf[3] = 0x08;

     UART_sendbuf[0] = 0xff;
  	 UART_sendbuf[1] = TOS_LOCAL_ADDRESS;
  	 UART_sendbuf[2] = 0x7f;
  	 
  	 UART_sendbuf[4] = 0;
  	 UART_snumber = 5;
  	 UART_spointer = 0;
  	 call UART.put(UART_sendbuf[UART_spointer]);
	}
  }
  
  
  uint8_t iscollision()
  {
  	 uint8_t temp;
  	 	//check collision
  	 if (entrance[currentIC-1]) 	
  	 {
  	 	for (temp=0;temp<allroadstatuspointer;temp++)
  	 	{
  	 		if (selfroadnumber==allroadstatusbuff[temp][1]) 			      //at the same crossroad
  	 		{
  	 			if (selfdirection == TURNLEFT)                                    
  	 			{
  	 				if(((allroadstatusbuff[temp][2]-3) == selfroadjunction)
  	 			   	 ||((allroadstatusbuff[temp][2]+1) == selfroadjunction))   //vertical road check-> on the left
  	 				{
  	 						//no clollision
  	 				}
  	 				else if (((allroadstatusbuff[temp][2]+3) == selfroadjunction) //vertical road check-> on the right
  	 			   	 	   ||((allroadstatusbuff[temp][2]-1) == selfroadjunction))
  	 				{
  	 					if (allroadstatusbuff[temp][3]==TURNLEFT)
  	 					{
  	 						//no clollision
  	 					}
  	 					else 
  	 					{
  	 						return 1;
  	 					}
  	 				}
  	 				else if (allroadstatusbuff[temp][2] == selfroadjunction)
  	 				{
  	 					if (allroadstatusbuff[temp][3]==TURNLEFT)
  	 					{
  	 						return 1;
  	 					} 	 					
  	 				}
  	 			}  	 			
  	 			else //(selfdirection == FORWARD)  
  	 			{
  	 				if(((allroadstatusbuff[temp][2]-3) == selfroadjunction)
  	 			   	 ||((allroadstatusbuff[temp][2]+1) == selfroadjunction))   //vertical road check-> on the left
  	 				{
  	 					return 1;
  	 				}
  	 				else if (((allroadstatusbuff[temp][2]+3) == selfroadjunction) //vertical road check-> on the right
  	 			   	 	   ||((allroadstatusbuff[temp][2]-1) == selfroadjunction))
  	 				{
  	 					if (allroadstatusbuff[temp][3]==TURNLEFT)
  	 					{
  	 						//no clollision
  	 					}
  	 					else 
  	 					{
  	 						return 1;
  	 					}
  	 				}
  	 				else if (allroadstatusbuff[temp][2] == selfroadjunction)
  	 				{
	 					
  	 				}
  	 			} 
  	 		} 		
  	 	}
  	 }
	 return	0;
  }
 
  void  claimgopass()
  { 		
  	// if (currentIC !=7)
  	 {
		atomic gPktSending = 1;
  		Msgdata.data[0] = TOS_LOCAL_ADDRESS;
  		Msgdata.data[1] = selfroadnumber;
  		Msgdata.data[2] = selfroadjunction;
  		Msgdata.data[3] = mSeqNo;//selfdirection;
  		Msgdata.data[4] = selfstatus;
		Msgdata.data[5] = selflocation;
		Msgdata.data[6] = selfseq;
  		if ((call SendResultMsg.send(0, MESSAGE_LENGTH, &Msgdata))==SUCCESS)
			call Leds.greenToggle();
		else
			call Leds.redToggle();
			mcrosstimeout = mcrosstimercnt;
		mSeqNo++;
  	}
	
  }
  void  claimgopassover()
  { 
  	 {  
	 	atomic gPktSending = 2;
  		Msgdata.data[0] = TOS_LOCAL_ADDRESS;
  		Msgdata.data[1] = selfroadnumber;
  		Msgdata.data[2] = selfroadjunction;
  		Msgdata.data[3] = mSeqNo;//selfdirection;
  		Msgdata.data[4] = selfstatus;
		Msgdata.data[5] = selflocation;
		Msgdata.data[6] = selfseq;
  		if ((call SendResultMsg.send(TOS_BCAST_ADDR, MESSAGE_LENGTH, &Msgdata))==SUCCESS)
			call Leds.greenToggle();
		else
			call Leds.redToggle();
		//
		mSeqNo++;
  	}
  	mcrosstimeout = 0;
  	selfroadjunction = INVALID_JUNCTION;
  	selfroadnumber  = INVALID_ROAD;
  }  
  task void checkandgo()
  {	
#if 1
  	 if (iscollision()==1)
  	 {
  		selfstatus=CLISSIONSTATUS_WAITING;
  		carcontrol(0);
  		mtimeoutpt = mtimercnt;
		
  	 }
  	 else
#endif
  	 {
  		selfstatus=CLISSIONSTATUS_CLISSION;
  		claimgopass();
		gSpeedPending = 1;
  	 }
  }


  task void sendWarningMsg()
  {
	//call Leds.yellowOn();
	gVehWarnMsg.data[0] = TOS_LOCAL_ADDRESS;
	gVehWarnMsg.data[1] = selflocation;
	//call SendWarnMsg.send(0, sizeof(ITSWarnMsg), &gVehWarnMsg);
  }
  task void sendStatsMsg()
  {
	if(mStaTbl.numvs)
	{
		memcpy(&gVehStatsMsg, &mStaTbl, sizeof(ITSStatisticsMsg));
		call SendStasMsg.send(0, sizeof(ITSStatisticsMsg), &gVehStatsMsg);
		mStaTbl.numvs = 0;
	}	
  }
//         0        1     2    3     4
//0xff datalength carid speed dir icnumber
  task void checkuartinfo()
  {
  	//call Leds.greenToggle();
//	if (UART_receivebuf[1]==TOS_LOCAL_ADDRESS)  //CHECK CAR ID
	{
		TOS_LOCAL_ADDRESS=UART_receivebuf[1];
		currentspeed = UART_receivebuf[2];
		if(!UART_receivebuf[4])
		{
			if(!currentspeed && selfstatus!=CLISSIONSTATUS_WAITING)
			{
				mWarning++;
				if(mWarning >= MAX_WARNING_TIMES)
				{
					post sendWarningMsg();
					mWarning = 0;
				}
			}
			return;
		}
		currentIC = UART_receivebuf[4];
		currentdir = UART_receivebuf[3];
  	 	selfroadnumber = crossroadnumber[currentIC-1];
  	 	selfroadjunction = junction[currentIC-1];
  	 	selfdirection  = currentdir;
		selflocation = currentIC;

	
  	 	if (entrance[currentIC-1]) 	//road entrance
  	 	{
  	 	  
  			if (iscollision()==1)
  			{
  				selfstatus=CLISSIONSTATUS_WAITING;
  				carcontrol(0); //
  				mtimeoutpt = mtimercnt;
  			}
  			else 
  			{
  				selfstatus=CLISSIONSTATUS_CLISSION;
  				claimgopass();
  				gSpeedPending = 1;
  			}
  		}
  		else if(selfstatus==CLISSIONSTATUS_CLISSION) //road exit 
  		{
  			selfstatus = CLISSIONSTATUS_FREE;
  			
  			claimgopassover();
			lightcontrol(0);
  			sendnumber = 1;
  		}
		else
		{
			selfstatus = CLISSIONSTATUS_NULL;
			//post claimgopassover();
		}
	 }
  }
///////////////////////////////////////////////////////////////////  
  command result_t StdControl.init()
  {
  	atomic
  	{
  	signal_stopped = 0;
  		allroadstatuspointer = 0;
		selfseq = 0;
		gSpeedPending = 0;
  	}
  	mtimercnt = 0;
	mtimeoutpt = 0;
	mcrosstimercnt = 1;
	mcrosstimeout = 0;
  	call CommControl.init();

  	call Leds.init();
  	call UART.init();
	UART_sendbuf[3] = 0xF8;
	mStaTbl.numvs = 0;
	mWarning = 0;
	mSeqNo = 0;
	atomic gPktSending = 0;

    return SUCCESS;
  }
  command result_t StdControl.start() 
  {
  	call CommControl.start();
  	call mtimer.start(TIMER_REPEAT,TIME_UNIT_VALUE);
//	call Leds.start();
	call MacControl.enableAck();
  	call Leds.redOn();
    return SUCCESS;
  }
  command result_t StdControl.stop() 
  {
  	call CommControl.stop();
  	call Timer.stop();
  	call UART.stop();
    return SUCCESS;
  }
//////////////uart//////////////////////////////////////////////
  async event result_t UART.get(uint8_t data)
  {
		if(data==0xff)
		{
			UART_receivecounter=0;
		}
		else
		{ 
			UART_receivecounter++;
			if (UART_receivecounter<5)
			{
				UART_receivebuf[UART_receivecounter-1]=data;
			}
			else if(UART_receivecounter==5)
			{
				UART_receivebuf[UART_receivecounter-1]=data;
				//post  whj
				post checkuartinfo();
			}
		}
		return SUCCESS;
  }

  async event result_t UART.putDone()
  {
  	UART_spointer++;
	if (UART_spointer<UART_snumber)
	{
		call UART.put(UART_sendbuf[UART_spointer]);
	}
  	return SUCCESS;
  } 
/////////////////////////////////////////////////////////////////////////
  event result_t Timer.fired()
  {
  
	post checkandgo();	
  	return SUCCESS;
  }
  #define MAX_RESEND_TIMES 4
  	static uint8_t resendtimes = 0;
   void resendpkt(TOS_MsgPtr msg)
   {
	
		if(gPktSending == 1)
		{
			resendtimes++;
		}
		if(resendtimes > MAX_RESEND_TIMES)
		{
			carcontrol(0);
			
		}
		call Leds.yellowToggle();
		if ((call SendResultMsg.send(0, MESSAGE_LENGTH, &Msgdata))==SUCCESS)
			call Leds.greenToggle();
		else
			call Leds.redToggle();
   }
/////////////////////////////////////////////////////////////////////////
  event result_t SendResultMsg.sendDone(TOS_MsgPtr msg, result_t success)
  {
	if(msg->ack == 1)
	{
		selfseq++;
    if(gSpeedPending && !signal_stopped)
		{
			carcontrol(GIVENSPEED);
			lightcontrol(1);
			gSpeedPending = 0;
		}
	gPktSending = 0;
		resendtimes = 0;
		
	}	
	else
	{
		resendpkt(msg);
		return FAIL;
	}
	
  	return SUCCESS;
  }
    
	
  event TOS_MsgPtr ReceiveStasMsg.receive(TOS_MsgPtr m)
  {
	if(mStaTbl.numvs)
	{
		memcpy(&gVehStatsMsg, &mStaTbl, sizeof(ITSStatisticsMsg));
		call SendStasMsg.send(0, sizeof(ITSStatisticsMsg), &gVehStatsMsg);
		mStaTbl.numvs = 0;
	}	
	memcpy(&mStaTbl,m->data, sizeof(ITSStatisticsMsg));
	return m;
  }

//***************************For traffic light control message **************************
//   0        1         	  	2   	  	         3      		
// ROADNUMBER  ROADJUNCTION   		COLOR  	  		REMAIN_TIME
//			       (1:GREEN, 2:YELLOW, 3: RED)
 
#define SIGNAL_LIGHT_FLAG 2
#define SIGNAL_LIGHT_RED 3
#define SIGNAL_LIGHT_YELLOW 2
#define SIGNAL_LIGHT_GREEN 1
  event TOS_MsgPtr ReceiveTrafficMsg.receive(TOS_MsgPtr m)
  {
	uint8_t * pData = (uint8_t *) m->data;
  	//call Leds.yellowToggle();
  	
	if (selfroadnumber == pData[0] && pData[1] == selfroadjunction && (pData[2] == SIGNAL_LIGHT_RED||pData[2] == SIGNAL_LIGHT_YELLOW)) {
			if(mcrosstimeout)
			{
				carcontrol(0);
				signal_stopped = 1;
			}
	} else if(selfroadnumber == pData[0] && pData[1] == selfroadjunction && (pData[2] == SIGNAL_LIGHT_GREEN)) {
		carcontrol(GIVENSPEED);
		signal_stopped = 0;
	}
	return m;
  }
  event TOS_MsgPtr ReceiveTestMsg.receive(TOS_MsgPtr m)
  {
//   0        1         	  2   	  	       3      		4
// CARID  ROADNUMBER   	 ROADJUNCTION  		  DIR   	  STATUS
//		selfroadnumber, selfroadjunction, selfdirection, selfstatus;

	uint8_t temp;
 	uint8_t i;	
	call Leds.redOff();
	#if 0
	if(TOS_LOCAL_ADDRESS==17)
	{
		carcontrol(0);
		return m;
	}
	for(i = 0; i<0x7f; i++)
		for(temp = 0; temp<0x7f; temp++)
			//horncontrol(0);
	#endif

	if ((uint8_t)(m->data[4])==CLISSIONSTATUS_NULL)
	{
		return m;
	}

 	if (TOS_LOCAL_ADDRESS==0)
 	{
  	 	UART_sendbuf[0] = (uint8_t)(m->data[0]);
  	 	UART_sendbuf[1] = (uint8_t)(m->data[1]);
  	 	UART_sendbuf[2] = (uint8_t)(m->data[2]);
  	 	UART_sendbuf[3] = (uint8_t)(m->data[3]);
  	 	UART_sendbuf[4] = (uint8_t)(m->data[4]);
  	 	UART_snumber = 5;
  	 	UART_spointer = 0;
  	 	call UART.put(UART_sendbuf[UART_spointer]);	
 	}
 	else {
 	if (allroadstatuspointer < MAX_BUFFER_SZ && (uint8_t)(m->data[4])==CLISSIONSTATUS_CLISSION)
 	{
 		allroadstatusbuff[allroadstatuspointer][0]=(uint8_t)(m->data[0]);
 		allroadstatusbuff[allroadstatuspointer][1]=(uint8_t)(m->data[1]);
 		allroadstatusbuff[allroadstatuspointer][2]=(uint8_t)(m->data[2]);
 		allroadstatusbuff[allroadstatuspointer][3]=(uint8_t)(m->data[3]);
 		allroadstatusbuff[allroadstatuspointer][4]=(uint8_t)(m->data[4]);
 		allroadstatusbuff[allroadstatuspointer][5]= TIME_OUT_VALUE; 
 		allroadstatuspointer++;
 	}
 	
 	else if ((uint8_t)(m->data[4])==CLISSIONSTATUS_FREE)
 	{
 		//call Leds.greenToggle();
		for(temp=0;temp<allroadstatuspointer;temp++)
 		{
 			if((allroadstatusbuff[temp][0]==(uint8_t)(m->data[0]))&&((allroadstatusbuff[temp][1]==(uint8_t)(m->data[1]))))
 			{
 				for(i=temp;i<allroadstatuspointer-1;i++)
 				{
 					allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
 					allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
 					allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
 					allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
 					allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
					allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
 				}
 				allroadstatuspointer--;
 				break;
 			}
 		}
		#if 0
 		if(selfstatus==CLISSIONSTATUS_WAITING && elapseallcollisions())
 		{
 			call Leds.yellowToggle();
 			call Timer.start(TIMER_ONE_SHOT, rand()%800+200);
 		}
		#endif //whj
 	}}
  	return m;
  }
  
  uint8_t elapseallcollisions()
  {
  	uint8_t i, temp = 0, found = 1;
  	if(!allroadstatuspointer)
  	    return found;
  	  else
  	 {
  	 	while(temp<allroadstatuspointer)
  	 	{
			if(allroadstatusbuff[temp][5] > TIME_OUT_VALUE)
				allroadstatusbuff[temp][5] = 0;
  	 		if(allroadstatusbuff[temp][5])
  	 			allroadstatusbuff[temp][5]--;
  	 		else
            {
  	 			for(i=temp;i<allroadstatuspointer-1;i++)
				{
			 		allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
			 		allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
			 		allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
			 		allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
			 		allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
					allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
			 	}
			 	allroadstatuspointer--;
			 	continue;
			 }
  	 		if (selfroadnumber==allroadstatusbuff[temp][1] ) 			      //at the same crossroad
  	 		{
  	 			if (selfdirection == TURNLEFT)                                    
  	 			{
  	 				if(((allroadstatusbuff[temp][2]-3) == selfroadjunction)
  	 			   	 ||((allroadstatusbuff[temp][2]+1) == selfroadjunction))   //vertical road check-> on the left
  	 				{
  	 					temp++;
  	 					continue;
  	 				}
  	 				else if (((allroadstatusbuff[temp][2]+3) == selfroadjunction) //vertical road check-> on the right
  	 			   	 	   ||((allroadstatusbuff[temp][2]-1) == selfroadjunction))
  	 				{
  	 					if (allroadstatusbuff[temp][3]!=TURNLEFT)
  	 					{
  	 						if(allroadstatusbuff[temp][5])
			 					found = 0;
			 				else
			 				{
  	 							for(i=temp;i<allroadstatuspointer-1;i++)
			 					{
			 						allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
			 						allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
			 						allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
			 						allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
			 						allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
			 						allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
			 					}
			 					allroadstatuspointer--;
			 					continue;
			 				}
			 				
			 				
  	 					}
  	 				}
  	 				else if (allroadstatusbuff[temp][2] == selfroadjunction)
  	 				{
  	 					if (allroadstatusbuff[temp][3]==TURNLEFT)
  	 					{
  	 						if(allroadstatusbuff[temp][5])
			 					found = 0;
			 				else
			 				{
  	 							for(i=temp;i<allroadstatuspointer-1;i++)
			 					{
			 						allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
			 						allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
			 						allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
			 						allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
			 						allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
			 						allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
			 					}
			 					allroadstatuspointer--;
			 				continue;
			 				}	 				
			 				
  	 					} 	 					
  	 				}
  	 			}  	 			
  	 			else //(selfdirection == FORWARD)  
  	 			{
  	 				if(((allroadstatusbuff[temp][2]-3) == selfroadjunction)
  	 			   	 ||((allroadstatusbuff[temp][2]+1) == selfroadjunction))   //vertical road check-> on the left
  	 				{
  	 					   if(allroadstatusbuff[temp][5])
			 					found = 0;
			 				else
			 				{
  	 							for(i=temp;i<allroadstatuspointer-1;i++)
			 					{
			 						allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
			 						allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
			 						allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
			 						allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
			 						allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
			 						allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
			 					}
			 					allroadstatuspointer--;
			 					continue;
			 				}			
			 				
  	 				}
  	 				else if (((allroadstatusbuff[temp][2]+3) == selfroadjunction) //vertical road check-> on the right
  	 			   	 	   ||((allroadstatusbuff[temp][2]-1) == selfroadjunction))
  	 				{
  	 					if (allroadstatusbuff[temp][3]!=TURNLEFT)
  	 					{
  	 						if(allroadstatusbuff[temp][5])
			 					found = 0;
			 				else
			 				{
  	 							for(i=temp;i<allroadstatuspointer-1;i++)
			 					{
			 						allroadstatusbuff[temp][0]=allroadstatusbuff[temp+1][0];
			 						allroadstatusbuff[temp][1]=allroadstatusbuff[temp+1][1];
			 						allroadstatusbuff[temp][2]=allroadstatusbuff[temp+1][2];
			 						allroadstatusbuff[temp][3]=allroadstatusbuff[temp+1][3];
			 						allroadstatusbuff[temp][4]=allroadstatusbuff[temp+1][4];
			 						allroadstatusbuff[temp][5]=allroadstatusbuff[temp+1][5];
			 					}
			 					allroadstatuspointer--;
			 					continue;
			 				}		 				
			 				
  	 					}
  	 				}
  	 			} 
  	 		}
  	 		temp++; 		
  	 	}
  	 }
  	 return found;
  }
  task void checkTimeout()
  {
  	if(elapseallcollisions())
  	{
  		if(selfstatus==CLISSIONSTATUS_WAITING)
 		{
 			//call Leds.yellowToggle();
 			call Timer.start(TIMER_ONE_SHOT, rand()%100);
 		}
 	}
  }
  
  #define TICK_UNIT (1200 / TIME_UNIT_VALUE)
  event result_t mtimer.fired()
  {

  	 static uint8_t tick = 0;
  	 tick++;

#ifdef TEST_VEHICLE
	claimgopass();
#else
  	 if(tick == TICK_UNIT)	
  	 {
  	   	 mtimercnt++;
		  	 tick = 0;
		  	 post checkTimeout();
  	 }
  	 mcrosstimercnt++;
  	 if(!mcrosstimercnt)
  	 {
  	  mcrosstimercnt = 1;
  	  if(mcrosstimeout)
  	  	mcrosstimeout = 1;
  	 }
  	 if(mcrosstimeout)
  	 {
  	 		mcrosstimeout = 0;
  	 }
#endif
    if(gSpeedPending && !signal_stopped && !gPktSending)
		{
			carcontrol(GIVENSPEED);
			lightcontrol(1);
			gSpeedPending = 0;
		}

		 return SUCCESS;
  }
 
  event result_t SendStasMsg.sendDone(TOS_MsgPtr msg, result_t success)
  {
  	return SUCCESS;
  }

  event result_t SendWarnMsg.sendDone(TOS_MsgPtr msg, result_t success)
  {
  	return SUCCESS;
  }
}


