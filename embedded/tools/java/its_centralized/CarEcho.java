import java.io.IOException;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.message.*;
import net.tinyos.util.*;

public class CarEcho implements MessageListener, Runnable {
    private MoteIF moteIF;

    public CarEcho(MoteIF moteIF) {
	this.moteIF = moteIF;
	this.moteIF.registerListener(new VehicleMsg(), this);
	System.out.println("Msg registered");
    }

    public void messageReceived(int to, Message message) {
	System.out.println("Received message: " + message);
	if (message.amType() == (new VehicleMsg()).amType()) {
	    SerialPacket serialMsg = message.getSerialPacket();
	    boolean success = false;
	    while (!success) {
		try {
		    this.moteIF.send(serialMsg.get_header_src(), message);
		    success = true;
		} catch (IOException e) {
		}
	    }
	}
    }

    public void run() {
    }
    private static void usage() {
	System.err.println("usage: CarEcho [-comm <source>]");
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
	CarEcho comm = new CarEcho(mif);
	while (true) {
	    Thread.sleep(200);
	    Thread.yield();
	}
    }
}