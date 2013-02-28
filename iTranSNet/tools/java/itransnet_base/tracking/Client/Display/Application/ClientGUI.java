package itransnet_base.tracking.Client.Display.Application;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

// Server's modules
// Client's data engine is similar to the server's
import itransnet_base.tracking.Server.DataEngine.*;

// Client's modules
import itransnet_base.tracking.Client.Manager.*;
import itransnet_base.tracking.Server.Display.*;

public class ClientGUI extends JFrame implements WindowListener, Runnable
{
	private ClientManager mgr;
	private Map map;
	private DisplayPanel dp;
	
	public ClientGUI()
	{
		super ("Client Panel");
		// The client manager will take care of all the configurations.
		mgr = new ClientManager();
		
		// Now the map is updated
		map = mgr.getMap();
		dp = new DisplayPanel(mgr);
	}
	
	public void run()
	{
    Container c = getContentPane();    // default BorderLayout used
    c.add(dp, "Center");
    addWindowListener(this);
    pack();
    setResizable(false);
    setVisible(true);
	}
  public void windowActivated(WindowEvent e) 
  { dp.resumeGame();  }

  public void windowDeactivated(WindowEvent e) 
  {  dp.pauseGame();  }


  public void windowDeiconified(WindowEvent e) 
  {  dp.resumeGame();  }

  public void windowIconified(WindowEvent e) 
  {  dp.pauseGame(); }


  public void windowClosing(WindowEvent e)
  {  dp.stopGame();  }


  public void windowClosed(WindowEvent e) {}
  public void windowOpened(WindowEvent e) {}
  
	public static void main (String args [])
	{
		ClientGUI gui = new ClientGUI();
		Thread test = new Thread (gui);
		test.start();
	}
}