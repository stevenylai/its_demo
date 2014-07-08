import java.io.IOException;
import java.util.*;
import java.text.*;
import java.util.logging.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.message.*;
import net.tinyos.util.*;

class MessageInfo {
    public static final long MSG_TIMEOUT = 50; // ms
    public int id;
    public Date sent;
    public Message message;
    public MessageInfo(int id, Message message) {
	this.id = id;
	this.message = message;
	this.sent = new Date();
    }
    public boolean isTimeout() {
	Date current = new Date();
	long diff = current.getTime() - this.sent.getTime();
	if (diff > MessageInfo.MSG_TIMEOUT)
	    return true;
	else
	    return false;
    }
}

public class Packet implements MessageListener, ITSSender, Runnable {

    private MoteIF moteIF;
    private List<CarReceiver> carListeners;
    private List<TrafficLightReceiver> trafficLightListeners;
    private Dictionary<Integer, MessageInfo> pendingAck;
    private List<MessageInfo> resendMsg;
    private Thread checkTimeout;
    static private Logger LOGGER = Logger.getLogger(Packet.class.getName());
    static private String logFileName;

    static {
	DateFormat format = new SimpleDateFormat("yyyyMMddHHmmss");
	Date now = new Date();
	Packet.logFileName = format.format(now) + ".log";
    }
  
    public Packet(MoteIF moteIF) {
	Packet.setupLoggers();
	this.moteIF = moteIF;
	this.moteIF.registerListener(new VehicleMsg(), this);
	this.moteIF.registerListener(new TrafficLightMsg(), this);
	this.carListeners = new ArrayList<CarReceiver>();
	this.trafficLightListeners = new ArrayList<TrafficLightReceiver>();
	this.pendingAck = new Hashtable<Integer, MessageInfo>();
        this.checkTimeout = new Thread(this);
	this.checkTimeout.start();
	Packet.LOGGER.setLevel(Level.CONFIG);
    }
    static public void setupLoggers() {
	Properties props = System.getProperties();
	props.setProperty("java.util.logging.SimpleFormatter.format",
			  "%1$tY-%1$tm-%1$td %1$tH:%1$tM:%1$tS:%4$s/%2$s %5$s%6$s%n");
	//Logger logger = Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);
	Logger logger = Logger.getLogger("");
	/*
	Logger rootLogger = Logger.getLogger("");
	Handler[] handlers = rootLogger.getHandlers();
	if (handlers[0] instanceof ConsoleHandler) {
	    rootLogger.removeHandler(handlers[0]);
	}
	*/

	logger.setLevel(Level.CONFIG);
	SimpleFormatter formatter = new SimpleFormatter();
	try {
	    FileHandler fileHandler = new FileHandler(Packet.logFileName);
	    fileHandler.setFormatter(formatter);
	    fileHandler.setLevel(Level.CONFIG);
	    logger.addHandler(fileHandler);
	} catch (IOException e) {
	    System.err.println("Error in setting up log file!");
	}
	/*
	ConsoleHandler consoleHandler = new ConsoleHandler();
	consoleHandler.setFormatter(formatter);
	consoleHandler.setLevel(Level.INFO);
	logger.addHandler(consoleHandler);
	*/
    }
    public void sendPacket(int id, Message msg) {
	boolean success = false;
	while (!success) {
	    try {
		Packet.LOGGER.config("sending packet to " + id + " :" + msg);
		moteIF.send(id, msg);
		success = true;
	    } catch (IOException e) {
		success = false;
	    }
	}
    }
    synchronized public void checkTimeout() {
	this.resendMsg = new ArrayList<MessageInfo>();
	for (Enumeration<MessageInfo> e = this.pendingAck.elements(); e.hasMoreElements();) {
	    MessageInfo msgInfo = e.nextElement();
	    if (msgInfo.isTimeout())
		this.resendMsg.add(msgInfo);
	}
    }
    public void run() {
	while (true) {
	    this.checkTimeout();
	    for (MessageInfo msgInfo : this.resendMsg)
		this.sendPacket(msgInfo.id, msgInfo.message);
	    try {
		Thread.sleep(20);
	    } catch (Exception e) {}
	}
    }
    public void addCarListener (CarReceiver receiver) {
	this.carListeners.add(receiver);
    }
    public void addTrafficLightListener (TrafficLightReceiver receiver) {
	this.trafficLightListeners.add(receiver);
    }

    public void messageReceived(int to, Message message) {
	if (message.amType() == (new VehicleMsg()).amType()) {
	    VehicleMsg msg = (VehicleMsg)message;
	    SerialPacket serialMsg = message.getSerialPacket();
	    //Packet.LOGGER.config("Received packet " + msg + " Serial packet " + serialMsg);
	    for (CarReceiver receiver : this.carListeners) {
		receiver.receiveCar(serialMsg.get_header_src(), msg.get_dir(), msg.get_icnum(), msg.get_speed());
	    }
	} else if (message.amType() == (new TrafficLightMsg()).amType()) {
	    TrafficLightMsg msg = (TrafficLightMsg)message;
	    SerialPacket serialMsg = message.getSerialPacket();
	    for (TrafficLightReceiver receiver : this.trafficLightListeners) {
		receiver.receiveTrafficLight(serialMsg.get_header_src(), msg.get_dir(), msg.get_color(), msg.get_remain());
	    }
	    
	} else {
	    Packet.LOGGER.warning("Unknown msg type: " + message.amType());
	}
    }
  
    private static void usage() {
	Packet.LOGGER.info("usage: TestSerial [-comm <source>]");
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
	Map its_map = new Map(comm);
	comm.addCarListener(its_map);
	comm.addTrafficLightListener(its_map);
	CarRemover remover = new CarRemover(its_map);
	Thread remover_thread = new Thread(remover);
	remover_thread.start();
	Packet.LOGGER.info("##########################Starting up demo (" +
			   Packet.logFileName + ")##########################");

	while (true) {
	    Thread.sleep(2000);
	    Thread.yield();
	}
    }
}
