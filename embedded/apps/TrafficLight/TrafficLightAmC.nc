configuration TrafficLightAmC {
  provides {
    interface Packet;
    interface AMPacket;

    interface SplitControl;
    interface Receive[am_id_t id];
    interface AMSend[am_id_t id];
  }
} implementation {
  components TrafficLightAmP, ActiveMessageAddressC, SerialActiveMessageC as Serial;
  components SerialStartC;
  components TrafficLightDataC;
  //components LedsC;
  components NoLedsC as LedsC;

  SplitControl = TrafficLightAmP;
  SplitControl = TrafficLightDataC;
  SplitControl = Serial;
  Receive = TrafficLightAmP;
  AMSend = TrafficLightAmP;

  Packet = Serial;
  AMPacket = Serial;

  TrafficLightAmP.Leds -> LedsC;
  TrafficLightAmP.SerialPacket -> Serial;
  TrafficLightAmP.SerialAMPacket -> Serial;
  TrafficLightAmP.ActiveMessageAddress -> ActiveMessageAddressC;
  TrafficLightAmP.TrafficLightData -> TrafficLightDataC;
}
