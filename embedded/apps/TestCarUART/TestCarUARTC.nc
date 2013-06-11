includes TestCarUART;
configuration TestCarUARTC {
} implementation {
	components Main, HPLUARTC as UartComm, GenericComm as RadioComm,
		LedsC,
		TestCarUARTM;

	Main.StdControl->TestCarUARTM;
	Main.StdControl->RadioComm;

	TestCarUARTM.UART->UartComm.UART;
	TestCarUARTM.Leds->LedsC.Leds;
	TestCarUARTM.ReceiveMsg->RadioComm.ReceiveMsg[1];
}
