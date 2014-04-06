import java.io.IOException;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

class SimpleSender implements ITSSender {
    MoteIF moteIF;
    public SimpleSender(MoteIF mif) {
	this.moteIF = mif;
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
}