import java.util.*;
import java.util.logging.*;

class Car {
    public final static int ENTERING = 0;
    public final static int LEAVING = 1;
    public final static int TRANSIT = 2;
    public final static int DEFAULT_SPEED = 3;
    static private Logger LOGGER = Logger.getLogger(Car.class.getName());

    public int id;
    public boolean stopped;
    public Road from;
    public Road belongs;
    public Road to;
    public int speed;
    public int status;
    public Date freshness;
    public Date lastControl;
    public Date lastMsgReceived;
    public ITSSender sender;
    public Car (int id, ITSSender comm, Road belongs) {
	this.id = id;
	this.sender = comm;
	this.belongs = belongs;
	this.speed = Car.DEFAULT_SPEED;
	this.freshness = new Date();
	this.lastControl = new Date();
	this.stopped = false;
	Car.LOGGER.config("Creating car:" + this.toString());
    }
    public int getCurrentIC() {
	if (this.status == Car.ENTERING) {
	    return this.belongs.startIC;
	} else {
	    return this.belongs.endIC;
	}
    }
    public void updateReceived(Date received) {
	this.lastMsgReceived = received;
    }
    public void stop() {
	if (!this.stopped) {
	    this.stopped = true;
	    this.speed = 0;
	    this.setSpeed(0);
	    this.lastControl = new Date();
	}
    }
    public void start() {
        if (this.stopped) {
            this.stopped = false;
            this.speed = Car.DEFAULT_SPEED;
            this.setSpeed(this.speed);
            this.lastControl = new Date();
        }
    }
    public void turn(Road road) {
        for (Enumeration<Integer> e = this.belongs.exitRoads.keys(); e.hasMoreElements();) {
            Integer turn = e.nextElement();
            if (this.belongs.exitRoads.get(turn) == road) {
        	if (turn.intValue() == 1) { // 1: straight - no need to turn
        	    this.setDirIC(0, this.belongs.endIC);
        	    this.lastControl = new Date();
        	} else {
        	    this.setDirIC(1, this.belongs.endIC);
        	    this.lastControl = new Date();
        	}
        	 
            }
        }
    }
    public void prepareExit(boolean allowNull) {
	this.to = this.belongs.chooseExit(allowNull);
	if (this.to != null) {
	    String logStr = this.toString() + " is instructed to switch to " + this.to.toString();
	    if (this.lastMsgReceived != null) {
		Date current = new Date();
		logStr += ". Time spent in decision making: " +
		    (current.getTime() - this.lastMsgReceived.getTime()) + 
		    " ms";
	    }
	    Car.LOGGER.config(logStr);
	    
	    this.turn(this.to);
	}
    }
    public boolean exitPrepared() {
	if (this.to == null)
	    return false;
	
	for (Enumeration<Road> e = this.belongs.exitRoads.elements(); e.hasMoreElements();) {
	    Road road = e.nextElement();
	    if (road.startIC == this.to.startIC && road.endIC == this.to.endIC)
		return true;
	}
	return false;
    }
    public void setSpeed(int speed) {
	VehicleMsg cmd = new VehicleMsg();
	cmd.set_dir((short)0x00);
	cmd.set_speed((short)speed);
	cmd.set_icnum((short)(this.getCurrentIC()-1)); // Disable the dir
	this.sender.sendPacket(this.id, cmd);
    }
    public void setDir(int dir) {
	VehicleMsg cmd = new VehicleMsg();
	cmd.set_dir((short)dir);
	cmd.set_speed((short)0x10);
	cmd.set_icnum((short)this.getCurrentIC());
	this.sender.sendPacket(this.id, cmd);
    }

    public void setDirIC(int dir, int IC) {
	VehicleMsg cmd = new VehicleMsg();
	cmd.set_dir((short)dir);
	cmd.set_speed((short)0x10);
	cmd.set_icnum((short)IC);
	this.sender.sendPacket(this.id, cmd);
    }
    public void remove() {
	if (this.belongs.cross != null) {
	    this.belongs.cross.waiting.remove(this);
	}
	this.belongs.cars.remove(this);
    }
    public void switchTo(Road newRoad, int newIC) {
	int previousIC = this.getCurrentIC();
	//Car.LOGGER.config("Switching " + this.toString() + " to " + newRoad.toString());
	if (this.belongs.cross != null) {
	    //Car.LOGGER.config("Removing car from the old intersection");
	    this.belongs.cross.waiting.remove(this);
	}
	if (newRoad != this.belongs) { // reset the state variables
	    this.stopped = false;
	    this.freshness = new Date();
	}
	if (newRoad != this.belongs && this.status != Car.TRANSIT) {
	    if (newIC == newRoad.startIC && this.status == Car.ENTERING)
		Car.LOGGER.warning("IC card " + this.belongs.endIC +
				      " for Car: " + this.id + " is skipped");
	    else if (newIC == newRoad.endIC)
		Car.LOGGER.warning("IC card " + newRoad.startIC +
				      " for Car: " + this.id + " is skipped");
	}
	this.belongs.cars.remove(this);
	this.from = this.belongs;
	this.belongs = newRoad;
	this.belongs.cars.add(this);
    }
    protected String statusString() {
	if (this.status == Car.ENTERING)
	    return "ENTERING";
	else if (this.status == Car.LEAVING)
	    return "LEAVING";
	else
	    return "TRANSIT";
    }
    public String toString() {
	return "Car: " + Integer.toString(this.id) + ", status: " + this.statusString() + "," + (this.stopped ? "stopped" : "running") + ", on " + this.belongs.toString();
    }
}
