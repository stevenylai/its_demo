package itransnet_base.tracking.Server.DataEngine;

public class CarNotFoundException extends Exception
{
	public CarNotFoundException ()
	{
		super ("Cannot find any required car!!");
	}
}