import java.util.*;

class Road {
  public int startIC;
  public int endIC;
  public int capacity;
  public List <Car> cars;
  public Dictionary <Integer, Road> exitRoads;
  public Road () {
    this.cars = new ArrayList<Car>();
    this.exitRoads = new Hashtable <Integer, Road>();
  }
}
