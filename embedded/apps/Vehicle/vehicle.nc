//#define ENABLE_ACK
includes Definition;
includes CommAck;

configuration vehicle
{
}
implementation
{
	components Main, vehicleM, TimerC, LedsC as LedsC;
	components GenericComm as RadioComm;
	components HPLUARTC as UartComm;
	components CC2420RadioM;
#ifdef ENABLE_ACK
	components CommAckC, vehicleACKM;
#endif
	
	Main.StdControl -> vehicleM;
	Main.StdControl -> TimerC.StdControl;
	
	vehicleM.CommControl -> RadioComm.Control;
	vehicleM.Leds -> LedsC.Leds;
	
	vehicleM.SendResultMsg -> RadioComm.SendMsg[AM_ITSMSG];
	vehicleM.ReceiveTestMsg -> RadioComm.ReceiveMsg[AM_ITSMSG];

#ifdef ENABLE_ACK
	Main.StdControl -> CommAckC.StdControl;
	CommAckC.SendNormal -> RadioComm.SendMsg[AM_MSGACK];
	CommAckC.ReceiveNormal -> RadioComm.ReceiveMsg[AM_MSGACK];

	vehicleM.ReceiveTrafficMsg -> CommAckC.ReceiveMsg[2];
	vehicleACKM.PacketControlTraffic->CommAckC.PacketReceiveControl[2];
#else
	vehicleM.ReceiveTrafficMsg -> RadioComm.ReceiveMsg[2];
#endif
	vehicleM.MacControl -> CC2420RadioM;
	vehicleM.SendWarnMsg -> RadioComm.SendMsg[AM_ITSWARNMSG];
	vehicleM.SendStasMsg -> RadioComm.SendMsg[AM_ITSMSG];
	vehicleM.ReceiveStasMsg -> RadioComm.ReceiveMsg[AM_ITSSTATISTICSMSG];
	
	vehicleM.UART -> UartComm.UART;
	
	vehicleM.Timer -> TimerC.Timer[unique("Timer")];
	vehicleM.mtimer -> TimerC.Timer[unique("Timer")];
}

