package itransnet_base.tracking.Client.Manager;

import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
import java.util.Collections;

// Server's modules
// Client's data engine is similar to the server's
import itransnet_base.tracking.Server.DataEngine.*;

// Client's modules
import itransnet_base.tracking.Client.DataEngine.*;
import itransnet_base.tracking.Client.DataEngine.XML.*;

public class MapUpdater implements Runnable
{
	private Map map;
	private String targetFile;
	private CarLoader loader;
	//private ArrayList roadList;
	
	public MapUpdater (Map map)
	{
		this.map = map;
		//roadList = map.getRoad();
	}
	
	public void setTargetFile (String f)
	{
		targetFile = f;
		loader = new CarLoader (f);
	}
	
	public void run ()
	{
		while (true)
		{
			System.out.println("running ...");
			List carList = loader.getCarList();
			for (int i=0; i<carList.size(); i++)
			{
				SimpleCar c = (SimpleCar)carList.get(i);
				//System.out.println("Simple Car at" + c.getRoadID());
				Road r = findRoadInMap (c.getRoadID());

				//int idx = Collections.binarySearch(roadList, new Road (c.getRoadID()), new RoadComparator());
				if ( r!=null )
				{
					Car car = findCarInMap(c.getID());
					// New car
					if (car == null )
					{
						if (carInRegion(r,c.getPos()))
						{
							car = new Car (c.getID());
							car.setAverageSpeed(c.getSpeed());
							car.setLastPortionSpeed(c.getSpeed());
							car.setInstanceSpeed(c.getSpeed());
							car.setPos(c.getPos());
							car.setRoad(r);
							r.addCar (car);
						}
					}
					else
					{
						if(car.getAverageSpeed() != c.getSpeed())
						{
							car.setAverageSpeed(c.getSpeed());
							car.setLastPortionSpeed(c.getSpeed());
							car.setInstanceSpeed(c.getSpeed());
						}
						if (car.getPos() != c.getPos())
							car.setPos(c.getPos());
						if(car.getRoad().getID() != c.getRoadID())
						{
							Road oldRoad = car.getRoad();
							oldRoad.removeCar(car);
							car.setRoad(r);
							r.addCar(car);
						}
							
					} // end of else
				} // end of if
			} // end of for
			try{
				Thread.sleep(1000);
				Thread.yield();
			}
			catch (Exception e) {}
		} // End of while
	}
	
	private Car getCar (Road r, SimpleCar c)
	{
		if (r.getID()!=c.getRoadID())
			return null;
		List carList = r.getCar();
		
		for (int i=0; i<carList.size(); i++)
		{
			Car car = (Car)carList.get(i);
			if (car.getID() == c.getID())
				return car;
		}
		
		return null;
	}
	
	// Find a car in the map by its ID (brute force approach)
	private Car findCarInMap (int ID)
	{
		ArrayList roadList = map.getRoad();
		
		for (int i=0; i<roadList.size(); i++)
		{
			Road r = (Road)roadList.get(i);
			
			List carList = r.getCar();
			for (int j=0; j<carList.size(); j++)
			{
				Car c = (Car)carList.get(j);
				if (c.getID()==ID)
					return c;
			}
		}
		return null;
	}
	
	private Road findRoadInMap (int ID)
	{
		ArrayList roadList = map.getRoad();
		
		for (int i=0; i<roadList.size(); i++)
		{
			Road r = (Road)roadList.get(i);
			
			if (r.getID()==ID)
				return r;
		}
		return null;
	}
	
	private boolean carInRegion (Road r, double pos)
	{
		if (r.getEndCrossPoint()==null)
		{
			ArrayList sensor = r.getSensor();
			for (int i=0; i<sensor.size(); i++)
			{
				Sensor s = (Sensor)sensor.get(i);
				if(s.getPos()>=pos)
					return true;
			}
			return false;
		}
		else
			return true;
	}
	private class RoadComparator implements Comparator
	{
		public int compare (Object o1, Object o2)
		{
			return ((Road)o1).getID()-((Road)o2).getID();
		}
		public boolean equals (Object obj)
		{
			return obj.equals(this);
		}
	}
}