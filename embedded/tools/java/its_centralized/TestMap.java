import java.util.*;

public class TestMap implements ITSSender {
  private List<ITSReceiver> msgListeners;
  private List<int[]> msgs;

  public TestMap () {
    this.msgListeners = new ArrayList<ITSReceiver>();
    this.msgs = new ArrayList<int[]>();
    // Collision avoidance
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}
    this.msgs.add(new int[]{1, 1, 61, 5});
    this.msgs.add(new int[]{2, 1, 61, 5});
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}
    this.msgs.add(new int[]{1, 1, 57, 5});
    this.msgs.add(new int[]{2, 1, 83, 5});
    this.msgs.add(new int[]{3, 1, 83, 5});
    this.msgs.add(new int[]{4, 1, 53, 5});
    this.msgs.add(new int[]{4, 1, 55, 5});
    this.msgs.add(new int[]{5, 1, 82, 5});
    this.msgs.add(new int[]{1, 1, 59, 5});
    this.msgs.add(new int[]{1, 1, 61, 5});
    /*
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}
    this.msgs.add(new int[]{1, 1, 63, 5});
    this.msgs.add(new int[]{2, 1, 63, 5});

    this.msgs.add(new int[]{1, 1, 6, 5});
    this.msgs.add(new int[]{1, 1, 7, 5});
    this.msgs.add(new int[]{1, 1, 8, 5});
    this.msgs.add(new int[]{2, 1, 75, 5});
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}
    // Collision avoidance
    this.msgs.add(new int[]{1, 1, 9, 5});
    this.msgs.add(new int[]{2, 1, 9, 5});
    this.msgs.add(new int[]{1, 1, 10, 5});
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {}
    this.msgs.add(new int[]{2, 1, 10, 5});
    */
  }
  public void addITSListener (ITSReceiver receiver) {
    this.msgListeners.add(receiver);
  }
  public void run () {
    for (int[] msg : this.msgs) {
      for (ITSReceiver receiver : this.msgListeners) {
	      System.out.println("Receiving message:" + Integer.toString(msg[0]) + " " + Integer.toString(msg[1]) + " " + Integer.toString(msg[2]) + " " + Integer.toString(msg[3]));
	      receiver.receiveMsg(msg[0], msg[1], msg[2], msg[3]);
      }
    }
  }
  public void setSpeed(Car car, int speed) {
    System.out.println("Setting speed of car : "+Integer.toString(car.id)+" to: "+Integer.toString(speed));
  }
  public void setDir(Car car, int dir) {
    System.out.println("Setting dir of car : "+Integer.toString(car.id)+" to: "+Map.getDirString(dir));
  }
  public static void main(String[] args) throws Exception {
    TestMap tester = new TestMap();
    Map its_map = new Map(tester);
    tester.addITSListener(its_map);
    tester.run();
    //tester.run();
    Thread.yield();

  }
}
