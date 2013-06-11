#include <Timer.h>
#include "Vehicle.h"

module VehicleBaseC {
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;

  uses interface Packet as RadioPacket;
  uses interface AMPacket as RadioAMPacket;
  uses interface AMSend as RadioAMSend;
  uses interface Receive as RadioReceive;
  uses interface SplitControl as RadioAMControl;

  uses interface Packet as SerialPacket;
  uses interface AMPacket as SerialAMPacket;
  uses interface AMSend as SerialAMSend;
  uses interface Receive as SerialReceive;
  uses interface SplitControl as SerialAMControl;
}
implementation {

  message_t rpkt;
  message_t spkt;
  message_t pkt;
  bool locked = FALSE;
  bool busy = FALSE;
  bool pbusy = FALSE;
  uint16_t counter;


  void setLeds(uint16_t val) {
    if (val & 0x01)
      call Leds.led0On();
    else 
      call Leds.led0Off();
    if (val & 0x02)
      call Leds.led1On();
    else
      call Leds.led1Off();
    if (val & 0x04)
      call Leds.led2On();
    else
      call Leds.led2Off();
  }

  event void Boot.booted() {
    call RadioAMControl.start();
    call SerialAMControl.start();
  }

  event void RadioAMControl.startDone(error_t err) {
    if (err == SUCCESS) {
      //call Timer0.startPeriodic(TIMER_PERIOD_MILLI);
    }
    else {
      call RadioAMControl.start();
    }
  }

  event void RadioAMControl.stopDone(error_t err) {
  }

  event void SerialAMControl.startDone(error_t err) {
    if (err == SUCCESS) {
    }
    else {
      call SerialAMControl.start();
    }
  }

  event void SerialAMControl.stopDone(error_t err) {
  }

  event void Timer0.fired() {
    counter++;
    if (!pbusy) {
      BaseToMoteMsg* btrpkt = 
	(BaseToMoteMsg*)(call RadioPacket.getPayload(&pkt, sizeof(BaseToMoteMsg)));
      if (btrpkt == NULL) {
	return;
      }
      btrpkt->nodeid = TOS_NODE_ID;
      btrpkt->cmd = 0x02;
      btrpkt->data = counter;
      if (call RadioAMSend.send(AM_BROADCAST_ADDR, 
          &pkt, sizeof(BaseToMoteMsg)) == SUCCESS) {
        pbusy = TRUE;
      }
    }
  }

  event void RadioAMSend.sendDone(message_t* msg, error_t err) {
    if (&pkt == msg) {
      pbusy = FALSE;
      setLeds(counter);
    }
    else if (&rpkt == msg) {
      locked = FALSE;
    }
  }

  event void SerialAMSend.sendDone(message_t* msg, error_t err) {
    if (&spkt == msg) {
      busy = FALSE;
    }
  }

  /*event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len){
    if (len == sizeof(MoteToBaseMsg)) {
      MoteToBaseMsg* btrpkt = (MoteToBaseMsg*)payload;
      setLeds(btrpkt->speed);
    }
    return msg;
  }*/

  event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len){
    if (len != sizeof(MoteToBaseMsg)) {
	return msg;
    }
    else {
      MoteToBaseMsg* btrpkt = (MoteToBaseMsg*)payload;
      if (busy) {
          return msg;
      }
      else {
      	MoteToBaseMsg* mvm = (MoteToBaseMsg*)
		call SerialPacket.getPayload(&spkt, sizeof(MoteToBaseMsg));
      	if (mvm == NULL) {return msg;}
      	if (call SerialPacket.maxPayloadLength() < sizeof(MoteToBaseMsg)) {
		return msg;
        }
        mvm -> nodeid = btrpkt -> nodeid;
        setLeds(btrpkt->speed);
      	mvm -> dir = btrpkt -> dir;
	mvm -> icnum = btrpkt -> icnum;
	mvm -> speed = btrpkt -> speed;
      	if (call SerialAMSend.send(AM_BROADCAST_ADDR, &spkt, sizeof(MoteToBaseMsg)) == SUCCESS) {
		busy = TRUE;
      	}
      }
    }
    return msg;
  }

  event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len){
    if (len != sizeof(BaseToMoteMsg)) {
	return msg;
    }
    else {
      BaseToMoteMsg* vmm = (BaseToMoteMsg*)payload;
      if (!locked) {
              BaseToMoteMsg* mbm = (BaseToMoteMsg*)call RadioPacket.getPayload(&rpkt, sizeof(BaseToMoteMsg));
	      mbm->nodeid = TOS_NODE_ID;
	      mbm->cmd = vmm->cmd;
	      //mbm->icnum = vmm->IC_NO;
	      mbm->data = vmm->data;
	      setLeds(vmm->data);
	      if (call RadioAMSend.send(vmm -> nodeid, 
	          &rpkt, sizeof(BaseToMoteMsg)) == SUCCESS) {
	         locked = TRUE;
		 
      	      }
      }
    }
    return msg;
  }
}
