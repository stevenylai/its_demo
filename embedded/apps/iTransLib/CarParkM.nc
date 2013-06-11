includes ITSCmd;

module CarParkM
{
	provides
	{
		interface StdControl;
		interface CarPark;
	}
	uses
	{
		interface ReceiveMsg as ReceiveControlMsg;
	}
}
implementation
{
	bool available;

	command result_t StdControl.init() {
		atomic available=FALSE;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}

	event TOS_MsgPtr ReceiveControlMsg.receive(TOS_MsgPtr m) {
		SensorControlMsg * pReading = (SensorControlMsg *)m->data;

		if (pReading->sensorID==TOS_LOCAL_ADDRESS
			&& pReading->sensorType==SENSOR_TYPE_CAR)
		{
			if (pReading->operationMode==OPER_OCCUPIED)
				atomic available=FALSE;
			else if (pReading->operationMode==OPER_UNOCCUPIED)
				atomic available=TRUE;
		}
		return m;
	}

	command bool CarPark.checkAvail() {
		return available;
	}
}
