import java.io.IOException;
import java.util.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class Send {
  private static MoteIF moteIF;
 
  private static void sendPacket(int id, VehicleTurnMsg cmd) {
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
  private static void usage() {
    System.err.println("usage: Send <turn> <delay>");
  }
  
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      usage();
      System.exit(1);
    }
    VehicleTurnMsg msg = new VehicleTurnMsg();
    msg.set_turnPoint((short)Short.parseShort(args[0]));
    msg.set_delay(Integer.parseInt(args[1]));
    
    PhoenixSource phoenix;
   
    MoteIF mif = new MoteIF(BuildSource.makePhoenix(PrintStreamMessenger.err));
    mif.send(MoteIF.TOS_BCAST_ADDR, msg);

  }
}
