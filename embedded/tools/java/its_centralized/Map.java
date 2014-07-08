import java.util.*;
import java.util.logging.*;

class Map implements CarReceiver, TrafficLightReceiver{
    private static Logger LOGGER = Logger.getLogger(Map.class.getName());
    private static boolean debug = false;
    public Dictionary <Integer, Car> cars;
    public Dictionary <Integer, TrafficLight> trafficLights;
    public Dictionary <Integer, Road> startRoads;
    public Dictionary <Integer, Road> endRoads;
    public MessageDispatcher dispatcher;
    public CarKeeper keeper;
    public ITSSender sender;
    public static final int SAFE_EXIT_INTERVAL = 3000;
    public static final int STOPPED_EXPIRY = 16000;
    public static final int CMD_RESEND_INTERVAL = 10000;

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
    protected void log(String message) {
        if (debug)
            System.out.print(message);
    }
    protected void logln(String message) {
        if (debug)
            System.out.println(message);
    }
    private void constructMap () {
        for (int x=0; x<MapInfo.roadInfo.size(); x++) { // Add all roads
            int [] roadInfo = MapInfo.roadInfo.get(x);
            Road road = new Road(roadInfo[0], roadInfo[1], roadInfo[2]);
	    if (roadInfo[9] > 0) {
		TrafficLight light = this.trafficLights.get(new Integer(roadInfo[9]));
		if (light == null) {
		    light = new TrafficLight(roadInfo[9], this.sender);
		    this.trafficLights.put(new Integer(roadInfo[9]), light);
		}
		road.setTrafficLight(light, roadInfo[10]);
	    }
            startRoads.put(new Integer(road.startIC), road);
            endRoads.put(new Integer(road.endIC), road);
            this.logln("Constructed road: " + Integer.toString(road.startIC) + " - " + Integer.toString(road.endIC));
        }
        for (int x=0; x<MapInfo.roadInfo.size(); x++) { // Connect all roads
            int [] roadInfo = MapInfo.roadInfo.get(x);
            Road start = startRoads.get(new Integer(roadInfo[0]));
            for (int y=3; y<3+3; y++) {
        	if (roadInfo[y]>=0) {
        	    Road exit = startRoads.get(new Integer(roadInfo[y]));
        	    start.exitRoads.put(new Integer(y-3), exit);
        	    this.logln("Connected road: " + Integer.toString(exit.startIC) + " - " + Integer.toString(exit.endIC) + " to " + getDirString(y-3) + " of road: " + Integer.toString(start.startIC) + " - " + Integer.toString(start.endIC));
        	}
            }

            if (start.cross == null) {
        	for (int y=6; y<6+3; y++) {
        	    if (roadInfo[y]>=0) {
        		if (start.cross == null) {
        		    start.cross = new CrossRoad();
        		    this.log("Creating cross road for roads: " + Integer.toString(start.startIC) + " - " + Integer.toString(start.endIC));
        		}
        		Road theOther = startRoads.get(new Integer(roadInfo[y]));
        		theOther.cross = start.cross;
        		this.log(" and " + Integer.toString(theOther.startIC) + " - " + Integer.toString(theOther.endIC));
        	    }
        	}
        	if (start.cross != null) {
        	    this.logln("");
        	}
            }

        }
    }
    public Map (ITSSender sender) {
        this.sender = sender;
        this.cars = new Hashtable <Integer, Car> ();
	this.trafficLights = new Hashtable <Integer, TrafficLight> ();
        this.startRoads = new Hashtable <Integer, Road> ();
        this.endRoads = new Hashtable <Integer, Road> ();
        this.keeper = new CarKeeper();
        this.dispatcher = new MessageDispatcher(this);
        Thread dispatcherThread = new Thread(this.dispatcher);
        dispatcherThread.start();
        this.constructMap();
    }

