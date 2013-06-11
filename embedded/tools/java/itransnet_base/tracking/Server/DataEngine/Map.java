// Roads.java
package itransnet_base.tracking.Server.DataEngine;

import java.awt.*;
import java.util.*;

import itransnet_base.tracking.Utility.*;
import itransnet_base.tracking.Server.DataEngine.XML.*;

/**
 * Manage and process most of the data in the program.
 * <p>
 * The map maintains a set of roads in the program.
 * For each of the road, it keeps a list of sensors placed on the road.
 * It also keeps track of the cars running on the road.
 */
public class Map
{
  public static Map defaultMap=new Map();
 
  private ArrayList errorList=new ArrayList();
  
  
  private ArrayList road;    // All the roads information
  // Table to look up which road the sensor belongs to.
  // Key: Senser's ID. Value: Road
  private Hashtable sensorTable;
  
  private ArrayList cars; // Cars on the road

  MapLoader loader;
	
	/**
	 * Construct a simple map that has 2 roads and 4 sensors
	 * for a simple demonstration.
	 */
  public Map()
  {
  	// Construct the road list
    road = new ArrayList();
  	cars = new ArrayList();
    sensorTable = new Hashtable();

	loader = new MapLoader (this);
	//loadMap ("C:/UCB/cygwin/opt/tinyos-1.x/contrib/iTranSNet/tools/java/itransnet_base/tracking/map.xml");
	//loadMap ("D:/wtp-its/ITS-tool/itransnet_base/tracking/map.xml");
	loadMap ("C:/map.xml");
	
	//errorList.add("1");
	//errorList.add("2");
  }

	public void loadMap (String f)
	{
		loader.setFile(f);
		loader.loadMap();
	}
	
	public void addSensor (Sensor s) {	sensorTable.put(new Integer(s.getID()), s); }
	public void addRoad (Road r) { road.add (r); }
	
	public int numOfSensors () { return sensorTable.size(); }
	public ArrayList getRoad () { return road; }
	public Sensor getSensor(int ID){ 
		//System.out.println("----");
		//System.out.println(sensorTable);
		//System.out.println(sensorTable.keySet());
		return (Sensor)sensorTable.get(new Integer(ID)); 
	}

	public void addCar(Car c) 
	{
		cars.add(c);
	}
	public ArrayList getCars() {return cars;}
	public boolean isNewCar(int vid)
	{
		for(int i = 0; i < cars.size(); i++)
		{
			Car tc = (Car)cars.get(i);
			if(tc.getID() == vid)
				return false;
		}
		return true;
	}
	public synchronized  void updateCar(Road r, int vid, double pos,int turningDirection)
	{
		Car c = r.getCarById(vid);	
		if(c == null) //changed road...
		{
			System.out.println("changed road...road"+r.getID()+";vid="+vid);	
			Car tc;
			for(int i = 0; i < cars.size(); i++)
			{
				tc = (Car)cars.get(i);
				if(tc.getID() == vid)
				{
					System.out.println("found car...."+tc.getID());	
					Road tr = tc.getRoad();
					tr.removeCar(tc);
					//System.out.println("Updated road!!! previous: " + tc.getRoad().getID() + ": " + tc.getPos() + " now " + r.getID()  + ": " +  pos);
					System.out.println("change turningDirection"+turningDirection);	
					tc.setTurnDirection(turningDirection);
					tc.setRoad(r, pos);					
					r.addCar(tc);
					
					break;
				}
			}
		}
		else
		{
			System.out.println("Updated pos: pos="+pos+",turningDirection="+turningDirection);			
			c.setTurnDirection(turningDirection);
			c.setPos (pos);
		}
	}

	public ArrayList getErrorList() {
		return errorList;
	}

	public void setErrorList(ArrayList errorList) {
		this.errorList = errorList;
	}


}  // end of Obstacles class
