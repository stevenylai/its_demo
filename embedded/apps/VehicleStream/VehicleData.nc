#include "Vehicle.h"
interface VehicleData {
  event VehicleMsg * receive(VehicleMsg *msg);
  command error_t send(VehicleMsg *msg);
  event sendDone(VehicleMsg * msg, error_t err);
}
