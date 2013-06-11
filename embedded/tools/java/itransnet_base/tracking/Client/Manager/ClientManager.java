package itransnet_base.tracking.Client.Manager;

import java.util.Properties;
import java.io.*;
// Client's data engine is similar to the server's
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Server.Manager.*;

public class ClientManager implements Manager
{
	// Map of the program
	private Map map;
	// A separate thread that will continually update the map
	private MapUpdater updater;

	// Configures
	private Properties configure;
	private String configFile="/its.properties";	
	
	public ClientManager()
	{
		// Load the configurations
		getConfigure();
		// Load the map
		map = new Map();
		// Load configures
		configure = new Properties();
		if (configFile!=null) {
			try {
				configure.load(getClass().getResourceAsStream(configFile));
			} catch (IOException e) {
			}
		}
		map.loadMap(getTargetFile());
		// Dispatch the thread
		updater = new MapUpdater(map);
		updater.setTargetFile(getTargetFile());
		
		Thread updateThread = new Thread (updater);
		updateThread.start();
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
		double unit = 40.0; // Default value
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
		if (boolString!=null)
			result=Boolean.valueOf(boolString).booleanValue();
  	return result;
  }
  
	public Map getMap () { return map; }
	// Including downloading files from server
	private void getConfigure ()
	{
	}
}
	
	
