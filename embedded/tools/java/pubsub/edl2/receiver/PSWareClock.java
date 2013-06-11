package pubsub.edl2.receiver;

public class PSWareClock implements Runnable {
	public int count;
	public PSWareClock () {
		count=0;
	}
	public int getClock () {
		return count;
	}
	public void run () {
		while (true) {
			try {
				Thread.sleep(1000);
				count++;
				Thread.yield();
			} catch (Exception e) {
				// Ignoring any error
			}
		}
	}
}
