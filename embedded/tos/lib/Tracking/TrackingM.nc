includes Tracking;

module TrackingM {
	provides {
		interface StdControl;
		interface Tracking;
	} uses {
		interface ReceiveMsg as ReceiveRelay;
		interface SendMsg as SendTest;
		interface Leds;
		interface CommControl;
		interface Timer;
	}
} implementation {
	TrackingMap trackingMap;
	Car lastRemoved;
	TOS_Msg sendBuffer;
	
	static Car * removeCar(uint8_t carID, uint8_t inter_id, uint8_t junction, uint8_t status) {
		uint8_t i, j, k;
		Car * returnCar=NULL;
		bool found=FALSE;
		// Remove from intersection
		for (i=0; i<TOTAL_INTERSECTIONS; i++) {
			for (j=0; j<MAX_QUEUES_PER_INTER; j++) {
				for (k=0; k<MAX_CARS_PER_INTER; k++) {
					if (trackingMap.intersections[i].cars[j][k]==NULL)
						break;
					else if (trackingMap.intersections[i].cars[j][k]->id==carID) {
						found=TRUE;
						break;
					}
				}
				if (found)
					break;
			}
			if (found) {
				lastRemoved=*(trackingMap.intersections[i].cars[j][k]);
				returnCar=&lastRemoved;
				for (k=k+1; k<MAX_CARS_PER_INTER; k++) {
					trackingMap.intersections[i].cars[j][k-1]=trackingMap.intersections[i].cars[j][k];
				}
				trackingMap.intersections[i].cars[j][k-1]=NULL;
				break;
			}
		}

		// Remove from road
		found=FALSE;
		for (i=0; i<TOTAL_ROADS; i++) {
			for (j=0; j<MAX_CARS_PER_ROAD; j++) {
				if (trackingMap.roads[i].cars[j]==NULL) {
					break;
				} else if (trackingMap.roads[i].cars[j]->id==carID) {
					found=TRUE;
					break;
				}
			}
			if (found) {
				lastRemoved=*(trackingMap.roads[i].cars[j]);
				returnCar=&lastRemoved;
				for (j=j+1; j<MAX_CARS_PER_ROAD; j++) {
					trackingMap.roads[i].cars[j-1]=trackingMap.roads[i].cars[j];
				}
				trackingMap.roads[i].cars[j-1]=NULL;
				break;
			}
		}

		return returnCar;
	}
	static Car * addCar(uint8_t carID, uint8_t inter_id, uint8_t junction, uint8_t status) {
		uint8_t i; 
		Car * addedCar=NULL;
		Road * targetRoad=NULL;
		Intersection * targetIntersection=NULL;

		// Find the car
		for (i=0; i<TOTAL_CARS; i++) {
			if (trackingMap.cars[i].id==INVALID_ID)
				break;
			else if (trackingMap.cars[i].id==carID)
				addedCar=&(trackingMap.cars[i]);
		}
		if (addedCar==NULL) {
			if (i<TOTAL_CARS) {
				addedCar=&(trackingMap.cars[i]);
			} else {
				// List overflowing
				addedCar=&(trackingMap.cars[0]);
			}
		}
		// Update info
		addedCar->id=carID;
		addedCar->inter_id=inter_id;
		addedCar->junction=junction;
		addedCar->status=status;
		addedCar->currentRoad=NULL;
		addedCar->currentIntersection=NULL;

		// Find the road
		if (status==CLISSIONSTATUS_FREE) {
			for (i=0; i<TOTAL_ROADS; i++) {
				 if (trackingMap.roads[i].start!=NULL &&
					trackingMap.roads[i].start->id==inter_id &&
					trackingMap.roads[i].startJunct==junction) {
					targetRoad=&(trackingMap.roads[i]);
					break;
				}
			}
		}
		// Add car to road
		if (targetRoad!=NULL) {
			for (i=0; i<MAX_CARS_PER_ROAD; i++) {
				if (targetRoad->cars[i]==NULL) {
					targetRoad->cars[i]=addedCar;
					break;
				}
			}
			// List overflowing
			if (i>=MAX_CARS_PER_ROAD) {
				targetRoad->cars[0]=addedCar;
			}
			addedCar->currentRoad=targetRoad;
		}

		// Find the intersection
		if (status==CLISSIONSTATUS_CLISSION) {
			targetIntersection=getIntersectionByID(inter_id, &trackingMap);
		}
		// Add car to intersection
		if (targetIntersection!=NULL && junction-1<MAX_QUEUES_PER_INTER) {
			dbg(DBG_USR2, "Adding to intersection: %d\n", targetIntersection->id);
			for (i=0; i<MAX_CARS_PER_INTER; i++) {
				if (targetIntersection->cars[junction-1][i]==NULL) {
					targetIntersection->cars[junction-1][i]=addedCar;
					break;
				}
			}
			// List overflowing
			if (i>=MAX_CARS_PER_INTER) {
				targetIntersection->cars[junction-1][0]=addedCar;
			}
			addedCar->currentIntersection=targetIntersection;
		}
		return addedCar;
	}
	static uint8_t countCars() {
		uint8_t total=0;
		for (; total<TOTAL_CARS; total++) {
			if (trackingMap.cars[total].id==INVALID_ID)
				break;
		}
		return total;
	}
	static uint8_t countCarsRoad(Road * r) {
		uint8_t total=0;
		if (r!=NULL) {
			for (; total<MAX_CARS_PER_ROAD; total++) {
				if (r->cars[total]==NULL)
					break;
			}
		}
		if (total>0) {
			//dbg(DBG_USR2, "%d cars found on road: %d, %d\n", total, r->start->id, r->end->id);
		}
		return total;
	}
	static uint8_t countCarsIntersection(Intersection * r, uint8_t d) {
		uint8_t total=0;
		if (r!=NULL && d-1<MAX_QUEUES_PER_INTER) {
			for (; total<MAX_CARS_PER_INTER; total++) {
				if (r->cars[d-1][total]==NULL)
					break;
			}
		}
		if (total>0) {
			//dbg(DBG_USR2, "%d cars found on inter: %d, %d\n", total, r->id, d);
		}
		return total;
	}
	static uint8_t countCarsMap() {
		uint8_t i, j, total=0;
		for (i=0; i<TOTAL_ROADS; i++) {
			if (trackingMap.roads[i].start!=NULL) {
				total=total+countCarsRoad(&(trackingMap.roads[i]));
			}
		}
		for (i=0; i<TOTAL_INTERSECTIONS; i++) {
			if (trackingMap.intersections[i].id!=INVALID_ID) {
				for (j=0; j<MAX_QUEUES_PER_INTER; j++)
					total=total+countCarsIntersection(&(trackingMap.intersections[i]), j+1);
			}
		}
		return total;
	}
	static uint8_t countAllCarsOnIntersection (uint8_t inter_id, uint8_t junction) {
		Intersection * inter=getIntersectionByID(inter_id, &trackingMap);
		uint8_t total=0;
		total=total+countCarsIntersection(inter, junction);
		if (inter->endRoads[junction-1]!=NULL)
			total=total+countCarsRoad(inter->endRoads[junction-1]);
		return total;
	}
	static void  dbgCar (Car * carAdded, Car * carRemoved) {
		if (carRemoved!=NULL) {
			dbg(DBG_USR2, "Prev: (ID: %d, pos: (%d, %d)) ", carRemoved->id, carRemoved->inter_id, carRemoved->junction);
			if (carRemoved->currentRoad!=NULL) {
				dbg_clear(DBG_USR2, "@road (%d, %d, %d, %d) [%d] ", carRemoved->currentRoad->start->id, carRemoved->currentRoad->startJunct, carRemoved->currentRoad->end->id, carRemoved->currentRoad->endJunct, countCarsRoad(carRemoved->currentRoad));
			}
			if (carRemoved->currentIntersection!=NULL) {
				dbg_clear(DBG_USR2, "@inter (%d) [%d] ", carRemoved->currentIntersection->id, countCarsIntersection(carRemoved->currentIntersection, carRemoved->junction));
			}
		} else {
			dbg(DBG_USR2, "Prev: NULL ");
		}

		dbg_clear(DBG_USR2, "|");

		if (carAdded!=NULL) {
			dbg_clear(DBG_USR2, "Curr: (ID: %d, pos: (%d, %d)) ", carAdded->id, carAdded->inter_id, carAdded->junction);
			if (carAdded->currentRoad!=NULL) {
				dbg_clear(DBG_USR2, "@road (%d, %d, %d, %d) [%d] ", carAdded->currentRoad->start->id, carAdded->currentRoad->startJunct, carAdded->currentRoad->end->id, carAdded->currentRoad->endJunct, countCarsRoad(carAdded->currentRoad));
			}
			if (carAdded->currentIntersection!=NULL) {
				dbg_clear(DBG_USR2, "@inter (%d) [%d] ", carAdded->currentIntersection->id, countCarsIntersection(carAdded->currentIntersection, carAdded->junction));
			}
		} else {
			dbg_clear(DBG_USR2, "Curr: NULL ");
		}

		dbg_clear(DBG_USR2, "|Total cars: %d", countCarsMap());

		dbg_clear(DBG_USR2, "\n");
	}
	static void dbgMsg() {
		sendBuffer.data[0]=countAllCarsOnIntersection(1, 1);
		sendBuffer.data[1]=countAllCarsOnIntersection(1, 2);
		sendBuffer.data[2]=countAllCarsOnIntersection(1, 3);
		sendBuffer.data[3]=countAllCarsOnIntersection(1, 4);
		dbg(DBG_USR2, "%d, %d, %d, %d\n", sendBuffer.data[0], sendBuffer.data[1], sendBuffer.data[2], sendBuffer.data[3]);
		//call SendTest.send(TOS_UART_ADDR, 4, &sendBuffer);
	}
	static void processCar(uint8_t carID, uint8_t inter_id, uint8_t junction, uint8_t status) {
		Car * removed, * added;
		removed = removeCar(carID, inter_id, junction, status);
		added = addCar(carID, inter_id, junction, status);
		dbgCar(added, removed);
		if (removed==NULL || added==NULL) {
			call Leds.greenToggle();
			dbgMsg();
			signal Tracking.carUpdated(added, removed);
		} else if (removed->id==added->id && removed->inter_id==added->inter_id &&
			removed->junction==added->junction && removed->status==added->status) {
			/* Do nothing */
		} else {
			call Leds.greenToggle();
			dbgMsg();
			signal Tracking.carUpdated(added, removed);
		}
	}
	event TOS_MsgPtr ReceiveRelay.receive(TOS_MsgPtr m) {
		processCar(m->data[0], m->data[1], m->data[2], m->data[4]);
		return m;
	}
	event result_t SendTest.sendDone(TOS_MsgPtr msg, result_t success) {
		return SUCCESS;
	}

	command Intersection * Tracking.getIntersectionByID(uint8_t inter_id) {
		return getIntersectionByID(inter_id, &trackingMap);
	}
	command uint8_t Tracking.countCarsOnRoad (Road * r) {
		return countCarsRoad(r);
	}
	command uint8_t Tracking.countCarsOnIntersection (Intersection * inter, uint8_t junction){
		return countCarsIntersection(inter, junction);
	}
	command uint8_t Tracking.countAllCarsOnIntersection (uint8_t inter_id, uint8_t junction) {
		return countAllCarsOnIntersection(inter_id, junction);
	}

	event result_t Timer.fired() {
		// For garbage collection purpose
		return SUCCESS;
	}
	command result_t StdControl.init() {
		initialMap(&trackingMap);
		return SUCCESS;
	}
	command result_t StdControl.start() {
		call CommControl.setPromiscuous(TRUE);
		/*processCar(1, 2, 1, CLISSIONSTATUS_FREE);
		processCar(1, 1, 3, CLISSIONSTATUS_CLISSION);
		processCar(1, 1, 1, CLISSIONSTATUS_FREE);
		processCar(2, 6, 1, CLISSIONSTATUS_CLISSION);
		processCar(1, 6, 3, CLISSIONSTATUS_FREE);
		processCar(3, 6, 1, CLISSIONSTATUS_CLISSION);
		processCar(1, 7, 3, CLISSIONSTATUS_FREE);*/
		dbg(DBG_USR2, "StdControl.start() finishing\n");
		return SUCCESS;
	}
	command result_t StdControl.stop() {
		return SUCCESS;
	}
}
