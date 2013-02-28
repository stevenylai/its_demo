//includes Constants;
includes ITS;
includes ITSCmd;
//includes Common;

module CmdReceiverM {
  provides {
    interface StdControl;
    interface SensorInfo;
  }
  uses {
    //interface SensorReader;
		interface TimeSet;
		interface TimeUtil;
		interface Leds;
    
		interface Receive as CmdReceive; 
		interface StdControl as ReaderControl;
		interface StdControl as SubControl;
    //interface RouteControl;
  }
}

implementation {
	// Fields that define the 'Role' of the current sensor
	bool initialized = FALSE;
	uint8_t sensorType;
	uint8_t operCode;
	struct Sensor sensors [MAX_SENSOR_NUM];

	static void checkReader();
	/******** Initialization *********/
  static void initialize() {
    atomic
    {
    	sensorType = SENSOR_TYPE_UNKNOWN;
    	operCode = OPER_EVERY_MSG * OPER_SUMMARY_MSG * OPER_LIGHT;
    }
  }

  command result_t StdControl.init() {
  	initialize();
    return call SubControl.init();
  }

  command result_t StdControl.start() {
    return call SubControl.start();
  }

  command result_t StdControl.stop() {
  	return call SubControl.stop();
  }

  /***********************************************************************
   * Commands and events
   ***********************************************************************/

	command uint8_t SensorInfo.getSensorType()
	{
		return sensorType;
	}
	
	command uint8_t SensorInfo.getOperCode()
	{
		return operCode;
	}
	
	command struct Sensor * SensorInfo.getNextSensor(uint16_t distOffset, uint16_t speed)
	{
		uint8_t i = 0;
		struct Sensor *found = NULL;
		
		//dbg(DBG_USR2, "Car: speed is: %d, offset is %d\n", speed, distOffset);
		for (; i<MAX_SENSOR_NUM; i++)
		{
			//dbg(DBG_USR2, "Car: Checking sensor: %d\n", sensors[i].sensorID);
			if (sensors[i].sensorID==0)
				break;
			else
				found = &(sensors[i]);

			if (speed==0)
			{
				break;
			}
			// There is already enough time to react
			// else if ((sensors[i].distance-distOffset)/speed > SENSOR_REACTION_TIME)
			else if ((sensors[i].distance)/speed > SENSOR_REACTION_TIME)
				break;
		}
		 // Always return the first sensor
		//if (sensors[0].sensorID!=0)
			//found = &(sensors[0]);
		return found;
	}
	
	command uint8_t SensorInfo.sensorListSize()
	{
		uint8_t i = 0;
		for (; i<MAX_SENSOR_NUM; i++)
		{
			if (sensors[i].sensorID==0)
				break;
		}
		return i;
	}
	
	command uint16_t SensorInfo.getSensor (uint8_t idx)
	{
		return sensors[idx].sensorID;
	}
	/*
	async event result_t SensorReader.sensorChanged(uint8_t data)
	{
		atomic {
			// Mote is covered
			if (data == SENSOR_COVERED && initialized)
			{
				call CarMaintainer.carReached();
				// If the mote is 'Statistic' sensor, update the total number of cars passed by
			}
			// Mote is uncovered
			else if (data == SENSOR_UNCOVERED && initialized)
				call CarMaintainer.carLeft();
		}
		return SUCCESS;
	}*/
  event TOS_MsgPtr CmdReceive.receive(TOS_MsgPtr pMsg, void* payload, uint16_t payloadLen) {
		uint8_t i;
		ITSCmdMsg *pCmdMsg = (ITSCmdMsg *)payload;
		
		//dbg(DBG_USR2, "ITSM: Payload length: %d\n", payloadLen);
		dbg(DBG_USR2, "ITSM: Message received for 0x%02x with type 0x%02x\n", (uint16_t)(pCmdMsg->sensorID), (uint8_t)(pCmdMsg->sensorType));
		// Update information if the message is for this mote
		// The 'initialized' variable may not be checked as sensors can be initialized for more than once.
		//if (pCmdMsg->sensorID == (uint16_t)TOS_LOCAL_ADDRESS && !initialized) {
		if (pCmdMsg->sensorID == (uint16_t)TOS_LOCAL_ADDRESS) {
			call Leds.greenToggle();
			// Now the sensor should have a valid type
			sensorType = pCmdMsg->sensorType;
			operCode = pCmdMsg->operationMode;
			dbg(DBG_USR2, "ITSM: got operation code: %d\n", operCode);
			
			for (i=0; i<MAX_SENSOR_NUM; i++)
			{
				sensors[i].sensorID = pCmdMsg->sensors[i].sensorID;
				sensors[i].distance = pCmdMsg->sensors[i].distance;
				dbg(DBG_USR2, "ITSM: Got new information. Sensor: %d. Distance: %d\n", (uint16_t)(sensors[i].sensorID), (uint16_t)(sensors[i].distance));
			}
			initialized = TRUE;
			checkReader();
		}
			dbg(DBG_USR2, "ITSM: Time initialized: %d, %d\n", pCmdMsg->initTime.high32, pCmdMsg->initTime.low32);
			call TimeSet.set(pCmdMsg->initTime);
			//pCmdMsg->initTime = call TimeUtil.addUint32(pCmdMsg->initTime, SENSOR_REACTION_TIME);
			pCmdMsg->initTime = call TimeUtil.addUint32(pCmdMsg->initTime, 100);
    return pMsg;
  }
  static void checkReader()
  {
#ifndef ALL_TIME_MSG
  	if (sensorType == SENSOR_TYPE_START || sensorType == SENSOR_TYPE_ONLY || sensorType == SENSOR_TYPE_PARK)
#endif
  		call ReaderControl.start();
	}
}


