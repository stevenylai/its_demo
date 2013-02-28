includes Tracking;

interface Tracking {
	event result_t carUpdated (Car * currentCar, Car * previousCar);
	command Intersection * getIntersectionByID(uint8_t inter_id);
	//command uint8_t getRoadID(Car * currentCar);
	command uint8_t countCarsOnRoad (Road * r);
	command uint8_t countCarsOnIntersection (Intersection * inter, uint8_t junction);
	command uint8_t countAllCarsOnIntersection (uint8_t inter_id, uint8_t junction);
}
