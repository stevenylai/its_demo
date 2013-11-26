import java.util.*;

public class CarRemover implements Runnable {
  Map map;
  int sleep;
  public CarRemover (Map map) {
    this.map = map;
    this.sleep = 10000;
  }
  public void run () {
    try {
      while (true) {
        Thread.sleep(this.sleep);
        this.map.checkInactiveCars();
      }
    } catch (InterruptedException e) {}
  }
}
