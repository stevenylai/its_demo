import java.util.*;

class Car {
    public final static int ENTERING = 0;
    public final static int LEAVING = 1;
    public final static int TRANSIT = 2;
    public final static int DEFAULT_SPEED = 3;

    public int id;
    public boolean stopped;
    public Road from;
    public Road belongs;
    public int speed;
    public int status;
    public Date freshness;
    public Date lastControl;
    public Car (int id, Road belongs) {
        this.id = id;
        this.belongs = belongs;
        this.speed = Car.DEFAULT_SPEED;
        this.freshness = new Date();
        this.lastControl = new Date();
        this.stopped = false;
        System.out.println("Creating car:" + this.toString());
    }
    public int getCurrentIC() {
        if (this.status == Car.ENTERING) {
            return this.belongs.startIC;
        } else {
            return this.belongs.endIC;
        }
    }
    public void remove() {
        if (this.belongs.cross != null) {
            this.belongs.cross.waiting.remove(this);
        }
        this.belongs.cars.remove(this);
    }
    public void switchTo(Road newRoad) {
        //System.out.println("Switching " + this.toString() + " to " + newRoad.toString());
        if (this.belongs.cross != null) {
            //System.out.println("Removing car from the old intersection");
            this.belongs.cross.waiting.remove(this);
        }
        if (newRoad != this.belongs) { // reset the state variables
            this.stopped = false;
            this.freshness = new Date();
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
