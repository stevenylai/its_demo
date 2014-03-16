import java.io.IOException;
import java.util.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

class TrafficLightInfo {
    public int color;
    public int remain;
    public Date lastUpdated;
    public TrafficLightInfo() {
	this.color = TrafficLight.LIGHT_UNKNOWN;
	this.remain = 0;
	this.lastUpdated = null;
    }
    public boolean update(int color, int remain) {
	boolean changed = (this.color == color);
	this.color = color;
	this.remain = remain;
	this.lastUpdated = new Date();
	return changed;
    }
}
// Test for TrafficLigtMsg
public class TrafficLight {

    public static final short LIGHT_GREEN = 1;
    public static final short LIGHT_YELLOW = 2;
    public static final short LIGHT_RED = 3;
    public static final short LIGHT_UNKNOWN = 4;

    public static final short DIR_NORTH = 1;
    public static final short DIR_SOUTH = 3;
    public static final short DIR_EAST = 0;
    public static final short DIR_WEST = 2;
    public static final short DIR_UNKNOWN = 4;

    public static final long EXPIRY_DURATION = 10; // 10 seconds
    public static final int defaultColorDuration = 8;

    public static Date lastUpdate = null;

    public int id;
    public ITSSender sender;
    public Dictionary <Integer, TrafficLightInfo> info;
    public Dictionary <Integer, Road> roads;

    public TrafficLight(int id, ITSSender comm) {
	this.id = id;
	this.sender = comm;
	this.roads = new Hashtable<Integer, Road>();
	this.info = new Hashtable<Integer, TrafficLightInfo>();
	for (int i = 0; i < TrafficLight.DIR_UNKNOWN; i++) {
	    TrafficLightInfo lightInfo = new TrafficLightInfo();
	    this.info.put(new Integer(i), lightInfo);
	}
    }
    public Car getFirstCar(int dir) {
	Road road = this.roads.get(new Integer(dir));
	if (road == null)
	    return null;
	else if (road.cars.size() > 0)
	    return road.cars.get(0);
	else
	    return null;
    }
    public boolean updateInfo(int dir, int color, int remain) {
	TrafficLightInfo lightInfo = this.info.get(new Integer(dir));
	boolean changed = lightInfo.update(color, remain);
	TrafficLight.lastUpdate = new Date();
	return changed;
    }
    public void addRoad(int dir, Road road) {
	this.roads.put(new Integer(dir), road);
    }
    public boolean askPass(int dir) {
	TrafficLightInfo lightInfo = this.info.get(new Integer(dir));
	if (lightInfo.color == TrafficLight.LIGHT_GREEN ||
	    lightInfo.color == TrafficLight.LIGHT_UNKNOWN)
	    return true;
	else {
	    int dirOther1 = (dir + 1) % DIR_UNKNOWN, dirOther2 = (dir + 3) % DIR_UNKNOWN;
	    Road roadOther1 = this.roads.get(new Integer(dirOther1)),
		roadOther2 = this.roads.get(new Integer(dirOther2));
	    
	    if ((roadOther1 == null || roadOther1.cars.size() == 0) &&
		(roadOther2 == null || roadOther2.cars.size() == 0)) {
		this.setLight((short)dir, TrafficLight.LIGHT_GREEN, TrafficLight.defaultColorDuration);
		this.setLight((short)((dir + 2) % 4), TrafficLight.LIGHT_GREEN, TrafficLight.defaultColorDuration);
		this.setLight((short)dirOther1, TrafficLight.LIGHT_RED, TrafficLight.defaultColorDuration);
		this.setLight((short)dirOther2, TrafficLight.LIGHT_RED, TrafficLight.defaultColorDuration);
		return true;
	    } else
		return false;
	}
    }
    public static boolean isInEffect() {
	if (TrafficLight.lastUpdate == null)
	    return false;
	Date current = new Date();
	long diff = current.getTime() - TrafficLight.lastUpdate.getTime();
	if (diff > TrafficLight.EXPIRY_DURATION)
	    return false;
	else
	    return true;
    }
    public static String dirString(short dir) {
	switch (dir) {
	case DIR_NORTH:
	    return "North";
	case DIR_SOUTH:
	    return "South";
	case DIR_EAST:
	    return "East";
	case DIR_WEST:
	    return "West";
	default:
	    return "UnknownDir";
	}
    }

    public static String colorString(short color) {
	switch (color) {
	case LIGHT_GREEN:
	    return "Green";
	case LIGHT_YELLOW:
	    return "Yellow";
	case LIGHT_RED:
	    return "Red";
	default:
	    return "UnknownColor";
	}
    }
    public void messageReceived(int to, Message message) {
	TrafficLightMsg msg = (TrafficLightMsg)message;
	System.out.println("Dir: " + TrafficLight.dirString(msg.get_dir()) + ", color: " + TrafficLight.colorString(msg.get_color()) + ", remain: " + msg.get_remain());
    }
    private static void usage() {
	System.err.println("usage: TrafficLight [-comm <source>]");
    }
 
    public void setLight(short dir, short color, int remain) {
	TrafficLightMsg cmd;
	cmd = new TrafficLightMsg();
	cmd.set_dir(dir);
	cmd.set_color(color);
	cmd.set_remain(remain);
	this.sender.sendPacket(this.id, cmd);
    }
    public static void main(String[] args) throws Exception {
	String source = null;
	if (args.length == 2) {
	    if (!args[0].equals("-comm")) {
		usage();
		System.exit(1);
	    }
	    source = args[1];
	}
	else if (args.length != 0) {
	    usage();
	    System.exit(1);
	}
    
	PhoenixSource phoenix;
    
	if (source == null) {
	    phoenix = BuildSource.makePhoenix(PrintStreamMessenger.err);
	}
	else {
	    phoenix = BuildSource.makePhoenix(source, PrintStreamMessenger.err);
	}

	MoteIF mif = new MoteIF(phoenix);
	Packet comm = new Packet(mif);
	TrafficLight tl = new TrafficLight(1, comm);

	System.out.println("Starting the main loop");
	while (true) {
	    tl.setLight(TrafficLight.DIR_NORTH, TrafficLight.LIGHT_GREEN, 10);
	    tl.setLight(TrafficLight.DIR_SOUTH, TrafficLight.LIGHT_GREEN, 10);
	    tl.setLight(TrafficLight.DIR_EAST, TrafficLight.LIGHT_RED, 10);
	    tl.setLight(TrafficLight.DIR_WEST, TrafficLight.LIGHT_RED, 10);
	    Thread.sleep(1000);
	    Thread.yield();
	}
    }
}