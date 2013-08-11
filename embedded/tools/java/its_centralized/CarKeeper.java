import java.util.*;

public class CarKeeper {
  public static final long EXPIRY_DURATION = 60 * 1000; // two minutes
  public CarKeeper () {}

  public void checkInactiveCar(Dictionary <Integer, Car> cars) {
    Date current = new Date();
    List<Integer> toRemove = new ArrayList<Integer>();
    for (Enumeration<Integer> e = cars.keys(); e.hasMoreElements();) {
      Integer carid = e.nextElement();
      long diff = current.getTime() - cars.get(carid).freshness.getTime();
      if (diff > CarKeeper.EXPIRY_DURATION) {
        System.out.println(cars.get(carid) + " has been inactive for " + diff / 1000 + " seconds. Removing it");
        toRemove.add(carid);
      }
    }
    for (Integer carid : toRemove) {
      cars.get(carid).remove();
      cars.remove(carid);
    }
  }
}
