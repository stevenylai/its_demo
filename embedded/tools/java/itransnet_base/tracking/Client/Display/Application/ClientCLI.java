package itransnet_base.tracking.Client.Display.Application;

import java.awt.*;
import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

// Server's modules
// Client's data engine is similar to the server's
import itransnet_base.tracking.Server.DataEngine.*;

// Client's modules
import itransnet_base.tracking.Client.Manager.*;

public class ClientCLI implements Runnable
{
	private ClientManager mgr;
	private Map map;

	public ClientCLI()
	{
		// The client manager will take care of all the configurations.
		mgr = new ClientManager();
		// Now the map is updated
		map = mgr.getMap();
	}
	
	public void run ()
	{
		while (true)
		{
			ArrayList road = map.getRoad();
			for (int i=0; i<road.size(); i++)
			{
				Road r = (Road)road.get(i);
				System.out.println(r.getName()+": "+r.getAnimatedCar().size());
				
				java.util.List carList = r.getAnimatedCar();
				for (int j=0; j<carList.size(); j++)
				{
					AnimatedCar c = (AnimatedCar)carList.get(j);
					c.rendered();
					//System.out.println("Animated: "+c);
					//System.out.println("real: "+c.getRealCar()+"\n");
				}
			}
			try {
				Thread.sleep(1000);
				Thread.yield();
			}
			catch (Exception e)
			{ }
		}
	}
	
	public static void main (String args[])
	{
		ClientCLI test = new ClientCLI ();
		Thread testThread = new Thread(test);
		testThread.start();
	}
}