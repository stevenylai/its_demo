#include <Timer.h>
#include "Vehicle.h"

module VehicleC {
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;

  uses interface Packet as RadioPacket;
  uses interface AMSend as RadioSend;
  uses interface Receive as RadioReceive;
  uses interface PacketAcknowledgements as RadioAckowledgement;
  uses interface SplitControl as RadioSplitControl;
} implementation {

  message_t pkt;
  bool radio_busy = FALSE;
  uint16_t counter;

  event void Boot.booted() {
    radio_busy = FALSE;
    counter = 0;
    call RadioSplitControl.start();
    call Timer0.startPeriodic(512);
  }

  event void RadioSplitControl.startDone(error_t err) {
    if (err) {
    	call RadioSplitControl.start();
    }
  }
  event void RadioSplitControl.stopDone(error_t err) {
  }

  task void radioSendTask() {
    call RadioAckowledgement.requestAck(&pkt);
    if (call RadioSend.send(0, &pkt, sizeof(MoteToBaseMsg)) == SUCCESS) {
      atomic radio_busy = TRUE;
    } else {
      post radioSendTask();
    }
  }
  event void Timer0.fired() {
    counter++;
    atomic
    if (!radio_busy) {
      MoteToBaseMsg* ppkt = (MoteToBaseMsg*)(call RadioPacket.getPayload(&pkt, sizeof(MoteToBaseMsg)));
      if (ppkt == NULL) {
	      return;
      }
      ppkt->nodeid = TOS_NODE_ID;
      ppkt->dir = 0x02;
      ppkt->icnum = 51;
      ppkt->speed = counter;
      post radioSendTask();
    }
  }

  event void RadioSend.sendDone(message_t* msg, error_t err) {
    if(!err && call RadioAckowledgement.wasAcked(msg)) {
      atomic radio_busy = FALSE;
    } else {
      post radioSendTask();
      call Leds.led0Toggle();
    }
  }

  event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len){
    if (len != sizeof(BaseToMoteMsg)) {
	    return msg;
    } else {
      BaseToMoteMsg* ppkt = (BaseToMoteMsg*)payload;
      call Leds.set(ppkt -> nodeid);
      if (radio_busy) {
        return msg;
      } else {
	      // Send to serial
      }
    }
    return msg;
  }
}
