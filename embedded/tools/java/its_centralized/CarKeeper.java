import java.util.*;
import java.util.logging.*;

public class CarKeeper {
    public static final long EXPIRY_DURATION = 5 * 60 * 1000; // five minutes
    private static Logger LOGGER = Logger.getLogger(CarKeeper.class.getName());
    public CarKeeper () {}

    public void checkInactiveCar(Dictionary <Integer, Car> cars, MessageDispatcher pendingCars) {
	Date current = new Date();
	List<Integer> toRemove = new ArrayList<Integer>();
	for (Enumeration<Integer> e = cars.keys(); e.hasMoreElements();) {
	    Integer carid = e.nextElement();
	    long diff = current.getTime() - cars.get(carid).freshness.getTime();
	    if (!cars.get(carid).stopped && diff > CarKeeper.EXPIRY_DURATION) {
		CarKeeper.LOGGER.config(cars.get(carid) + " has been inactive for " + diff / 1000 + " seconds. Removing it");
		toRemove.add(carid);
	    }
	}
	for (Integer carid : toRemove) {
	    pendingCars.removeCar(cars.get(carid));
	    cars.get(carid).remove();
	    cars.remove(carid);
	}
    }
}
