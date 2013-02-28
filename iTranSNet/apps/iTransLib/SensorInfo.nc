includes ITSCmd;

interface SensorInfo
{
	command uint8_t getSensorType();
	command uint8_t getOperCode();
	command struct Sensor * getNextSensor(uint16_t distOffset, uint16_t speed);
	command uint8_t sensorListSize();
	command uint16_t getSensor (uint8_t idx);
}
