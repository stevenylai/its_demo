package itransnet_base.tracking.Server.Manager;

import itransnet_base.tracking.Server.DataEngine.Map;
import itransnet_base.tracking.Server.Display.MainWindow;
import itransnet_base.tracking.Server.Display.StatisticsWindow;
import itransnet_base.tracking.Server.Display.SummaryWindow;
import itransnet_base.tracking.Server.Message.ITSMsg;
import itransnet_base.tracking.Server.Message.ITSWarnMsg;
import itransnet_base.tracking.Server.Message.MultiHop;
import itransnet_base.tracking.Utility.SensorConstants;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

import net.tinyos.message.Message;
import net.tinyos.message.MessageListener;
import net.tinyos.message.MoteIF;

/**
 * Controls the program execution at the top level.
 */
public class SensorManager implements MessageListener, Runnable, Manager, SensorConstants{

	// For registering the manager as a Mote listener
	MoteIF mote;
	private Initializer sensorInit;
	// Contains all of the information needed.
	private Map map;
	// Configures
	private Properties configure;
	private String configfile;
	
	private MainWindow display; // Main display window
      private StatisticsWindow statisticsWin; // Statistics window

	private SummaryWindow summaryDisplay; // Summary display window
	// Enable driver which is used for testing
	private boolean driverEnabled = false;
	private SensorDriver d;
	private int operCode;
	private int lastWarVid = 0;

	//private boolean localTesting = true;
	/**
	 * Creates a Manager instance.
	 * <p>
	 * The Manager is initialized to listen to the Serial Forward's port
	 * and it will create different components of the program such as map
	 * and GUI
	 */
	private void RedrawSensorDriver()
	{
		d.dispose();
		d = new SensorDriver(this);
		Thread driverThread = new Thread (d);
		driverThread.start();
	}
	public SensorManager(String configFile)
	{
		operCode = OPER_EVERY_MSG * OPER_SUMMARY_MSG * OPER_LIGHT;
		//mote = new MoteIF(PrintStreamMessenger.err,125);
		mote = new MoteIF();
		sensorInit = new Initializer(mote);
		
		//map = new Map();
		map = Map.defaultMap;
		
		// Load configures
		configure = new Properties();
		if (configFile!=null) {
			try {
				configure.load(new FileInputStream(configFile));
			} catch (IOException e) {
			}
		}
		String mapfile = getMapFile();
		if (map!=null){
			//map.loadMap(getMapFile());
		    map=Map.defaultMap;
		}
		
		display = new MainWindow(this);
				d = new SensorDriver(this);
            statisticsWin=new StatisticsWindow();		
	}

	public Map getMap() { return map; }
	
	/**
	 * Call-back method when a message is received from Serial Forward.
	 * <p>
	 * This method is called whenever Serial Forward delivers a message.
	 * @param		dest_addr	The destination address of the packet.
	 * @param		msg				The message returned.
	 */
	public void messageReceived(int dest_addr, Message msg)
	{
		System.out.println("Message received without error");// delete
		// Create a new thread to handle the message
		if (driverEnabled)
		{
			System.out.println("Dummy Message received without error");
			Message mtmsg = msg; // For testing
			MessageHandler handler = new MessageHandler (mtmsg);
			// Pass necessary information to the child so that it can handle the job
			handler.setMap(map);
			handler.setOutput(getDumpFile());
			
			//Thread handlerThread = new Thread (handler);
			//handlerThread.start();
			handler.run();
		}
		else
		{
			System.out.println("ddd dddReal Message received without error");
		    if(msg instanceof ITSWarnMsg)
		    {
				 //pop-up window + voice...
				 ITSWarnMsg wmsg = new ITSWarnMsg(msg.dataGet(),0);
     			 int vid = wmsg.get_vid();
				int warning = wmsg.get_warningNo();
				display.startAlertWindow("Emergency: Vehicle " + vid + " is broken at location " + warning, vid);
     			 return;
            }
			MultiHop mtmsg = new MultiHop(msg.dataGet());
			MessageHandler handler = new MessageHandler (msg);
			// Pass necessary information to the child so that it can handle the job
			handler.setMap(map);
			handler.setOutput(getDumpFile());
			
			//Thread handlerThread = new Thread (handler);
			//handlerThread.start();
			handler.run();
		}
	}

