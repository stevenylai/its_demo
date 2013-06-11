interface TrafficLightControl {
	command result_t get (uint8_t id, uint8_t * color, uint8_t * remain_t);
	event result_t lightChanged (uint8_t inter_id, uint8_t color, uint8_t remain_t);
}
