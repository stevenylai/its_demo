import java.util.*;
import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class TrafficLightTest implements MessageListener {
    private MoteIF moteIF;
    private Dictionary <Integer, Integer> info;

    public TrafficLightTest(MoteIF mif) {
	this.info = new Hashtable<Integer, Integer>();
	for (int i = 0; i < TrafficLight.DIR_UNKNOWN; i++) {
	    this.info.put(new Integer(i), new Integer(TrafficLight.LIGHT_UNKNOWN));
	}
	this.moteIF = mif;
	this.moteIF.registerListener(new TrafficLightMsg(), this);
    }
    public void messageReceived(int to, Message message) {
	if (message.amType() == (new TrafficLightMsg()).amType()) {
	    TrafficLightMsg msg = (TrafficLightMsg)message;
	    short color = msg.get_color();
	    short dir = msg.get_dir();
	    int remain = msg.get_remain();
	    Date current = new Date();
	    Integer preColor = this.info.get(new Integer(dir));
	    if (preColor.intValue() != color) {
		this.info.put(new Integer(dir), new Integer(color));
		System.out.println(current + " Dir: " + TrafficLight.dirString(dir) + ", color: " + TrafficLight.colorString(color) + ", remain: " + remain);
	    }
		
	}
    }
    public static void main(String[] args) throws Exception {
	PhoenixSource phoenix = BuildSource.makePhoenix(PrintStreamMessenger.err);
	MoteIF mif = new MoteIF(phoenix);
	if (args.length == 1) {
	    SimpleSender sender = new SimpleSender(mif);
	    System.out.println("Setting light color");
	    TrafficLight controller = new TrafficLight(100, sender);
	    controller.setLight(TrafficLight.DIR_NORTH, TrafficLight.LIGHT_GREEN, 10);
	    controller.setLight(TrafficLight.DIR_SOUTH, TrafficLight.LIGHT_GREEN, 10);
	    controller.setLight(TrafficLight.DIR_EAST, TrafficLight.LIGHT_RED, 10);
	    controller.setLight(TrafficLight.DIR_WEST, TrafficLight.LIGHT_RED, 10);
	} else {
	    TrafficLightTest test = new TrafficLightTest(mif);
	    while (true) {	    
		Thread.sleep(2000);
		Thread.yield();

	    }
	}
    }
}