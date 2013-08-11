import java.util.*;

class Road {
  public int startIC;
  public int endIC;
  public int capacity;
  public List <Car> cars;
  public Dictionary <Integer, Road> exitRoads;
  public CrossRoad cross;
  public Road (int startIC, int endIC, int capacity) {
    this.startIC = startIC;
    this.endIC = endIC;
    this.capacity = capacity;
    this.cars = new ArrayList<Car>();
    this.exitRoads = new Hashtable <Integer, Road>();
  }
  public Road chooseExit () {
    List<Road> avail = new ArrayList<Road>();
    for (Enumeration<Road> e = this.exitRoads.elements(); e.hasMoreElements();) {
      Road candidate = e.nextElement();
      if (candidate.capacity > candidate.cars.size()) {
        //System.out.println("Capacity of " + this + ": " + candidate.capacity + ", currently used: " + candidate.cars.size());
        avail.add(candidate);
      }
    }
    if (avail.size() > 0) {
      Random rand = new Random();
      return avail.get(rand.nextInt(avail.size()));
    } else
      return null;
  }
  public String toString() {
    return "Road: " + Integer.toString(this.startIC) + ", " + Integer.toString(this.endIC);
  }
}
