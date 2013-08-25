import java.util.*;

public class MessageDispatcher implements Runnable{
  List<Car> carList;
  List<Date> dateList;
  List<Road> exitList;
  Map map;
  int sleep;
  final static int STARTUP_DELAY = 1000;

  public MessageDispatcher (Map map) {
    this.map = map;
    this.carList = new ArrayList<Car>();
    this.exitList = new ArrayList<Road>();
    this.dateList = new ArrayList<Date>();
    this.sleep = 1000;
  }
  synchronized public void addCar (Car car, Date date, Road exit) {
    System.out.println("Adding car: " + car + " to dispatcher");
    this.carList.add(car);
    this.exitList.add(exit);
    this.dateList.add(date);
  }
  synchronized public boolean hasCar (Car car) {
    return this.carList.contains(car);
  }
  synchronized public void removeCar(Car car) {
    int i;
    for (i = 0; i < this.carList.size(); i++) {
      if (this.carList.get(i).id == car.id)
        break;
    }
    if (i < this.carList.size()) {
      this.carList.remove(i);
      this.exitList.remove(i);
      this.dateList.remove(i);
    }
  }
  synchronized public void checkCars() {
    Date current = new Date();
    boolean processed = false;
    do {
      int i;
      for (i = 0; i < this.carList.size(); i++) {
        if (current.getTime() - this.dateList.get(i).getTime() >= MessageDispatcher.STARTUP_DELAY) {
          System.out.println("Dispatching car: " + this.carList.get(i));
          this.map.startCar(this.carList.get(i));
          this.map.turnCar(this.carList.get(i), this.exitList.get(i));
          this.exitList.get(i).lastExit = current;
          break;
        }
      }
      if (i < this.carList.size()) {
        this.carList.remove(i);
        this.exitList.remove(i);
        this.dateList.remove(i);
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
