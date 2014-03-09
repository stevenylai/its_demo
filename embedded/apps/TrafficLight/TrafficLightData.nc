#include "TrafficLight.h"

interface TrafficLightData {
  event TrafficLightMsg * receive(TrafficLightMsg *msg);
  command error_t send(TrafficLightMsg *msg);
  event void sendDone(TrafficLightMsg * msg, error_t err);
}
