package itransnet_base.tracking.Client.Display.Applet;

import java.awt.*;
import javax.swing.*;

// Server's modules
// Client's data engine is similar to the server's
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Server.Display.*;

// Client's modules
import itransnet_base.tracking.Client.Manager.*;
import itransnet_base.tracking.Client.DataEngine.*;

public class ClientGUISummary extends JApplet
{
	private ClientManager mgr;
	private Map map;
	private SummaryPanel dp;
	
	public void init()
	{
		// The client manager will take care of all the configurations.
		mgr = new ClientManager();
		
		// Now the map is updated
		map = mgr.getMap();
		dp = new SummaryPanel(mgr);
		
    Container c = getContentPane();
    c.setLayout( new BorderLayout() );
		c.add(dp, "Center");
    dp.resumeGame();
	}
   public void start()
   {  dp.resumeGame();  }

   public void stop()
   {  dp.pauseGame();  }

   public void destroy()
   {  dp.stopGame();  }
}