	/**
	 * The main execution procedure of the manager.
	 * <p>
	 * The manager will create a separate thread for GUI and listen to Serial Forward itself.
	 */
	public void run()
	{
		// Register for listening to messages
		System.out.println("Run...");
		if (!driverEnabled)
		{
			mote.registerListener(new ITSMsg(), this);
			mote.registerListener(new ITSWarnMsg(), this);
			mote.start();
			initializeWSN();
		}
		
		// Display thread
		Thread displayThread = new Thread (display);
		displayThread.start();
		
		if (displaySummary())
		{
			showSummary();
		}
		
		// Driver thread
		if (driverEnabled)
		{
			
			RedrawSensorDriver();
		}
		try{
			while (true)
			{
				Thread.sleep(3);Thread.yield();
			}
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
			
		}
	}
	private void showSummary()
	{
		summaryDisplay = new SummaryWindow (this);
		Thread displayThread = new Thread (summaryDisplay);
		displayThread.start();
	}
	private void initializeWSN()
	{
		// Initialize the sensors
		sensorInit.setMap(map);
		sensorInit.setManager(this);
		Thread initThread = new Thread (sensorInit);
		initThread.start();
	}
	
	public void changeMap (File newFile)
	{
		System.out.println("Received command to change file: file:///"+newFile.getPath().replace('\\', '/'));//+"/"+newFile.getName());
		String mapfile = newFile.getPath().replace('\\', '/');
		configure.setProperty("map", mapfile);
		map = new Map();
		map.loadMap(getMapFile());
		display.mapChanged(this);
		
		if (displaySummary())
		{
			summaryDisplay.dispose();
			showSummary();
		}
		
		if (!driverEnabled)
		{
			initializeWSN();
		}
		else
		{
		
		}
	}
	public void reloadMap()
	{
		//System.out.println("Received command to reload map.");
		map = new Map();
		map.loadMap(getMapFile());
		display.mapChanged(this);
		
		if (displaySummary())
		{
			summaryDisplay.dispose();
			showSummary();
		}
		
		if (!driverEnabled)
		{
			initializeWSN();
		}
		else
		{
			RedrawSensorDriver();
		}
	}

	public void clearMap()
	{
		System.out.println("Received command to clear map.");
		map = new Map();
		map.loadMap(getMapFile());
		display.mapChanged(this);
		
		if (displaySummary())
		{
			summaryDisplay.dispose();
			showSummary();
		}
		
		if (driverEnabled)
		{
			RedrawSensorDriver();
		}
	}

	public void updatOperation(int operCode)
	{
		System.out.println("Received command to change operation to "+operCode);
		this.operCode = operCode;
		reloadMap(); // Simpler in coding but result in energy inefficiency
	}
	public void startCars ()
	{
		sensorInit.setMap(map);
		sensorInit.setManager(this);
		sensorInit.startCars();
	}
	public void stopCars ()
	{
		sensorInit.setMap(map);
		sensorInit.setManager(this);
		sensorInit.stopCars();
	}
	public void enableDriver()
	{
		driverEnabled = true;
	}
	
	public short getOperationMode()
	{
		return 	(short)operCode;
	}
	
	public boolean simpleMode()
	{
		return false;
	}
	
	public void panelSizeChanged (int width, int height) {
		int oldwidth=getPanelWidth();
		int oldheight=getPanelHeight();
		double oldunit=getUnit();
		double unitwidth = oldwidth/oldunit;
		double unitheight = oldheight/oldunit;
		double newunit = (width/unitwidth<height/unitheight)?(width/unitwidth):(height/unitheight);
		configure.setProperty("panelWidth", Integer.toString((int)(newunit*unitwidth)));
		configure.setProperty("panelHeight", Integer.toString((int)(newunit*unitheight)));
		configure.setProperty("unit", Double.toString(newunit));
	}
	public String getMapFile ()
	{
		String mapfile = configure.getProperty("map");
		if (mapfile!=null)
			return "file:///"+mapfile;
		else
			return null;
	}
	public String getDumpFile ()
	{
		String dumpfile = configure.getProperty("dump");
		if (dumpfile!=null)
			return dumpfile;
		else
			return null;
	}
	public String getTargetFile ()
	{
		String targetfile = configure.getProperty("target");
		if (targetfile!=null)
			return targetfile;
		else
			return null;
	}
	public String getMapDir ()
	{
		String mapdir = configure.getProperty ("mapdir");
		if (mapdir!=null)
			return mapdir;
		else
			return null;
	}
	public long getRefreshPeriod()
	{
		String refreshPeriod = configure.getProperty ("refreshPeriod");
		long period = 50L; // Default value
		try {
			period = Long.parseLong(refreshPeriod);
		} catch (Exception e) {}
		return period;
	}
	
