module LightInformM {
	provides {
		interface StdControl;
	} uses {
		interface Tracking;
		interface TrafficLightControl;
		interface SendMsg as SendTraffic;
		interface Leds;
	}
} implementation {
	TOS_Msg gMsgBuffer;
	TOS_MsgPtr msgBuffer;
	bool sending;

	command result_t StdControl.init() {
		msgBuffer=&gMsgBuffer;
		sending=FALSE;
		return SUCCESS;
	}
	command result_t StdControl.start() {
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
	event result_t Tracking.carUpdated (Car * currentCar, Car * previousCar) {
		uint8_t color, remain_t;
		if (!sending && currentCar!=NULL && currentCar->currentIntersection!=NULL
			&& currentCar->currentIntersection->id==senorID2InterID(TOS_LOCAL_ADDRESS)) {
			call Leds.greenToggle();
			call TrafficLightControl.get(carJunct2InterJunct(currentCar->junction), &color, &remain_t);
			// Unicast non-green, broadcast green
			if (color!=GREEN) {
				msgBuffer->data[0]=senorID2InterID(TOS_LOCAL_ADDRESS);
				msgBuffer->data[1]=currentCar->junction;
				msgBuffer->data[2]=color;
				msgBuffer->data[3]=remain_t;
				if ((call SendTraffic.send(currentCar->id, 4, msgBuffer))==SUCCESS)
					sending=TRUE;
			}
		}
		return SUCCESS;
	}
	event result_t TrafficLightControl.lightChanged (uint8_t junction, uint8_t color, uint8_t remain_t) {
		Intersection * inter;
		// Unicast non-green, broadcast green
		if (!sending && color==GREEN) {
			inter = call Tracking.getIntersectionByID(senorID2InterID(TOS_LOCAL_ADDRESS));
			if ((call Tracking.countCarsOnIntersection (inter, interJunct2CarJunct(junction)))>0) {
				msgBuffer->data[0]=senorID2InterID(TOS_LOCAL_ADDRESS);
				msgBuffer->data[1]=interJunct2CarJunct(junction);
				msgBuffer->data[2]=color;
				msgBuffer->data[3]=remain_t;
				if ((call SendTraffic.send(TOS_BCAST_ADDR, 4, msgBuffer))==SUCCESS)
					sending=TRUE;
			}
		}
		return SUCCESS;
	}
	event result_t SendTraffic.sendDone(TOS_MsgPtr msg, result_t success) {
		msgBuffer=msg;
		sending=FALSE;
		return SUCCESS;
	}
}