    private void checkStoppedCars(Car excluding) {
        for (Enumeration<Car> e = this.cars.elements(); e.hasMoreElements();) {
            Car car = e.nextElement();
            if (!car.stopped || this.dispatcher.hasCar(car) || excluding == car)
        	continue;
            this.checkCar(car);
        }
    }
    private String intersectionCarString(CrossRoad cross) {
	String msg = "";
        for (Car car : cross.waiting) {
	    msg += car.id + " ";
        }
	return msg;
    }
    private void checkCar (Car car) {
        boolean tryToStartCar = false;
        Date current = new Date();
        if (car.status == Car.LEAVING || car.status == Car.TRANSIT) {
	    if (car.belongs.trafficLight != null && car.belongs.trafficLight.isInEffect()) { // Traffic light control
		if (car.belongs.checkTrafficLight())
		    tryToStartCar = true;
		else {
		    if (!car.stopped) {
			Map.LOGGER.config("Stopping car: " + car + " for traffic light.");
			car.stop();
		    }
		}
            } else if (car.belongs.cross != null) {
        	if (car.status == Car.TRANSIT)
        	    tryToStartCar = true;
        	else if (!car.belongs.cross.waiting.contains(car)) // Collision avoidance
        	    car.belongs.cross.waiting.add(car);

        	if (car.status == Car.TRANSIT)
        	    /* Nothing */;
        	else if (car.belongs.cross.waiting.get(0) != car && car.belongs.cross.waiting.size() > 1) {
		    String intersectionInfo = "";
        	    if (!car.stopped) {
        		car.stop();
			intersectionInfo += car.toString() +
			    " is stopped to avoid collision, intersection wait queue: ";
        	    } else {
			intersectionInfo += car.toString() +
			    " cannot start because intersection is still busy: ";
        	    }
        	    intersectionInfo += this.intersectionCarString(car.belongs.cross);
		    Map.LOGGER.config(intersectionInfo);
        	} else if ((car.belongs.cross.waiting.get(0) == car || car.belongs.cross.waiting.size() <= 1) && car.stopped) {
        	    Map.LOGGER.config(car.toString() + " is no longer in collision state, trying to start it ...");
        	    tryToStartCar = true;
        	}
            } else // If no cross road, just try start the car
        	tryToStartCar = true;

            if (tryToStartCar || !car.stopped) { // Before starting, need to make sure there is a valid exit
		if (!car.exitPrepared())// Get an exit if none yet
		    car.prepareExit(true);

		if (car.to == null || car.to.capacity <= car.to.cars.size()) {
        	    Map.LOGGER.config(car.toString() + " is stopped because there is no exit available");
        	    car.stop();
		} else if (current.getTime() - car.belongs.lastExit.getTime() < Map.SAFE_EXIT_INTERVAL) {
        	    Map.LOGGER.config(car.toString() + " is running too close to the previous car. Trying to pause it");
        	    car.stop();
        	    this.dispatcher.addCar(car, current, car.to);
		} else {
		    Map.LOGGER.config(car + " exit (pre:" +
				      car.belongs.lastExit + ") to " + car.to);
        	    if (car.stopped) {
        		car.start();
        		car.belongs.lastExit = current;
        		//this.dispatcher.addCar(car, current, exit);
        	    } else {
        		car.start();
        		car.belongs.lastExit = current;
        	    }
		}
            }
        }
	if (car.status == Car.ENTERING)
	    car.prepareExit(false);
	else if (car.status == Car.TRANSIT && !car.stopped) {
	    car.switchTo(car.to, car.belongs.endIC);
	    car.prepareExit(false);
	}
    }
    private boolean stateIsUnchanged (Car car, Road in, Road out) {
        if (car.status == Car.ENTERING && car.belongs == in) {
            return true;
        } else if (car.status == Car.LEAVING && car.belongs == out) {
            return true;
        } else if (car.status == Car.TRANSIT && car.belongs == out) {
            return true;
        } else {
            return false;
        }
    }
    private void dumpCarList() {
        String carList = "Current known cars: [";
        for (Enumeration<Car> e = this.cars.elements(); e.hasMoreElements();) {
            Car known_car = e.nextElement();
            carList += known_car.id + " ";
        }
        carList += "]";
	Map.LOGGER.info(carList);
    }
    public synchronized void checkInactiveCars() {
        List<Integer> toBeRemoved = new ArrayList<Integer>();
        for (Enumeration<Car> e = this.cars.elements(); e.hasMoreElements();) {
            Car car = e.nextElement();
            if (this.dispatcher.hasCar(car))
        	continue;
            Date current = new Date();
            if (current.getTime() - car.freshness.getTime() > Map.STOPPED_EXPIRY) {
        	Map.LOGGER.config("Car " + car.id + " has not sent any messages for over " + Map.STOPPED_EXPIRY + " ms. Removing it");
        	car.remove();
        	toBeRemoved.add(new Integer(car.id));
            }
        }
        if (toBeRemoved.size() > 0) {
            for (int id : toBeRemoved)
        	this.cars.remove(id);
            this.checkStoppedCars(null);
            this.dumpCarList();
        }
    }
    public synchronized void receiveTrafficLight (int id, int dir, int color, int remain) {
	TrafficLight light = this.trafficLights.get(new Integer(id));
	if (light != null) {
	    boolean changed = light.updateInfo(dir, color, remain);
	    if (changed) {
		Car car = light.getFirstCar(dir);
		if (car != null && car.stopped && light.getColor(dir) == TrafficLight.LIGHT_GREEN) {
		    Map.LOGGER.config("Traffic light changed to green, checking car: " + car);
		    this.checkCar(car);
		}
	    }
	} else
	    Map.LOGGER.warning("Unknown traffic light id: " + id);
    }
    public synchronized void receiveCar (int carID, int dir, int pos, int speed) {
	Date receivedDate = new Date();
        Road start = this.startRoads.get(new Integer(pos));
        Road end = this.endRoads.get(new Integer(pos));
        Car car = this.cars.get(new Integer(carID));
        	
        if (start == null && end == null) {
            if (pos == 0)
        	Map.LOGGER.info("Waiting for data for car: " + carID);
            else
        	Map.LOGGER.warning("Invalid pos: " + pos + " reported from car: " + carID);
            return;
        }
        if (car == null) {
            car = new Car(carID, this.sender, start==null?end:start);
            if (start == null)
        	car.status = Car.LEAVING;
            else if (end == null)
        	car.status = Car.ENTERING;
            else
        	car.status = Car.TRANSIT;
            this.cars.put(new Integer(car.id), car);
            car.switchTo(start==null?end:start, pos);
            Map.LOGGER.info("Car: " + carID + " has been added.");
            this.dumpCarList();
        } else if (stateIsUnchanged(car, start, end)) {
            car.freshness = new Date();
            if (car.freshness.getTime() - car.lastControl.getTime() > Map.CMD_RESEND_INTERVAL) {
        	// Re-send control command in case the car fail to start for whatever reason
        	if (speed == 0 && !car.stopped && !this.dispatcher.hasCar(car)) {
        	    Map.LOGGER.config("Resend control message to car: " + car.id);
        	    car.setSpeed(car.speed);
        	    car.lastControl = new Date();
        	}
            }
            return;
        } else {
            car.freshness = receivedDate;
	    car.updateReceived(receivedDate);
            this.dispatcher.removeCar(car);
            if (start == null) { // Preparing to exit a road
        	car.switchTo(end, pos);
        	car.status = Car.LEAVING;
            } else if (end == null) { // Entering a new road
        	car.switchTo(start, pos);
        	car.status = Car.ENTERING;
            } else {
        	car.switchTo(end, pos);
        	car.status = Car.TRANSIT;
            }
            Map.LOGGER.config(car.toString());
        }
        this.checkCar(car);
        this.checkStoppedCars(car);
        this.keeper.checkInactiveCar(this.cars, this.dispatcher);
    }
    // For testing if the roads are constructed and connected correctly
    public static void main(String[] args) throws Exception {
        debug = true;
        Map m = new Map(null);
    }
}
