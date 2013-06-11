
// WormChase.java
// Andrew Davison, April 2005, ad@fivedots.coe.psu.ac.th

/* A worm moves around the screen and the user must
   click (press) on its head to complete the game.

   If the user misses the worm's head then a blue box
   will be added to the screen (if the worm's body was
   not clicked upon).

   A worm cannot move over a box, so the added obstacles
   *may* make it easier to catch the worm.

   A worm starts at 0 length and increases to a maximum
   length which it keeps from then on.

   A score is displayed on screen at the end, calculated
   from the number of boxes used and the time taken. Less
   boxes and less time mean a higher score.

   -------------
   
   The display includes two textfields for showing the current time
   and number of boxes. The average FPS/UPS values are drawn in
   the game's JPanel.

   Pausing/Resuming/Quiting are controlled via the frame's window
   listener methods.

   Uses active rendering to update the JPanel.

   Using Java 3D's timer: J3DTimer.getValue()
     *  nanosecs rather than millisecs for the period

   Average FPS / UPS
				20			50			80			100
   Win 98:    20/20       48/50       81/83       96/100
   Win 2000:  20/20       43/50       59/83       58/100    // slow machine
   Win XP:    20/20       50/50       83/83      100/100
*/
package itransnet_base.tracking.Server.Display;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;
import java.util.ArrayList;

import itransnet_base.tracking.Server.Manager.*;
import itransnet_base.tracking.Server.DataEngine.*;

public class MainWindow extends JFrame implements WindowListener, Runnable, PanelListener, ComponentListener
{
	private SensorManager mgr;
	
  private DisplayPanel dp;        // where everything is drawn

  private JTextField jtfFPS;   // displays FPS
  private JTextField jtfUPS;  // displays UPS
  private static int MAX_VIDS = 32;
  private AlertWindow [] alert;
  private int [] alertIdx;
  private int [] alertSta;
  private static int numVids;
  
  private static boolean first = true;
  private int lastx, lasty;
	// Format for displaying UPS/FPS
  private DecimalFormat df = new DecimalFormat("0.##");  // 2 dp

  public MainWindow(SensorManager mgr)
  { super("Map Display");
  	this.mgr = mgr;
  }  // end of WormChase() constructor

	public void run()
	{
		if(first)
		{
			alertIdx = new int[MAX_VIDS];
			alertSta = new int[MAX_VIDS];
			alert = new AlertWindow[MAX_VIDS];;
			for(int i = 0; i < MAX_VIDS; i++)
			{
				lastx = lasty = 320;
				alert[i] = new AlertWindow((SensorManager)(this.mgr));
				alert[i].setLocation(lastx, lasty);
				alert[i].setResizable(false);

			}
			first = false;
		}
		makeGUI();

    addWindowListener(this);
		addComponentListener(this);
    pack();
    setResizable(false);
    setVisible(true);
	setSize(900, 735);
    
    //Thread t = new Thread(new ConfigureWindow(mgr));
    //t.start();
	}
	public void startAlertWindow(String err, int vid)
	{
		//dp.gameUpdate();
		//dp.paintScreen();
		//if(Map.defaultMap.getErrorList()!=null && Map.defaultMap.getErrorList().size()>0)
        alert[vid].dispose();
		alert[vid].setErrStr(err);
		Thread driverThread = new Thread (alert[vid]);
		driverThread.start();
		java.awt.Toolkit.getDefaultToolkit().beep();

	}
	public void closeAlertWindow(int vid)
	{
		alert[vid].dispose();
		
	}
  private void makeGUI()
  {
    Container c = getContentPane();    // default BorderLayout used

    dp = new DisplayPanel(mgr);
    dp.setPanelListener(this);
    
    c.add(dp, "Center");

    JPanel ctrls = new JPanel();   // a row of textfields
    ctrls.setLayout(new BoxLayout(ctrls, BoxLayout.X_AXIS));

    jtfFPS = new JTextField("FPS: 0");
    jtfFPS.setEditable(false);
    ctrls.add(jtfFPS);

    jtfUPS = new JTextField("UPS: 0");
    jtfUPS.setEditable(false);
    ctrls.add(jtfUPS);

    c.add(ctrls, "South");
  }  // end of makeGUI()

  public void setFPS(double fps)
  {  jtfFPS.setText("FPS: " + df.format(fps));  }

  public void setUPS(double ups)
  {  jtfUPS.setText("UPS: " + df.format(ups)); }
  
  public SensorManager getManager () {return mgr;}
  public void mapChanged(SensorManager mgr)
  {
  	dp.setMap(mgr.getMap());
  }
  // ----------------- window listener methods -------------

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
  // ----------------------------------------------------

	// ------------------ component listener methods ------------------
	public void componentResized(ComponentEvent e) {
		int pw = dp.getWidth();
		int ph = dp.getHeight();
		mgr.panelSizeChanged(pw, ph);
	}
	public void componentHidden(ComponentEvent e) {}
	public void componentShown(ComponentEvent e) {}
	public void componentMoved(ComponentEvent e) {}
	// ----------------------------------------------------------------

} // end of MainWindow class


