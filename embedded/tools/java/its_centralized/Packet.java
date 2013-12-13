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
    this.moteIF.registerListener(new VehicleMsg(), this);
    this.msgListeners = new ArrayList<ITSReceiver>();
  }

  private void sendPacket(int id, VehicleMsg cmd) {
    boolean success = false;
    while (!success) {
      try {
	      System.out.println("Sending packet " + cmd);
  	    moteIF.send(id, cmd);
        success = true;
      } catch (IOException e) {
        success = false;
      }
    }
  }
  public void setSpeed(Car car, int speed) {
    VehicleMsg cmd = new VehicleMsg();
    cmd.set_dir((short)0x00);
    cmd.set_speed((short)speed);
    cmd.set_icnum((short)(car.getCurrentIC()-1)); // Disable the dir
    sendPacket(car.id, cmd);
  }
  public void setDir(Car car, int dir) {
    VehicleMsg cmd = new VehicleMsg();
    cmd.set_dir((short)dir);
    cmd.set_speed((short)0x10);
    cmd.set_icnum((short)car.getCurrentIC());
    sendPacket(car.id, cmd);
  }

  public void addITSListener (ITSReceiver receiver) {
    this.msgListeners.add(receiver);
  }
  public void messageReceived(int to, Message message) {
    VehicleMsg msg = (VehicleMsg)message;
    SerialPacket serialMsg = message.getSerialPacket();
    //System.out.println("Received packet " + msg + " Serial packet " + serialMsg);
    for (ITSReceiver receiver : this.msgListeners) {
      receiver.receiveMsg(serialMsg.get_header_src(), msg.get_dir(), msg.get_icnum(), msg.get_speed());
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
