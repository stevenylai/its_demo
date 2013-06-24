import java.util.*;

public class TestMap implements ITSSender {
  private List<ITSReceiver> msgListeners;
  public TestMap () {
    this.msgListeners = new ArrayList<ITSReceiver>();
  }
  public void addITSListener (ITSReceiver receiver) {
    this.msgListeners.add(receiver);
  }
  public void run () {
  }
  public static void main(String[] args) throws Exception {
    TestMap tester = new TestMap();
    Map its_map = new Map(tester);
    tester.addITSListener(its_map);
    while (true) {
      tester.run();
      Thread.yield();
    }
  }
}
