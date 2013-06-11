package itransnet_base.tracking.Server.DataEngine;

import java.util.ArrayList;

import itransnet_base.tracking.Utility.*;

public class CrossRoad
{
	private int ID;
	
	// List of cars that will soon enter the cross road
	private ArrayList car;
	// List of road that the above car belongs to
	private ArrayList belongRoad;
	
	// Position of the crossroad
	private Coordinate position;
	
	// List of roads that start at this cross
	private ArrayList start;
	// List of roads that end at this cross
	private ArrayList end;
	
	public CrossRoad ()
	{
		car = new ArrayList();
		belongRoad = new ArrayList();
		start = new ArrayList();
		end = new ArrayList();
	}
	public CrossRoad (int ID)
	{
		this();
		this.ID = ID;
	}
	
	public ArrayList getStartList () { return start; }
	public ArrayList getEndList () { return end; }
	public ArrayList getCarList () { return car; }
	
	public void addStartRoad (Road r)
	{
		start.add(r);
	}
	
	public void addEndRoad (Road r)
	{
		end.add(r);
	}
	
	public void addCar(Car c, Road from){ car.add(c); belongRoad.add(from); }
	public Car removeFirstCar ()
	{
		if(car.size()>0)
		{
			Road ownerRoad = (Road)belongRoad.remove(0);
			Car returnCar = (Car)car.remove(0);
			ownerRoad.removeCar(returnCar);
			return returnCar;
		}
		else
			return null;
	}
	//public long getLastTime () { return lastTime; }
	//public void setLastTime (long t) { lastTime = t; }
}
