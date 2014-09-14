package itransnet_base.tracking.Server.DataEngine;

import itransnet_base.tracking.Utility.*;

public class Car implements SensorConstants
{
	// Used to automatically generate unique ID for each car
	private static int IDcount = 1;

	private int ID;	// ID of the car
	private Road road; // The road it belongs to
	private double pos; // Real position of the car
	private short direction; // Moving direction of the car
	
	private int turnDirection=-1;

	// Various kinds of speed measurement of the car
	private double averageSpeed; // speed measured from the total distance
	private double lastPortionSpeed; // Speed measured from last 2 sensors
	private double instanceSpeed; // Speed measured instantly
	
	private long entranceTime; // Time when the car appear in the system
	private double totalDistance; // Total distance the car has traveled
	
	// For animation purpose:
	private AnimatedCar fakeCar;
	private Map map=new Map();
	public Car ()
	{
		//ID = IDcount;
		//IDcount ++;
		ID = 0;
		totalDistance = 0.0;
		averageSpeed = lastPortionSpeed = instanceSpeed = 0.0;
		entranceTime = System.currentTimeMillis();
		direction = DIRECTION_FORWARD;
		turnDirection=2;
	}

	public Car (int ID)
	{
		this.ID = ID;
		totalDistance = 0.0;
		averageSpeed = lastPortionSpeed = instanceSpeed = 0.0;
		entranceTime = System.currentTimeMillis();
		turnDirection=2;
	}

	public void setRoad (Road r, double initposition) {
	    road = r;
	    pos = initposition;
	    setDirection(r.getDirection());
	    if(fakeCar!=null)
		fakeCar.updatePos(map);
	}
	public void setRoad (Road r) { road = r; if(fakeCar!=null)fakeCar.updatePos(map);}
	public void setAnimatedCar (AnimatedCar ac) {fakeCar = ac;}
	
	public void setDirection (short d) { direction = d; }
	public short getDirection () { return direction; }

	public void setAverageSpeed (double s) { averageSpeed = s; if(fakeCar!=null)fakeCar.updateSpeed();}
	public void setLastPortionSpeed (double s) { lastPortionSpeed = s; if(fakeCar!=null)fakeCar.updateSpeed();}
	public void setInstanceSpeed (double s) { instanceSpeed = s; if(fakeCar!=null)fakeCar.updateSpeed();}
	
	public void setPos (double pos)
	{
		// Update the total distance first
		if (pos > this.pos)
			totalDistance = totalDistance + pos - this.pos;
//		System.out.println("setPOSition~~~~~~~~~~~~~~~~~~~~`````````");
		this.pos = pos;
		
		if(fakeCar!=null)
			fakeCar.updatePos(map);
		
	}
	
	public int getID () {return ID;}
	public void setID (int vid) {ID = vid;}
	public Road getRoad () { return road; }

	public AnimatedCar getAnimatedCar () { return fakeCar; }
	
	public double getAverageSpeed () {return averageSpeed; }
	public double getLastPortionSpeed () {return lastPortionSpeed; }
	public double getInstanceSpeed () {return instanceSpeed; }
	public double getGrandSpeed () {return 0.8*getInstanceSpeed()+0.1*(getAverageSpeed () + getLastPortionSpeed ());}
	
	public double getPos () { return pos; }
	
	public long getEntranceTime() { return entranceTime; }
	public double getTotalDistance () { return totalDistance; }
	
	// Get the length of the car
	public double getLength () { return 0.0; }
	
	public String toString () { 
		return "Car: " + ID + " Road: " + road.getID() + " Pos: "+pos +
		/*" A/S: " + averageSpeed + " L/S: " + lastPortionSpeed +*/ " I/S: " + instanceSpeed;
	}

	public int getTurnDirection() {
		return turnDirection;
	}

	public void setTurnDirection(int turnDirection) {
		this.turnDirection = turnDirection;
	}
}
