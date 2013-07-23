import java.util.*;

public class TestMap implements ITSSender {
  private List<ITSReceiver> msgListeners;
  private List<int[]> msgs;

  public TestMap () {
    this.msgListeners = new ArrayList<ITSReceiver>();
    this.msgs = new ArrayList<int[]>();
    this.msgs.add(new int[]{1, 1, 6, 5});
    this.msgs.add(new int[]{1, 1, 7, 5});
    this.msgs.add(new int[]{1, 1, 8, 5});
    this.msgs.add(new int[]{2, 1, 75, 5});
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
