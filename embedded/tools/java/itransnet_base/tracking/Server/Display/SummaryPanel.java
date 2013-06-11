package itransnet_base.tracking.Server.Display;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;
import java.util.ArrayList;

import itransnet_base.tracking.Server.Manager.*;
import itransnet_base.tracking.Server.DataEngine.*;

public class SummaryPanel extends JPanel implements Runnable
{
	private Map map;
	
  private Thread animator;           // the thread that performs the animation
	private boolean isPaused, running;
	
  private static int PWIDTH = 50;   // size of panel
  private static int PHEIGHT = 40;
  
	private ArrayList numLabels;
	
	public SummaryPanel (Manager mgr)
	{
		this.map = mgr.getMap();
		
    PWIDTH = mgr.getSumaryPanelWidth();
    PHEIGHT = mgr.getSumaryPanelHeight();
    setPreferredSize( new Dimension(PWIDTH, PHEIGHT));
		isPaused=false;
		running=false;
	}
	
	public void run ()
	{
		createScreen();
		running = true;
		while(running)
		{
			updateScreen ();
			try {
				Thread.sleep(500);
			} catch (Exception e) {}
		}
	}
	private void createScreen()
	{
		ArrayList road = map.getRoad();
		
		numLabels = new ArrayList(road.size());

		// Create layout
		setLayout(new GridLayout(road.size(), 2));
		
		// Initialize all GUI
		for (int i=0; i<road.size(); i++)
		{
			Road r = (Road)road.get(i);
			// Road name
			JLabel jlRoad = new JLabel(r.getName());
			add(jlRoad);
			
			// Number of cars
			int num = getNumOfCars(r);
			JLabel jlNum = new JLabel(Integer.toString(num));
			numLabels.add(jlNum);
			add(jlNum);
		}
		
		//pack();
		//setVisible(true);
	}

  public void addNotify()
  // wait for the JPanel to be added to the JFrame before starting
  { super.addNotify();   // creates the peer
    startGame();         // start the thread
  }
  
  public void startGame()
  // initialise and start the thread 
  { 
    if (animator == null || !running) {
      animator = new Thread(this);
			animator.start();
    }
  } // end of startGame()
  
	private void updateScreen ()
	{
		ArrayList road = map.getRoad();
		// Initialize all GUI
		for (int i=0; i<road.size(); i++)
		{
			Road r = (Road)road.get(i);
			// Number of cars
			int num = getNumOfCars(r);
			//System.out.println(r.getName()+"has cars: "+num);
			JLabel jlNum = (JLabel)numLabels.get(i);
			jlNum.setText(Integer.toString(num));
		}
	}
	
	private int getNumOfCars (Road r)
	{
		if (r.getCar().size()>0)
			return r.getCar().size();
		else if (r.getNumOfCars()<0)
			return 0;
		else
			return r.getNumOfCars();
	}
	
  public void resumeGame()
  // called when the JFrame is activated / deiconified
  {  isPaused = false;  } 


  public void pauseGame()
  // called when the JFrame is deactivated / iconified
  { isPaused = true;   } 


  public void stopGame() 
  // called when the JFrame is closing
  {  running = false;   }
}