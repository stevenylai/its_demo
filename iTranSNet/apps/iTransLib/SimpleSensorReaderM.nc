#define NORMAL_TIMER_RATE 50
#define PARK_TIMER_RATE 50
#define DATA_THRESHOLD 0x0300

includes ITS;
includes MultiHop;

module SimpleSensorReaderM
{
	provides
	{
		interface StdControl;
	}
	uses
	{
		interface Timer;
		interface ADC;
		interface CarMaintainer;
		interface Send as SendToBase;
		interface SensorInfo;
	}
}
implementation
{
	TOS_Msg gMsgBuffer;
	ITSMsg * pITSMsg;
	
	uint16_t lastReading;
	bool sendBusy;

	task void reportCarLeft();
	task void reportCarReached();

	command result_t StdControl.init() {
		uint16_t Len;
		atomic {
			lastReading = DATA_THRESHOLD*2;
			sendBusy=FALSE;
		}
		pITSMsg = (ITSMsg *)call SendToBase.getBuffer(&gMsgBuffer, &Len);
		pITSMsg->operationMode=OPER_EVERY_MSG;
		return SUCCESS;
	}
	
	command result_t StdControl.start() {
		atomic pITSMsg->sensorID=TOS_LOCAL_ADDRESS;
		if (call SensorInfo.getSensorType()!=SENSOR_TYPE_PARK)
			call Timer.start(TIMER_REPEAT, NORMAL_TIMER_RATE);
		else {
			call CarMaintainer.carLeft();
			call Timer.start(TIMER_REPEAT, PARK_TIMER_RATE);
		}
		return SUCCESS;
	}
	
	command result_t StdControl.stop() {
		return call Timer.stop();
	}

	event result_t Timer.fired() {
  	call ADC.getData();
		return SUCCESS;
	}
  
	task void reportCarLeft()
	{
		// Don't send if the sensor hasn't been initialized yet.
		if (call SensorInfo.getSensorType() != SENSOR_TYPE_UNKNOWN)
		{
			call CarMaintainer.carLeft();
		}
	}
	task void reportCarReached()
	{
		// Don't send if the sensor hasn't been initialized yet.
		if (call SensorInfo.getSensorType() != SENSOR_TYPE_UNKNOWN)
		{
			call CarMaintainer.carReached();
		}
	}

	static result_t sendSensorStatus (uint8_t status) {
		uint8_t operCode = call SensorInfo.getOperCode();
		if (operCode%OPER_EVERY_MSG==0)
		{
			atomic pITSMsg->reading=status;
			if (TOS_LOCAL_ADDRESS!=0) {
				if ((call SendToBase.send(&gMsgBuffer, sizeof(ITSMsg)))==SUCCESS) {
					atomic sendBusy = TRUE;
				}
				else
					return FAIL;
			}
		}
		return SUCCESS;
	}

  async event result_t ADC.dataReady(uint16_t data) {
		if (!sendBusy) {
			atomic {
	 			// Mote is uncovered
 				if (data >= DATA_THRESHOLD && lastReading < DATA_THRESHOLD)
 				{
 					post reportCarLeft();
	 			}
 				// Mote is covered
 				else if (data < DATA_THRESHOLD && lastReading >= DATA_THRESHOLD)
 				{
 					post reportCarReached ();
		 		}
			}
		}
 		atomic lastReading = data;

  	//dbg(DBG_USR2, "End of getting data");
  	return SUCCESS;
	}

	event result_t CarMaintainer.carReachedDone() {
		return sendSensorStatus (SENSOR_COVERED);
	}
	event result_t CarMaintainer.carLeftDone() {
		return sendSensorStatus (SENSOR_UNCOVERED);
	}

	event result_t SendToBase.sendDone(TOS_MsgPtr pMsg, result_t success) {
		atomic sendBusy = FALSE;
		return SUCCESS;
	}
}