  public int getSumaryPanelWidth ()
  {
		String sumPanelWidth = configure.getProperty ("summaryPanelWidth");
		int width = 60; // Default value
		try {
			width = Integer.parseInt(sumPanelWidth);
		} catch (Exception e) {}
		return width;
  }
  public int getSumaryPanelHeight()
  {
		String sumPanelHeight = configure.getProperty ("summaryPanelHeight");
		int height = 48; // Default value
		try {
			height = Integer.parseInt(sumPanelHeight);
		} catch (Exception e) {}
		return height;
  }
	public int getPanelWidth()
	{
		String panelWidth = configure.getProperty ("panelWidth");
		int width = 680; // Default value
		try {
			width = Integer.parseInt(panelWidth);
		} catch (Exception e) {}
		return width;
	}
  public int getPanelHeight()
  {
		String panelHeight = configure.getProperty ("panelHeight");
		int height = 520; // Default value
		try {
			height = Integer.parseInt(panelHeight);
		} catch (Exception e) {}
		return height;
  }
	
  public double getUnit()
  {
		String unitString = configure.getProperty ("unit");
		double unit = 58.0; // Default value
		try {
			unit = Double.parseDouble(unitString);
		} catch (Exception e) {}
  	return unit;
  }

  public boolean displaySummary ()
  {
		String boolString = configure.getProperty ("displaySummary");
		boolean result = false; // Default value
		if (boolString!=null)
			result=Boolean.valueOf(boolString).booleanValue();
  	return result;
  }
  public boolean drawSensor ()
  {
		String boolString = configure.getProperty ("drawSensor");
		boolean result = true; // Default value
		if (boolString!=null)
			result=Boolean.valueOf(boolString).booleanValue();
  	return result;
  }
  public boolean drawSensorID ()
  {
		String boolString = configure.getProperty ("drawSensorID");
		boolean result = true; // Default value
		if (boolString!=null){
			System.out.println("drawSensorID="+boolString);
			result=Boolean.valueOf(boolString).booleanValue();
		}
  	return result;
  }
  
	public static void main (String[] args)
	{
		//String itransnetdir="C:/Program Files/Programming/cygwin/opt/tinyos-1.x/contrib/iTranSNet/tools/java";
		//String itransnetdir = Env.getenv("TOSROOT_WIN").replace('\\', '/')+"/contrib/iTranSNet/tools/java";

		String itransnetdir = "C:/tinyos/cygwin/opt/tinyos-1.x/contrib/iTranSNet/tools/java/";
		//String itransnetdir = "D:/wtp-its/workspace/ITS-tool/";
		System.out.println(itransnetdir);
		boolean driver = false;
		int num = 1;

		if (args.length >0) {
			for (int i=0; i<args.length; i++) {
				if (args[i].compareToIgnoreCase("-driver")==0)
					driver = true;
				else if (args[i].startsWith("-n="))
					try {
						num=Integer.parseInt(args[i].split("=")[1]);
					} catch (Exception e) {
						System.out.println("Invalid args ignored: "+args[i]);
					}
			}	
		}
		//debug
		//driver = true;
		
		
		SensorManager [] test = new SensorManager [num];
		Thread [] testThread = new Thread[num];
		for (int i=0; i<num; i++) {
			if (i==0)
				test[i] = new SensorManager(itransnetdir+"/its.properties");
			else
				test[i] = new SensorManager (null);
			if (driver)
				test[i].enableDriver();
			testThread[i] = new Thread (test[i]);
			testThread[i].start();
			try {
				Thread.sleep(10000);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	
}
