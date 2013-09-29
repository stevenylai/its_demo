package itransnet_base.tracking.Server.DataEngine;

import java.util.*;

import itransnet_base.tracking.Utility.*;

public class Road implements SensorConstants
{
	// Road's name, not necessarily unique

	private String name;
	// Road's ID for easy search
	private int ID;
	// Road's type: FIFO or LIFO
	private short type;
	// The position of the road
	private Coordinate start;
	private Coordinate end;

	// Road's length
	private double roadLength=0.0;
	// Road's inclination angle according to the panel
	private double incAngle=0.0;
	
	// Cross points with other roads
	private CrossRoad endCross;
	private CrossRoad startCross;
	
	private List car; // Cars on the road
	private List animatedCar; // Cars that will be drawn
	private ArrayList sensor; // Sensors on the road
	
	private int numOfCars; // number of cars reported by the START/END sensors

	// A list of neighboring roads (i.e. roads that with multiple lanes)
	private ArrayList neighbor;
	private short direction;
	
	public Road ()
	{
		// Dynamic lists that will be changed by multiple threads.
		car = Collections.synchronizedList(new ArrayList());
		animatedCar = Collections.synchronizedList(new ArrayList());
		type=FIFO_ROAD;
		// Static lists that will not be changed once initialized during start up
		sensor = new ArrayList();
		neighbor = new ArrayList ();
	}
	
	/*public Road (Coordinate start, Coordinate end)
	{
		this();
		this.start = start;
		this.end = end;
	}*/
	
	public Road (int ID)
	{
		this();
		this.ID = ID;
	}
	
	/** Set the start position of the road. */
	public void setStart (Coordinate s) { start = s; }
	/** Get the end position of the road. */
	public void setEnd (Coordinate e) { end = e; setDirection(); }

	/** Get the start position of the road. */	
	public Coordinate getStart(){ return start; }
	/** Get the end position of the road. */	
	public Coordinate getEnd(){ return end; }
	
	public int getID () { return ID; }
	public void setID (int ID) { this.ID = ID; }

	public int getNumOfCars() { return numOfCars; }
	public void setNumOfCars(int num) { numOfCars = num; }
	
	public String getName () { return name; }
	public void setName (String name) { this.name = name; }

	public short getType () { return this.type; }
	public void setType (short type) { this.type = type; }
	
	public Car getCarById(int id)
	{
		for (int i=0; i<car.size(); i++)
		{
			Car c = (Car)car.get(i);
			if(c.getID() == id)
				return c;
		}
		return null;
	}
	public double getLength ()
	{
		if(roadLength == 0.0)
		{
			if (start != null && end != null)
			{
				double x = Math.pow((start.getX()-end.getX()),2.0);
				double y = Math.pow((start.getY()-end.getY()),2.0);
				roadLength = Math.sqrt(x+y); //+1.0;
			}
		}
		return roadLength;
	}
	
	public void addNeighbor (Road r)
	{
		if (neighbor.indexOf (r)<0)
		{
			neighbor.add(r);
			r.addNeighbor(this);
		}
	}
	
	public ArrayList getNeighbor () { return neighbor; }
	
	public boolean isNeighbor (Road r)
	{
		if (neighbor.indexOf (r)<0)
			return false;
		else
			return true;
	}
	/**
	 *	Add a cross road point for the start of the road.
	 *	<p>
	 *	This method should be called during the construction of the map.
	 *	The start cross point probably doesn't require any kind of special monitoring
	 *	because all the car has just been monitored before passing the cross point.
	 *	The start cross point will probably be used to see where is the new car coming from.
	 *	@param	c	The cross road that will be added.
	 */
	public void addStartCrossPoint (CrossRoad c)
	{
		startCross = c;
		c.addStartRoad (this);
	}
	public CrossRoad getStartCrossPoint () { return startCross; }
	/**
	 *	Add a cross road point for the end of the road.
	 *	<p>
	 *	This method should be called during the construction of the map.
	 *	The end cross point is the place where the system should monitor
	 *	because if there are 2 different roads with a same cross point, drivers
	 *	must be careful so that they will not run into each other.
	 *	@param	c	The cross road that will be added.
	 */
	public void addEndCrossPoint (CrossRoad c)
	{
		endCross = c;
		c.addEndRoad (this);
	}
	public CrossRoad getEndCrossPoint () { return endCross; }
	public void addSensor (DefaultSensor s)
	{
		sensor.add(s);
		s.setRoad(this);
		sortSensor();
	}
	private void sortSensor ()
	{
		// Sort the sensor's list according to their positions
		Collections.sort(sensor, new Comparator ()
		{
			public int compare (Object o1, Object o2)
			{
				double result = ((Sensor)o1).getPos() - ((Sensor)o2).getPos();
				if (result>0.0)
					return 1;
				else if (result<0.0)
					return -1;
				else
					return 0;
			}
		});
	}
	public void addCar (Car c)
	{
		c.setRoad(this);
		car.add(c);
		
		if(c.getAnimatedCar() == null)
		{
    		System.out.println("New AnimatedCar...!!!" + c.getTurnDirection() + " road " + getID());
			AnimatedCar ac = new AnimatedCar(c);
			ac.setImageID(c.getID());
			animatedCar.add(ac);
			
		}
		else
		{
			System.out.println("update AnimatedCar...!!!" +c.getTurnDirection() + " road " + getID());
			c.getAnimatedCar().updatePos(Map.defaultMap);
		}
		

	}
	
