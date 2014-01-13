import java.util.*;

class DispatchInfo {
    public Car car;
    public Road exit;
    public Date date;
    public DispatchInfo(Car car, Date date, Road exit) {
	this.car = car;
	this.date = date;
	this.exit = exit;
    }
}
public class MessageDispatcher implements Runnable{
    List<DispatchInfo> dispatchList;
    Map map;
    int sleep;

    public MessageDispatcher (Map map) {
	this.map = map;
	this.dispatchList = new ArrayList<DispatchInfo>();
	this.sleep = 1000;
    }
    synchronized public void addCar (Car car, Date date, Road exit) {
	System.out.println("Adding car: " + car + " to dispatcher");
	this.dispatchList.add(new DispatchInfo(car, date, exit));
    }
    synchronized public boolean hasCar (Car car) {
	for (DispatchInfo info : this.dispatchList)
	    if (info.car.id == car.id)
		return true;
	return false;
    }
    synchronized public void removeCar(Car car) {
	int i;
	for (i = 0; i < this.dispatchList.size(); i++) {
	    if (this.dispatchList.get(i).car.id == car.id)
		break;
	}
	if (i < this.dispatchList.size())
	    this.dispatchList.remove(i);
    }
    synchronized public void checkCars() {
	boolean processed = false;
	do {
	    int i;
	    for (i = 0; i < this.dispatchList.size(); i++) {
		Date current = new Date();
		if (current.getTime() - this.dispatchList.get(i).car.belongs.lastExit.getTime() >= Map.SAFE_EXIT_INTERVAL) {
		    System.out.println("Dispatching car: " + this.dispatchList.get(i).car + " at " + current);
		    this.map.startCar(this.dispatchList.get(i).car);
		    this.map.turnCar(this.dispatchList.get(i).car, this.dispatchList.get(i).exit);
		    System.out.println("Road " + this.dispatchList.get(i).exit + ". lastExit: " + this.dispatchList.get(i).exit.lastExit + " this exit " + current);
		    this.dispatchList.get(i).car.belongs.lastExit = current;
		    break;
		}
	    }
	    if (i < this.dispatchList.size()) {
		this.dispatchList.remove(i);
		processed = true;
	    } else
		processed = false;
	} while (processed);
    }
    public void run () {
	try {
	    while (true) {
		Thread.sleep(this.sleep);
		this.checkCars();
	    }
	} catch (InterruptedException e) {}
    }
}
