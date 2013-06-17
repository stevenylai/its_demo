import java.util.*;

class Map {
  public Dictionary <Integer, Car> cars;
  public Dictionary <Integer, Road> startRoads;
  public Dictionary <Integer, Road> endRoads;
  public Packet packet;

  private void constructMap () {
    for (int x=0; x<MapInfo.roadInfo.size(); x++) {
    }
  }
  public Map (Packet packet) {
    this.packet = packet;
    this.cars = new Hashtable <Integer, Car> ();
    this.startRoads = new Hashtable <Integer, Road> ();
    this.endRoads = new Hashtable <Integer, Road> ();
    this.constructMap();
  }
  private void checkCars (Car car) {
  }
  public void update (int carID, int dir, int pos, int speed) {
    Road road = this.startRoads.get(Integer(pos));
    Car car = this.cars.get(Integer(carID));
    if (road == null) {
      // Log an error 
      return;
    }
    if (car == null) {
      car = new Car(carID, road);
    }
    this.checkCars(car);
  }
}
