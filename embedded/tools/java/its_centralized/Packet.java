import java.io.IOException;
import java.util.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class Packet implements MessageListener, ITSSender {

  private MoteIF moteIF;
  private List<ITSReceiver> msgListeners;
  
  public Packet(MoteIF moteIF) {
    this.moteIF = moteIF;
    this.moteIF.registerListener(new MoteToBaseMsg(), this);
    this.msgListeners = new ArrayList<ITSReceiver>();
  }

  public void sendMsg(int id, int dir, int speed) {
    BaseToMoteMsg payload = new BaseToMoteMsg();
    
    try {
      while (true) {
	      System.out.println("Sending packet ");
	      payload.set_nodeid(id);
	      payload.set_dir((short)dir);
	      //payload.set_IC_NO((short)73);
	      payload.set_speed(speed);
	      moteIF.send(0, payload);
	      try {Thread.sleep(1000);}
	      catch (InterruptedException exception) {}
      }
    } catch (IOException exception) {
      System.err.println("Exception thrown when sending packets. Exiting.");
      System.err.println(exception);
    }
  }

  public void addITSListener (ITSReceiver receiver) {
    this.msgListeners.add(receiver);
  }
  public void messageReceived(int to, Message message) {
    MoteToBaseMsg msg = (MoteToBaseMsg)message;
    System.out.println("Received packet " + msg);
    for (ITSReceiver receiver : this.msgListeners) {
      receiver.receiveMsg(msg.get_nodeid(), msg.get_dir(), msg.get_icnum(), msg.get_speed());
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
    comm.addITSListener(its_map);

    while (true) {
      Thread.yield();
    }
  }
}
