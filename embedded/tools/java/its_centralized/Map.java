import java.util.*;

class Map implements ITSReceiver{
  private static boolean debug = false;
  public Dictionary <Integer, Car> cars;
  public Dictionary <Integer, Road> startRoads;
  public Dictionary <Integer, Road> endRoads;
  public ITSSender sender;

  static public String getDirString (int dir) {
    switch (dir) {
    case 0:
      return "right";
    case 1:
      return "straight";
    case 2:
      return "left";
    default:
      return "unknown";
    }
  }
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
          start.exitRoads.put(new Integer(y-3), exit);
          if (debug) {
            System.out.println("Connected road: " + Integer.toString(exit.startIC) + " - " + Integer.toString(exit.endIC) + " to " + getDirString(y-3) + " of road: " + Integer.toString(start.startIC) + " - " + Integer.toString(start.endIC));
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
  public Map (ITSSender sender) {
    this.sender = sender;
    this.cars = new Hashtable <Integer, Car> ();
    this.startRoads = new Hashtable <Integer, Road> ();
    this.endRoads = new Hashtable <Integer, Road> ();
    this.constructMap();
  }
  private void stopCar (Car car) {
    if (!car.stopped) {
      car.stopped = true;
      sender.setSpeed(car, 0);
    }
  }
  private void startCar (Car car) {
    if (car.stopped) {
      car.stopped = false;
      sender.setSpeed(car, car.speed);
    }
  }
  private void turnCar (Car car, Road road) {
    for (Enumeration<Integer> e = car.belongs.exitRoads.keys(); e.hasMoreElements();) {
      Integer turn = e.nextElement();
      if (car.belongs.exitRoads.get(turn) == road) {
        if (turn.intValue() == 1) // 1: straight - no need to turn
          sender.setDir(car, 0);
        else
          sender.setDir(car, 1);
     
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
    boolean tryToStartCar = false;
    if (car.status == Car.LEAVING) {
      if (car.belongs.cross != null) {
        // 1. Collision avoidance
	      if (!car.belongs.cross.waiting.contains(car) ) {
	        car.belongs.cross.waiting.add(car);
	      }
        if (car.belongs.cross.waiting.size() > 1 && !car.stopped) {
	        System.out.println(car.toString() + " is stopped to avoid collision");
          this.stopCar(car);
        } else if (car.belongs.cross.waiting.size() <= 1 && car.stopped) {
	        System.out.println(car.toString() + " is no longer in collision state, trying to start it ...");
          tryToStartCar = true;
	      }
      }
      if (tryToStartCar || !car.stopped) { // Before starting, need to make sure there is a valid exit
        Road exit = car.belongs.chooseExit();
        if (exit == null) { // All exit roads are full, stop the car
	        System.out.println(car.toString() + " is stopped because there is no exit available");
          this.stopCar(car);
        } else {
	        System.out.println(car.toString() + " is instructed to switch to " + exit.toString());
          this.startCar(car);
          this.turnCar(car, exit);
	      }
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
  public void receiveMsg (int carID, int dir, int pos, int speed) {
    Road start = this.startRoads.get(new Integer(pos));
    Road end = null;
    Car car = this.cars.get(new Integer(carID));
    if (start == null) {
      end = this.endRoads.get(new Integer(pos));
    }
    if (car == null) {
      car = new Car(carID, start==null?end:start);
      car.status = (start==null?Car.LEAVING:car.ENTERING);
      this.cars.put(new Integer(car.id), car);
    } else if (stateIsUnchanged(car, start, end)) {
      //System.out.println("Status is unchanged: " + car.toString());
      // Do nothing for now (may need to adjust speed later on)
      return;
    } else {
      if (start != null) { // Entering a new road
        car.switchTo(start);
        car.status = Car.ENTERING;
      } else { // Preparing to exit a road
        car.switchTo(end);
        car.status = Car.LEAVING;
      }
      System.out.println("Car: " + car);
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
