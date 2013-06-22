import java.util.*;

class Map {
  private static boolean debug = false;
  public Dictionary <Integer, Car> cars;
  public Dictionary <Integer, Road> startRoads;
  public Dictionary <Integer, Road> endRoads;
  public Packet packet;

  private void constructMap () {
    for (int x=0; x<MapInfo.roadInfo.size(); x++) { // Add all roads
      int [] roadInfo = MapInfo.roadInfo.get(x);
      Road road = new Road(roadInfo[0], roadInfo[1], roadInfo[2]);
      startRoads.put(new Integer(road.startIC), road);
      endRoads.put(new Integer(road.endIC), road);
      if (debug)
        System.out.println("Constructed road: " + Integer.toString(road.startIC) + " - " + Integer.toString(road.endIC));
    }
    for (int x=0; x<MapInfo.roadInfo.size(); x++) { // Connect all roads
      int [] roadInfo = MapInfo.roadInfo.get(x);
      Road start = startRoads.get(new Integer(roadInfo[0]));
      for (int y=3; y<3+3; y++) {
        if (roadInfo[y]>=0) {
          Road exit = startRoads.get(new Integer(roadInfo[y]));
          start.exitRoads.put(new Integer(roadInfo[y]), exit);
          if (debug) {
            String direction = "None";
            if (y==3)
              direction = "right";
            else if (y==4)
              direction = "straight";
            else
               direction = "left";
            System.out.println("Connected road: " + Integer.toString(exit.startIC) + " - " + Integer.toString(exit.endIC) + " to " + direction + " of road: " + Integer.toString(start.startIC) + " - " + Integer.toString(start.endIC));
          }
        }
      }

      if (start.cross == null) {
        for (int y=6; y<6+3; y++) {
          if (roadInfo[y]>=0) {
            if (start.cross == null) {
              start.cross = new CrossRoad();
              if (debug) {
                System.out.print("Creating cross road for roads: " + Integer.toString(start.startIC) + " - " + Integer.toString(start.endIC));
              }
            }
            Road theOther = startRoads.get(new Integer(roadInfo[y]));
            theOther.cross = start.cross;
            if (debug)
              System.out.print(" and " + Integer.toString(theOther.startIC) + " - " + Integer.toString(theOther.endIC));
          }
        }
        if (debug && start.cross != null) {
          System.out.println("");
        }
      }

    }
  }
  public Map (Packet packet) {
    this.packet = packet;
    this.cars = new Hashtable <Integer, Car> ();
    this.startRoads = new Hashtable <Integer, Road> ();
    this.endRoads = new Hashtable <Integer, Road> ();
    this.constructMap();
  }
  private void stopCar (Car car) {
    // TODO: Send command to stop the car
  }
  private void turnCar (Car car, Road road) {
    for (Enumeration<Integer> e = car.belongs.exitRoads.keys(); e.hasMoreElements();) {
      Integer turn = e.nextElement();
      if (car.belongs.exitRoads.get(turn) == road) {
        // TODO: Send command to turn the car
      }
    }
  }
  private void checkStoppedCars() {
    for (Enumeration<Car> e = this.cars.elements(); e.hasMoreElements();) {
      Car car = e.nextElement();
      if (!car.stopped)
         continue;
      this.checkCar(car);
    }
  }
  private void checkCar (Car car) {
    if (car.status == Car.LEAVING) {
      if (car.belongs.cross != null) {
        // 1. Collision avoidance
        car.belongs.cross.waiting.add(car);
        if (car.belongs.cross.waiting.size() > 1) {
          car.stopped = true;
          this.stopCar(car);
        }
      }
      if (!car.stopped) { // Not stopped, need to choose exit
        Road exit = car.belongs.chooseExit();
        if (exit == null) { // All exit roads are full, stop the car
          car.stopped = true;
          this.stopCar(car);
        } else
          this.turnCar(car, exit);
      }
    } else {
      // Not doing anything for now but we may need to adjust the car's speed here in the future
    }
  }
  private boolean stateIsUnchanged (Car car, Road in, Road out) {
    if (car.status == Car.ENTERING && car.belongs == in) {
      return true;
    } else if (car.status == Car.LEAVING && car.belongs == out) {
      return true;
    } else {
      return false;
    }
  }
  public void update (int carID, int dir, int pos, int speed) {
    Road start = this.startRoads.get(new Integer(pos));
    Road end = null;
    Car car = this.cars.get(new Integer(carID));
    if (start == null) {
      end = this.endRoads.get(new Integer(pos));
    }
    if (car == null) {
      car = new Car(carID, start==null?end:start);
      car.status = (start==null?Car.LEAVING:car.ENTERING);
    } else if (stateIsUnchanged(car, start, end)) {
      // Do nothing for now (may need to adjust speed later on)
      return;
    } else {
      if (start != null) { // Entering a new road
        car.switchTo(start);
        car.status = Car.ENTERING;
      } else { // Preparing to exit a road
        car.status = Car.LEAVING;
      }
    }
    this.checkCar(car);
    this.checkStoppedCars();
  }
  // For testing if the roads are constructed and connected correctly
  public static void main(String[] args) throws Exception {
     debug = true;
     Map m = new Map(null);
  }
}
