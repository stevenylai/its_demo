import java.io.IOException;
import java.io.*;
import java.net.*;

import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class TestSerial implements MessageListener {

  private MoteIF moteIF;
  private int counter;
  private static ServerSocket server;
  private static Socket client;
  private static PrintWriter out;

  private static ServerSocket cmdserver;
  private static Socket cmdclient;
  private static BufferedReader cmdin;
  
  public TestSerial(MoteIF moteIF) {
    this.moteIF = moteIF;
    this.moteIF.registerListener(new MoteToBaseMsg(), this);
    counter = 0;
  }

  public void sendPacket(int nodeid, int cmd, int dir, int data) {
    BaseToMoteMsg payload = new BaseToMoteMsg();
    try {
	System.out.println("Sending packet " + counter);
	payload.set_nodeid(nodeid);
	payload.set_cmd((short)cmd);
	if(cmd == 1){
		payload.set_data(data);
	}
	else if(cmd == 2){
		if(dir == 1){
		payload.set_data(256+data);
		}
	}
	moteIF.send(0, payload);
	counter++;
    }
    catch (IOException exception) {
      System.err.println("Exception thrown when sending packets. Exiting.");
      System.err.println(exception);
    }
  }

  public void messageReceived(int to, Message message) {
    MoteToBaseMsg msg = (MoteToBaseMsg)message;
    int nodeid = msg.get_nodeid();
    short dir = msg.get_dir();
    short icnum = msg.get_icnum();
    int speed = msg.get_speed();
    String ostr = "" + nodeid + ","
			+ dir + ","
		        +icnum + ","
			+speed;
    System.out.println(ostr);
    out.println(ostr);
    out.flush();
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
    server=new ServerSocket(5686);
    client=server.accept();
    System.out.println("Report Client connected...");
    out=new PrintWriter(client.getOutputStream());

    cmdserver=new ServerSocket(5687);
    cmdclient=cmdserver.accept();
    System.out.println("Cmd Client connected...");
    cmdin=new BufferedReader(new InputStreamReader(cmdclient.getInputStream()));

    PhoenixSource phoenix;
    
    if (source == null) {
      phoenix = BuildSource.makePhoenix(PrintStreamMessenger.err);
    }
    else {
      phoenix = BuildSource.makePhoenix(source, PrintStreamMessenger.err);
    }

    MoteIF mif = new MoteIF(phoenix);
    TestSerial serial = new TestSerial(mif);
    while(true){
	String str = cmdin.readLine();
	System.out.println(str);
	if(str == null)
		continue;
	if(str.equals("end"))
		break;
	String[] paras = str.split(",");
    	serial.sendPacket(Integer.parseInt(paras[0]),
			Integer.parseInt(paras[1]),
			Integer.parseInt(paras[2]),
			Integer.parseInt(paras[3]));
    }
    client.close();
  }


}
