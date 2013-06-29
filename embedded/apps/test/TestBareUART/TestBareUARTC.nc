configuration TestBareUARTC {
} implementation {
  components TestBareUARTP, PlatformSerialC, LedsC, MainC;
  components new TimerMilliC();
  components SerialStartC;

  TestBareUARTP.Boot -> MainC;
  TestBareUARTP.Leds -> LedsC;
  TestBareUARTP.UartStream -> PlatformSerialC;
  TestBareUARTP.MilliTimer -> TimerMilliC;
}
