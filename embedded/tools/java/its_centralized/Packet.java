import java.io.IOException;
import java.util.*;
import java.text.*;

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
    private SimpleDateFormat format;
    private Thread checkTimeout;
  
    public Packet(MoteIF moteIF) {
	this.moteIF = moteIF;
	this.moteIF.registerListener(new VehicleMsg(), this);
	this.moteIF.registerListener(new TrafficLightMsg(), this);
	Message ackMsg = new VehicleMsg();
	//System.out.println("Ack AM type: " + ackMsg.amType() + " inverted: " + ((~ackMsg.amType()) & 0xff));
	ackMsg.amTypeSet((~ackMsg.amType()) & 0xff);
	this.moteIF.registerListener(ackMsg, this);
	this.format = new SimpleDateFormat("yyyy.MM.dd HH:mm:ss.S");
	this.carListeners = new ArrayList<CarReceiver>();
	this.trafficLightListeners = new ArrayList<TrafficLightReceiver>();
	this.pendingAck = new Hashtable<Integer, MessageInfo>();
        this.checkTimeout = new Thread(this);
	this.checkTimeout.start();
    }
    public void sendPacket(int id, Message msg) {
	//this.sendPacket(id, msg, true);
	this.sendPacket(id, msg, false);
    }
    private void sendPacket(int id, Message msg, boolean addToPending) {
	boolean success = false;
	while (!success) {
	    try {
		Date current = new Date();
		System.out.println(this.format.format(current) + ": sending packet " + msg);
		moteIF.send(id, msg);
		if (addToPending)
		    this.addPendingPacket(id, msg);
		success = true;
	    } catch (IOException e) {
		success = false;
	    }
	}
    }
    synchronized public void addPendingPacket(int id, Message msg) {
	MessageInfo msgInfo = new MessageInfo(id, msg);
	this.pendingAck.put(new Integer(id), msgInfo);
    }
    synchronized public void ackedPacket(int id, Message msg) {
	MessageInfo pending = this.pendingAck.get(new Integer(id));
	if (pending != null) {
	    byte [] expected = pending.message.dataGet();
	    byte [] actual = msg.dataGet();
	    boolean sameContent = true;
	    if (expected.length != actual.length)
		sameContent = false;
	    else {		 
		for (int i = 0; i < expected.length; i++)
		    if (expected[i] != actual[i]) {
			sameContent = false;
			break;
		    }
	    }
	    if (sameContent) {	
		Date current = new Date();
		System.out.println(this.format.format(current) + ": received ack for packet: " + pending.message);
		this.pendingAck.remove(new Integer(id));
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
		this.sendPacket(msgInfo.id, msgInfo.message, false);
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
	if (message.amType() == ((~(new VehicleMsg()).amType()) & 0xff)) {
	    SerialPacket serialMsg = message.getSerialPacket();
	    this.ackedPacket(serialMsg.get_header_dest(), message);
	} else if (message.amType() == (new VehicleMsg()).amType()) {
	    VehicleMsg msg = (VehicleMsg)message;
	    SerialPacket serialMsg = message.getSerialPacket();
	    //System.out.println("Received packet " + msg + " Serial packet " + serialMsg);
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
	    System.out.println("Unknown msg type: " + message.amType());
	}
    }
  
    private static void usage() {
	System.err.println("usage: TestSerial [-comm <source>]");
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
	System.err.println("##########################Starting up demo##########################");

	while (true) {
	    Thread.sleep(2000);
	    Thread.yield();
	}
    }
}
