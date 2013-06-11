package itransnet_base.tracking.Client.DataEngine;

public class SimpleCar 
{
	private int ID;
	private double pos;
	private int roadID;
	private double speed;
	
	public void setID (int ID) { this.ID = ID; System.out.println("settttt");}
	public void setPos (double pos) { this.pos = pos; }
	public void setRoadID (int ID) { roadID = ID; }
	public void setSpeed (double s) { speed = s; }
	
	public int getID () { return ID; }
	public double getPos () { return pos; }
	public int getRoadID () { return roadID; }
	public double getSpeed () { return speed; }
	public String toString () { return "Car: "+ID+" Road: "+roadID+" Pos: "+pos; }
}