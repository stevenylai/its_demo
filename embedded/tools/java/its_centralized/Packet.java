import java.io.IOException;
import java.util.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class Packet implements MessageListener, ITSSender {

    private MoteIF moteIF;
    private List<CarReceiver> carListeners;
    private List<TrafficLightReceiver> trafficLightListeners;
  
    public Packet(MoteIF moteIF) {
	this.moteIF = moteIF;
	this.moteIF.registerListener(new VehicleMsg(), this);
	this.moteIF.registerListener(new TrafficLightMsg(), this);
	this.carListeners = new ArrayList<CarReceiver>();
	this.trafficLightListeners = new ArrayList<TrafficLightReceiver>();
    }

    public void sendPacket(int id, Message msg) {
	boolean success = false;
	while (!success) {
	    try {
		System.out.println("Sending packet " + msg);
		moteIF.send(id, msg);
		success = true;
	    } catch (IOException e) {
		success = false;
	    }
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
