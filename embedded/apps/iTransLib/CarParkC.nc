configuration CarParkC
{
	provides {
		interface StdControl;
		interface CarPark;
	}
}
implementation {
	components GenericCommPromiscuous as Comm,
		CarParkM;

	StdControl = CarParkM;
	CarPark = CarParkM;

	CarParkM.ReceiveControlMsg -> Comm.ReceiveMsg[AM_SENSORCONTROLMSG];
}
