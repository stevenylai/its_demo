configuration TestBareUARTC {
} implementation {
  components TestBareUARTP, PlatformSerialC, LedsC, MainC;
  components SerialStartC;

  TestBareUARTP.Boot -> MainC;
  TestBareUARTP.Leds -> LedsC;
  TestBareUARTP.UartStream -> PlatformSerialC;
}