	public void addAnimatedCar (AnimatedCar ac)
	{
		animatedCar.add(ac);
	}
	// Never sort cars!
	private void sortCar ()
	{
		// Sort the car's list according to their positions
		Collections.sort(car, new Comparator ()
		{
			public int compare (Object o1, Object o2)
			{
				double result = ((Car)o1).getPos() - ((Car)o2).getPos();
				if (result>0.0)
					return 1;
				else if (result<0.0)
					return -1;
				else
					return 0;
			}
		});
	}
	
	public void removeCar (Car c)
	{
		int vid = c.getID();
		for(int i = 0; i< car.size(); i++)
		{
			Car tc = (Car)car.get(i);
			if (tc.getID()== vid )
			{
				car.remove(i);
				break;
			}
		}
		/*
		if (idx>=0)
			car.remove(idx);
			*/
		// FIX ME !!!
		// Need to remove the sensor's dataLog as well
	}
	public void removeAnimatedCar(AnimatedCar c)
	{
		int idx = animatedCar.indexOf (c);
		animatedCar.remove(idx);
	}
	
	public ArrayList getSensor() { return sensor; }
	public List getCar() { return car; }
	public List getAnimatedCar() { return animatedCar; }

	/**
	 *	Get a car that has just covered the specified sensor.
	 *	<p>
	 *	Maybe this method should not be placed within Road class because Road class is mainly
	 *	responsible for storing data, not for algorithm such as searching
	 *	@param	s the sensor which will be examined
	 *	@return the car that meets the criteria.
	 */
	public Car getCarAt (Sensor s) throws CarNotFoundException
	{
		double pos = s.getPos();
		//sortCar();
		for (int i=0; i<car.size(); i++)
		{
			Car c = (Car)car.get(i);
			if (c.getPos()==pos)
				return c;
			else if (c.getPos()<pos)
				throw new CarNotFoundException();
		}
		throw new CarNotFoundException();
	} // end of getCarAt ()

	public Sensor getPreviousSensor (Sensor s)
	{
		int idx = sensor.indexOf(s);
		// We've found the previous sensor
		if (idx > 0)
			return (Sensor)sensor.get(idx-1);
		else
			return null;
	}

	public Sensor getPreviousSensor (double pos)
	{
		for (int i=sensor.size()-1; i>=0; i--)
		{
			Sensor s = (Sensor)sensor.get(i);
			if (s.getPos()<=pos)
				return s;
		}
		return null;
	}
	
	public Sensor getNextSensor (Sensor s)
	{
		int idx = sensor.indexOf(s);
		/*
			int idx = Collections.binarySearch(sensor, s,new Comparator ()
			{
				public int compare (Object o1, Object o2)
				{
					double result = ((Sensor)o1).getPos() - ((Sensor)o2).getPos();
					if (result>0.0)
						return 1;
					else if (result<0.0)
						return -1;
					else
						return 0;
				}
			});*/
			// We've found the previous sensor
			if (idx < sensor.size()-1)
				return (Sensor)sensor.get(idx+1);
			else
				return null;
	}
	public void setDirection()
	{
		if(start.getX() > end.getX())
			direction = DIRECTION_BACKWARD;
		if(start.getY() > end.getY())
			direction = DIRECTION_BACKWARD;
		direction = DIRECTION_FORWARD;
	}
	public short getDirection()
	{
		return direction;
	}
}
