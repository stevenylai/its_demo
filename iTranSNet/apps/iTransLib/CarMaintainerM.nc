//includes Constants;
includes CarCmd;
includes SimpleQueue;
includes ITSCmd;

module CarMaintainerM
{
	provides
	{
		interface StdControl;
		interface CarMaintainer;
	}
	uses
	{
		interface SensorInfo;
		interface CarPark;
		interface SendMsg;
		interface Timer as SendTimer;
		interface ReceiveMsg;
		interface CommControl;
		// For controling the sensor to read data
		interface StdControl as ReaderControl;
		
		// Component for report message to base station
		interface Send as SendToBase;
		
		// Components for calculating time
		interface TimeUtil;
		interface Time;
		
		// Components for making sound
		interface Timer as ChirpTimer;
		interface StdControl as ChirpControl;
		
		// Components for making lights
		interface Leds;
		// For collision avoidance
		interface Timer as CollisionTimer;

		// For communication with the sensors on the car
		interface SendMsg as SendControlMsg;
	}
}
implementation
{
	TOS_Msg gReportMsg; // Message for reporting
	ITSMsg * pITSMsg;
	uint8_t lastReading;
	uint8_t leftStatus; // For 'START' sensor to report to base
	uint8_t reachedStatus; // Status to control the program flow
	uint8_t pendingMsg; // For 'END' sensor to warn other sensors and report to base
	uint8_t carPassed; // For 'END' sensor to report number of cars passed by
	
	TOS_Msg gMsgBuffer;
	struct queue expectCar;
	CarCmdMsg justLeft; // Used to temporary hold the car that just left the current sensor
	// Time for calculating the length of the car
	tos_time_t time_length;
	tos_time_t time_reach;
	TOS_Msg carMsgBuffer;
	enum {
		// Status codes for leftStatus
		NO_PENDING,
		REPORT_PENDING,
		SENDING_WARN,
		// Status codes for reachedStatus
	};
	bool danger;
	task void reportForwardSTAT (); // Step 1
	task void recordCarLeftSTART(); // Step 2
	static void calculateSpeed (); // Step 4
	static void calculateLength(); // Step 5
	task void sendWarning(); // Step 6
	task void sendNext(); // Step 6
	//task void reportToBase(); // task to report sensor readings to base station
	task void receivedMsgTask (); // Task after receiving message such as turn on light.
	static void carLeaving(); // Task after the car has left such as turn off light.
	static void checkCollision (tos_time_t *); // function for checking potential collision
	static uint32_t calcTimeDiff (tos_time_t *, tos_time_t *);
	
	command result_t StdControl.init() {
		//call CommControl.setPromiscuous(FALSE);
		atomic
		{
			// Initialize the queue information
			expectCar.count = 0;
			expectCar.front = 1;
			expectCar.rear = 0;
			
			// Clear Status
			leftStatus = NO_PENDING;
			pendingMsg = 0;
			carPassed = 0;
			danger = FALSE;
		}
		clearEntry (&justLeft);
		return call ReaderControl.init();
	}
	
	command result_t StdControl.start() {
		uint16_t Len;
		atomic {
			pITSMsg = (ITSMsg *)call SendToBase.getBuffer(&gReportMsg, &Len);
			pITSMsg->sensorID = TOS_LOCAL_ADDRESS;
		}
		return SUCCESS;
	}
	
	command result_t StdControl.stop() {
		return SUCCESS;
	}

	event TOS_MsgPtr ReceiveMsg.receive(TOS_MsgPtr m)
	{
		if (m->addr == TOS_LOCAL_ADDRESS)
		{
			atomic
			{
				CarCmdMsg *pReading = (CarCmdMsg *)m->data;
				//CarCmdMsg *reportInfo;
				// Step 3 (Message receiver)
				if (pReading->msgType==MSG_TYPE_INFORM)
				{
					dbg(DBG_USR2, "Car: Message received from %d\n", pReading->sourceID);
					dbg(DBG_USR2, "Car: CarInfo: CarID: %d, Speed: %d, Length: %d\n", pReading->c.carID,pReading->c.speed,pReading->c.length);
					dbg(DBG_USR2, "Car: MessageInfo: Distance: %d, StartTime(l): %d, EndTime(l): %d\n", pReading->distance, pReading->startTime.low32, pReading->endTime.low32);
					//dbg(DBG_USR2, "Car list info: %d, %d", expectCar.front, expectCar.rear);
					append(pReading, &expectCar);
				}
				// Step 6 (Message receiver)
				else if (pReading->msgType==MSG_TYPE_WARN)
				{
					//call Leds.yellowToggle();
					dbg(DBG_USR2, "MSG_Warn: warning received from %d",pReading->sourceID);
					// Simply update the time for checking collision
					justLeft.endTime = pReading -> endTime;
					danger=TRUE;
					call CollisionTimer.start(TIMER_ONE_SHOT, 1000);
				}
			} // end of atomic
			post receivedMsgTask ();
		} // end of if (m->addr == TOS_LOCAL_ADDRESS)
		else
		{
			CarCmdMsg *pReading = (CarCmdMsg *)m->data;
			if (pReading ->msgType==MSG_TYPE_INFORM||pReading->msgType==MSG_TYPE_WARN)
			{

			}
		}
		return m;
	}

	static void sendParkInfo (uint8_t mode)
	{
		// Added for car controling
		SensorControlMsg * carControlMsgPtr = (SensorControlMsg *)carMsgBuffer.data;

		carControlMsgPtr -> sensorID = call SensorInfo.getSensor(0);
		carControlMsgPtr -> sensorType = SENSOR_TYPE_CAR;
		carControlMsgPtr -> operationMode = mode;
		call SendControlMsg.send(carControlMsgPtr->sensorID, sizeof(SensorControlMsg), &carMsgBuffer);
	}

	/**
	 *	Actions to be taken when a car just left a sensor.
	 *	Statstic sensor:
	 *	   Nothing to be done.
	 *	Normal sensor:
	 *	1. Get the last car in the list.
	 *	2. Calculate the length of the car.
	 *	3. Report to the previous sensor if necessary.
	 *	4. Inform the next sensor about the coming car.
	 *	5. Remove the car from the list.
	 */
	command result_t CarMaintainer.carLeft()
	{
		if (call SensorInfo.getSensorType()!=SENSOR_TYPE_PARK) {
			atomic {
				time_length = call Time.get();
				lastReading = SENSOR_UNCOVERED;
			}
			calculateLength ();
		} else {
			sendParkInfo(OPER_UNOCCUPIED);
		}
		return SUCCESS;
	}
	/**
	 *	Actions to be taken when a car just reached a sensor.
	 *	Statstic sensor:
	 *	1. Record the car.
	 *	2. Inform the next sensors that a new car has entered the region
	 *	Normal sensor:
	 *	1. Get the last car informed by previous sensor.
	 *	2. Calculate the speed.
	 */
	command result_t CarMaintainer.carReached()
	{
		if (call SensorInfo.getSensorType()!=SENSOR_TYPE_PARK) {
			atomic {
				time_reach = call Time.get();
				lastReading = SENSOR_COVERED;
			}
			calculateSpeed();
		} else {
			sendParkInfo(OPER_OCCUPIED);
		}
		
		return SUCCESS;
	}

	event result_t SendControlMsg.sendDone(TOS_MsgPtr msg, result_t success)
	{
		SensorControlMsg * pReading = (SensorControlMsg *)msg->data;
		if (pReading->sensorType == SENSOR_TYPE_CAR && pReading->operationMode == OPER_UNOCCUPIED)
			signal CarMaintainer.carLeftDone();
		else
			signal CarMaintainer.carReachedDone();
		return SUCCESS;
	}
	event result_t SendMsg.sendDone(TOS_MsgPtr msg, result_t success)
	{
		dbg(DBG_USR2, "Car: finished sending car message, %d\n", success);
		if (pendingMsg>0)
		{
			post sendNext();
		}
		else if (leftStatus == REPORT_PENDING)
		{
			call SendToBase.send(&gReportMsg, sizeof(ITSMsg));
		}
		else
			signal CarMaintainer.carLeftDone();
		return SUCCESS;
	}

	// Step 1
	task void reportForwardSTAT ()
	{
		
	}
	static void moveToPark ()
	{
		// Added for car controling
		SensorControlMsg * carControlMsgPtr = (SensorControlMsg *)carMsgBuffer.data;

		carControlMsgPtr -> sensorID = TOS_BCAST_ADDR;
		carControlMsgPtr -> sensorType = SENSOR_TYPE_CAR;
		carControlMsgPtr -> operationMode = OPER_TURN_RIGHT;
		call SendControlMsg.send(TOS_BCAST_ADDR, sizeof(SensorControlMsg), &carMsgBuffer);	
	}
	static void stopCars ()
	{
		// Added for car controling
		SensorControlMsg * carControlMsgPtr = (SensorControlMsg *)carMsgBuffer.data;

		carControlMsgPtr -> sensorID = TOS_BCAST_ADDR;
		carControlMsgPtr -> sensorType = SENSOR_TYPE_CAR;
		carControlMsgPtr -> operationMode = OPER_COLLISION;
		call SendControlMsg.send(TOS_BCAST_ADDR, sizeof(SensorControlMsg), &carMsgBuffer);
		call Leds.redToggle();
		call ChirpControl.start();
	}
	static void moveCars ()
	{
		// Added for car controling
		SensorControlMsg * carControlMsgPtr = (SensorControlMsg *)carMsgBuffer.data;

		carControlMsgPtr -> sensorID = TOS_BCAST_ADDR;
		carControlMsgPtr -> sensorType = SENSOR_TYPE_CAR;
		carControlMsgPtr -> operationMode = OPER_NO_COLLISION;
		call SendControlMsg.send(TOS_BCAST_ADDR, sizeof(SensorControlMsg), &carMsgBuffer);
		//call Leds.redToggle();
	}
	// Step 4
	static void calculateSpeed ()
	{
		uint32_t timeDiff;
		CarCmdMsg newInfo; // For 'Stat' sensors
		uint8_t sensorType = call SensorInfo.getSensorType();

		// Append the car if necessary
		/***************Record the time*****************/
		CarCmdMsg *firstInfo = getFirst(&expectCar);
		dbg(DBG_USR2, "Car: A car just reached!\n");
		if (firstInfo != NULL)
		{
			firstInfo->endTime = time_reach;
			//dbg(DBG_USR2, "Car Got informed car: %d,%d, %d,%d\n", firstInfo->startTime.high32, firstInfo->startTime.low32, firstInfo->endTime.high32, firstInfo->endTime.low32);
		}
		else
		{
			//dbg(DBG_USR2, "Car: this sensor is not informed about the incoming car.");
			newInfo.c.length=newInfo.c.speed=0;
			newInfo.startTime.high32 = newInfo.startTime.low32 = 0;
			newInfo.endTime = time_reach;
			append(&newInfo, &expectCar);
			firstInfo = getFirst(&expectCar);
		}
		/*************************************************/

		//checkCollision(&time_reach);
		if (firstInfo != NULL)
		{
			if (firstInfo->startTime.low32 != 0)
			{
				timeDiff = calcTimeDiff(&(firstInfo->endTime), &(firstInfo->startTime));
				//dbg(DBG_USR2, "Car: Caution! 1: %d, %d, 2: %d, %d, d: %d\n", firstInfo->startTime.high32, firstInfo->startTime.low32, firstInfo->endTime.high32, firstInfo->endTime.low32, timeDiff);
				firstInfo -> c.speed = firstInfo -> distance/timeDiff;
				dbg(DBG_USR2, "Car: speed updated: %d/%d=%d", firstInfo -> distance, timeDiff, firstInfo -> c.speed);
				// update to indicate that we have processed this message
				firstInfo -> msgType = MSG_TYPE_PROCESSED;
				dbg(DBG_USR2, "MSG_Base: Speed updated as %d\n", firstInfo -> c.speed);
				//dbg(DBG_USR2, "Car: calculating speed, time diff: %d, speed: %d\n", timeDiff, firstInfo -> c.speed);
			}
		}
		switch (sensorType)
		{
			case SENSOR_TYPE_START:
			case SENSOR_TYPE_ONLY:
			case SENSOR_TYPE_END:
				carPassed++;
				break;
		}
		if (call CarPark.checkAvail())
		{
			moveToPark();
		}
		else if (danger==TRUE)
		{
			danger = FALSE;
			stopCars();
			call ChirpTimer.start(TIMER_ONE_SHOT, CHIRP_TIME);
		}
		else
		{
			//Sth here to accelerate the car
			moveCars();
			//signal CarMaintainer.carReachedDone();
		}
	}

	// Step 5
	static void calculateLength()
	{
		uint32_t timeDiff;
		CarCmdMsg *firstInfo = NULL;
		// For sending messages to other sensors
		CarCmdMsg *pReading=NULL;
		struct Sensor *nextSensor=NULL;

		uint8_t sensorType = call SensorInfo.getSensorType();
		
		/**************For START sensors******************/
		// Get the operation code
		uint8_t operCode;
		operCode = call SensorInfo.getOperCode();
		// Update the 'last left time' for collision detection
		justLeft.endTime = time_length;
		// Report base station when the queue list is full
		dbg(DBG_USR2, "Car: car left\n");
		if (sensorType==SENSOR_TYPE_START && carPassed >= MAX_SENSOR_NUM)
		{
			if (operCode%OPER_SUMMARY_MSG==0)
			{
				// Summary report
				dbg(DBG_USR2, "MSG_Base: car list is full, now report to base station.\n");
				pITSMsg -> operationMode = OPER_SUMMARY_MSG;
				pITSMsg -> numCarPassed = carPassed;
				carPassed = 0; // Reset the number after reporting
				leftStatus = REPORT_PENDING; // leftStatus for sending message later.
				dbg(DBG_USR2, "Car: Reporting summary to base: %d\n",pITSMsg -> numCarPassed);
				//call SendToBase.send(&gReportMsg, sizeof(ITSMsg));
			}
			else
			{
				// Simply reset the number
				carPassed = 0;
			}
		}
		/*****************************************/
		
		// Update the car message information
		firstInfo = getFirst(&expectCar);
		if (firstInfo != NULL) // firstInfo should always be non-null
		{
			// Need the speed in order to get the length
			if (firstInfo -> c.speed != 0)
			{
				timeDiff =  calcTimeDiff(&time_length, &(firstInfo->endTime));
				firstInfo -> c.length = firstInfo -> c.speed*timeDiff;
				//dbg(DBG_USR2, "Car: calculating length, time diff: %d, length: %d\n", timeDiff, firstInfo -> c.length);
			}

			nextSensor = call SensorInfo.getNextSensor(firstInfo->c.length, firstInfo->c.speed);
			
			// Construct the message
			pReading = (CarCmdMsg *)gMsgBuffer.data;
			pReading->c = firstInfo->c;
			// Start time to other sensors is always the time when the car reached the sensor
			pReading->startTime = firstInfo->endTime;
			pReading->endTime = time_length;
			// Length is calculated, no need to report back
			pReading->reportBack = FALSE;
			pReading->sourceID = TOS_LOCAL_ADDRESS;
		}

		// Step 6 Trigger
		if (sensorType == SENSOR_TYPE_END || sensorType == SENSOR_TYPE_ONLY)
		{
			dbg(DBG_USR2, "MSG_Warn: beginning to send warnings\n");
			post sendWarning();
		}
		// Inform the next sensor
		else if (nextSensor!=NULL && (sensorType == SENSOR_TYPE_NORM||sensorType == SENSOR_TYPE_START))
		{
			pReading->msgType = MSG_TYPE_INFORM;
			pReading->distance = nextSensor->distance;
			dbg(DBG_USR2, "Car: Sending car information to %d\n", nextSensor->sensorID);
			//dbg(DBG_USR2, "Car: CarInfo: CarID: %d, Speed: %d, Length: %d\n", pReading->c.carID,pReading->c.speed,pReading->c.length);
			//dbg(DBG_USR2, "Car: MessageInfo: Distance: %d, StartTime(l): %d, EndTime(l): %d\n", pReading->distance, pReading->startTime.low32, pReading->endTime.low32);
			call SendMsg.send(nextSensor->sensorID,sizeof(CarCmdMsg),&gMsgBuffer);
		}
		else
			signal CarMaintainer.carLeftDone();

		// Delete the car information
		if (firstInfo != NULL)
		{
			dbg(DBG_USR2, "Car: car left, removing entry.\n");
			serve(&justLeft, &expectCar);
		}
		danger=TRUE;
		call CollisionTimer.start(TIMER_ONE_SHOT, 1000);
		carLeaving ();
	}
	
	// Step 6
	// WORK! Not good here, should just broadcast the message and let the receivers to determine
	task void sendWarning()
	{
		uint16_t tmpAddr;
		CarCmdMsg * pReading = (CarCmdMsg *)gMsgBuffer.data;
		// increase num of cars passed by
		//carPassed++;
		dbg(DBG_USR2, "MSG_Warn: Number of cars passed: %d", carPassed);
		// Prepare to report
		if (carPassed >= MAX_SENSOR_NUM)
		{
			// Set the leftStatus for sending the report
			leftStatus = REPORT_PENDING;
			// Update the message
			pITSMsg -> numCarPassed = carPassed;
		}
		// Check if there is any sensor to warn:
		pendingMsg = call SensorInfo.sensorListSize();
		dbg(DBG_USR2, "MSG_Warn: num of sensors to warn: %d\n", pendingMsg);
		if (pendingMsg >0)
		{
			pReading->msgType = MSG_TYPE_WARN;
			tmpAddr = call SensorInfo.getSensor(pendingMsg-1);
			dbg(DBG_USR2, "MSG_Warn: sending warning to %d.\n", tmpAddr);
			call SendMsg.send(call SensorInfo.getSensor(pendingMsg-1), sizeof(CarCmdMsg), &gMsgBuffer);
			pendingMsg--;
		}
		// No warning, check if there is any need for reporting
		else if (carPassed >= MAX_SENSOR_NUM)
		{
			pITSMsg -> operationMode = OPER_SUMMARY_MSG;
			// Reset the number
			carPassed = 0;
			dbg(DBG_USR2, "MSG_Base: Reporting summary to base: %d\n",pITSMsg -> numCarPassed);
			call SendToBase.send(&gReportMsg, sizeof(ITSMsg));
		}
		else
			signal CarMaintainer.carLeftDone();
	}
	
	// Step 6
	task void sendNext()
	{
		uint16_t tmpAddr;
		if (pendingMsg>0)
		{
			tmpAddr=call SensorInfo.getSensor(pendingMsg-1);
			dbg(DBG_USR2, "MSG_Warn: sending warning to %d.\n", tmpAddr);
			call SendMsg.send(call SensorInfo.getSensor(pendingMsg-1), sizeof(CarCmdMsg), &gMsgBuffer);
			pendingMsg--;
		}
	}
	
	// Step 2
	task void recordCarLeftSTART()
	{


	}
	// Stop chirp
	event result_t ChirpTimer.fired() {
		call ChirpControl.stop();
		return SUCCESS;
	}

	task void receivedMsgTask ()
	{
		if ((call SensorInfo.getSensorType()!=SENSOR_TYPE_START) && (call SensorInfo.getSensorType()!=SENSOR_TYPE_ONLY))
			call ReaderControl.start();
		call Leds.redOn();
	}
	/*task void reportToBase()
	{
		uint8_t operCode;
		operCode = call SensorInfo.getOperCode();
		if (operCode%OPER_EVERY_MSG==0)
		{
			pITSMsg->operationMode=OPER_EVERY_MSG;
			pITSMsg->reading=lastReading;
			if (lastReading == SENSOR_UNCOVERED)
			{
				dbg(DBG_USR2, "MSG_Base: car left. Sending to base\n");
			}
			else if (lastReading == SENSOR_COVERED)
			{
				dbg(DBG_USR2, "MSG_Base: car reached. Sending to base\n");
			}
			else
			{
				dbg(DBG_USR2, "MSG_Base: Unknown information is being sent %d!\n", lastReading);
			}
			
			if (TOS_LOCAL_ADDRESS!=0)
			{
				call SendToBase.send(&gReportMsg, sizeof(ITSMsg));
			}
		}
	}*/
	static void checkCollision (tos_time_t *x)
	{
		uint32_t timeDiff;
		if (justLeft.endTime.low32!=0)
		{
			timeDiff=calcTimeDiff(x, &(justLeft.endTime));
			dbg(DBG_USR2, "Car: collision detection result: %d\n", timeDiff);
			if (timeDiff<1000)
			{
				call ChirpControl.start();
				call ChirpTimer.start(TIMER_ONE_SHOT, CHIRP_TIME);
			}
		}
	}
	
	static uint32_t calcTimeDiff (tos_time_t *t1, tos_time_t *t2)
	{
		tos_time_t resultTime = call TimeUtil.subtract(*t1, *t2);
		return (call TimeUtil.low32(resultTime));
	}

	static void carLeaving()
	{
		// Don't stop the sensor reader for the 'START/ONLY sensor
		if ((call SensorInfo.getSensorType()) != SENSOR_TYPE_START
			&& (call SensorInfo.getSensorType()) != SENSOR_TYPE_ONLY
			&& (call SensorInfo.getSensorType()) != SENSOR_TYPE_PARK
			&& queueSize(&expectCar)==0)
		{
#ifndef ALL_TIME_MSG
			call ReaderControl.stop();
#endif
		}
		if (queueSize(&expectCar)==0)
			call Leds.redOff();
	}
	event result_t SendToBase.sendDone(TOS_MsgPtr pMsg, result_t success) {
		dbg(DBG_USR2, "Car: finished sending server message, %d\n", success);
		if (leftStatus==REPORT_PENDING)
		{
			leftStatus = NO_PENDING;
			// Wait for 100 binary seconds
			call SendTimer.start(TIMER_ONE_SHOT, 50);
			dbg(DBG_USR2, "Sending and resetting leftStatus\n");
		}
		if (success!=SUCCESS)
			call Leds.greenToggle();
		return SUCCESS;
	}
	
	event result_t SendTimer.fired() {
		signal CarMaintainer.carLeftDone();
		return SUCCESS;
	}
	event result_t CollisionTimer.fired() {
		danger=FALSE;
		return SUCCESS;
	}
}
