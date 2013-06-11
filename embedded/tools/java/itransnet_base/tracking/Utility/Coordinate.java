package itransnet_base.tracking.Utility;

public class Coordinate
{
	private static int scale = 1;
	private static double hscale = 600, wscale = 800;
	private double x,y;
	
	public Coordinate (double x, double y)
	{
		this.x = x;
		this.y = y;

	}
	
	synchronized public void setScale (int s) {scale = s;}
	synchronized public void setHeightScale (double s) {hscale = s; System.out.println("height set as" + s);}
	synchronized public void setWidthScale (double s) {wscale = s; System.out.println("width set as" + s);}
	
	public double getX () {return x*wscale;}
	public double getY () {return y*hscale;}
	
	public double getScaledX () {return x;}
	public double getScaledY () {return y;}
}
