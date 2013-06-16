import java.util.*;

class Road {
  public int startIC;
  public int endIC;
  public int capacity;
  public ArrayList <Vehicle> cars;
  public Dictionary <int, Road> startIntersection;
  public Dictionary <int, Road> endIntersection;
  public Road () {
    this.cars = new ArrayList<Vehicle>();
    this.startIntersection = new Dictionary <int, Road>();
    this.endIntersection = new Dictionary <int, Road>();
  }
}
