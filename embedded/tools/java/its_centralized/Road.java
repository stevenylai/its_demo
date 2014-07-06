import java.util.*;
import java.util.logging.*;

class Road {
    public int startIC;
    public int endIC;
    public int capacity;
    public Date lastExit;
    public List <Car> cars;
    public List <Car> planned;
    public Dictionary <Integer, Road> exitRoads;
    public CrossRoad cross;
    public TrafficLight trafficLight;
    public int trafficLightDir;
    static private Logger LOGGER = Logger.getLogger(Road.class.getName());

    public Road (int startIC, int endIC, int capacity) {
	this.startIC = startIC;
	this.endIC = endIC;
	this.capacity = capacity;
	this.trafficLight = null;
	this.lastExit = new Date();
	this.cars = new ArrayList<Car>();
	this.planned = new ArrayList<Car>();
	this.exitRoads = new Hashtable <Integer, Road>();
    }
    public void setTrafficLight (TrafficLight light, int dir) {
	this.trafficLight = light;
	this.trafficLightDir = dir;
	light.addRoad(dir, this);
    }
    public boolean checkTrafficLight() {
	if (this.trafficLight == null)
	    return true;
	else {
	    Road.LOGGER.config("Current traffic light color: " + TrafficLight.colorString(this.trafficLight.getColor(this.trafficLightDir)));
	    /*
	    if (this.trafficLight.askPass(this.trafficLightDir))
		return true;
	    else
		return false;
	    */

	    if (this.trafficLight.getColor(this.trafficLightDir) == TrafficLight.LIGHT_GREEN)
		return true;
	    else {
		this.trafficLight.askPass(this.trafficLightDir);
		return false;
	    }
	}
    }
    public Road chooseExit (boolean allowNull) {
	Road best = null;
	List<Road> avail = new ArrayList<Road>();
	for (Enumeration<Road> e = this.exitRoads.elements(); e.hasMoreElements();) {
	    Road candidate = e.nextElement();
	    if (candidate.capacity > candidate.cars.size()) {
		//Road.LOGGER.config("Capacity of " + candidate + ": " + candidate.capacity + ", currently used: " + candidate.cars.size() + ": " + candidate.cars);
		avail.add(candidate);
	    } else if (best == null || (candidate.cars.size() - candidate.capacity) < (best.cars.size() - best.capacity)) {
		best = candidate;
	    }
	}
	if (avail.size() > 0) {
	    Random rand = new Random();
	    return avail.get(rand.nextInt(avail.size()));
	} else if (allowNull)
	    return null;
	else
	    return best;
    }
    public String toString() {
	return "Road: " + Integer.toString(this.startIC) + ", " + Integer.toString(this.endIC);
    }
}
