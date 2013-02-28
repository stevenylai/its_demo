package itransnet_base.tracking.Server.Display;

// DisplayPanel.java
// Implemented from Andrew Davison's GamePanel framework in the book:
// 'Killer Game Programming in Java'

/* The game's drawing surface. It shows:
     - the moving objects on the road
     - the roads
     - the sensors
     - the current average FPS and UPS
*/

import itransnet_base.tracking.Server.DataEngine.AnimatedCar;
import itransnet_base.tracking.Server.DataEngine.DefaultSensor;
import itransnet_base.tracking.Server.DataEngine.Map;
import itransnet_base.tracking.Server.DataEngine.Road;
import itransnet_base.tracking.Server.Manager.Manager;
import itransnet_base.tracking.Server.Manager.SensorDriver;
import itransnet_base.tracking.Server.Manager.SensorManager;
import itransnet_base.tracking.Utility.Coordinate;
import itransnet_base.tracking.Utility.SensorConstants;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class DisplayPanel extends JPanel implements Runnable, SensorConstants
{
	// Variables configured by configurer
  private static int PWIDTH = 500;   // size of panel
  private static int PHEIGHT = 400;
  private long period;                // period between drawing in _nanosecs_


	//private static long MAX_STATS_INTERVAL = 1000000000L;
	private static long MAX_STATS_INTERVAL = 1000L;
    // record stats every 1 second (roughly)

  private static final int NO_DELAYS_PER_YIELD = 16;
  /* Number of frames with a delay of 0 ms before the animation thread yields
     to other running threads. */

  private static int MAX_FRAME_SKIPS = 5;   // was 2;
    // no. of frames that can be skipped in any one animation loop
    // i.e the games state is updated but not rendered

  private static int NUM_FPS = 10;
     // number of FPS values stored to get an average


  // used for gathering statistics
  private long statsInterval = 0L;    // in ns
  private long prevStatsTime;   
  private long totalElapsedTime = 0L;
  private long gameStartTime;
  private int timeSpentInGame = 0;    // in seconds

  private long frameCount = 0;
  private double fpsStore[];
  private long statsCount = 0;
  private double averageFPS = 0.0;

  private long framesSkipped = 0L;
  private long totalFramesSkipped = 0L;
  private double upsStore[];
  private double averageUPS = 0.0;


  private DecimalFormat df = new DecimalFormat("0.##");  // 2 dp
  private DecimalFormat timedf = new DecimalFormat("0.####");  // 4 dp


  private Thread animator;           // the thread that performs the animation
  private boolean running = false;   // used to stop the animation thread
  private boolean isPaused = false;


	// Project related modules
  private Manager mgr;
  private Map map;
  private PanelListener listener;
  private ImagesLoader imsLoader;
  // Not used now.
	private ImageSFXs imageSfx;
  private final static String IMS_FILE = "imsInfo.txt";
	
  // used at game termination
  private int score = 0;
  private Font font;
  private FontMetrics metrics;

  // off screen rendering
  private Graphics dbg; 
  private Image dbImage = null;
  
  private BufferedImage bridge1 = new BufferedImage(30, 50,BufferedImage.TYPE_INT_ARGB);
  private BufferedImage bridge2 = new BufferedImage(30, 50,BufferedImage.TYPE_INT_ARGB);
  private BufferedImage bridge3 = new BufferedImage(30, 50,BufferedImage.TYPE_INT_ARGB);
  
  public DisplayPanel(Manager mgr)
  {
  	// Need the manager to get the map and various kinds of system settings.
    this.mgr = mgr;
    map = mgr.getMap();
   
	getSettings();
    setBackground(Color.white);

    // load and initialize the images
    imsLoader = new ImagesLoader(IMS_FILE); 
    imageSfx = new ImageSFXs();

    setFocusable(true);
		requestFocus();    // the JPanel now has focus, so receives key events
		readyForTermination();

    // initialise timing elements
    fpsStore = new double[NUM_FPS];
    upsStore = new double[NUM_FPS];
    for (int i=0; i < NUM_FPS; i++) {
      fpsStore[i] = 0.0;
      upsStore[i] = 0.0;
    }
    
    try {
		bridge1=ImageIO.read(new File("c:/bridge1.JPG"));
		bridge2=ImageIO.read(new File("c:/bridge2.JPG"));
		bridge3=ImageIO.read(new File("c:/bridge3.JPG"));
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    System.out.println("Create Birdge successful") ;  
    
  }  // end of DisplayPanel()

	public void setMap (Map map)
	{
		this.map = map;
	}

	public void setPanelListener (PanelListener listener)
	{
		this.listener = listener;
	}
	
  private void readyForTermination()
  {
	addKeyListener( new KeyAdapter() {
	// listen for esc, q, end, ctrl-c on the canvas to
	// allow a convenient exit from the full screen configuration
       public void keyPressed(KeyEvent e)
       { int keyCode = e.getKeyCode();
         if ((keyCode == KeyEvent.VK_ESCAPE) || (keyCode == KeyEvent.VK_Q) ||
             (keyCode == KeyEvent.VK_END) ||
             ((keyCode == KeyEvent.VK_C) && e.isControlDown()) ) {
           running = false;
         }
       }
     });
  }  // end of readyForTermination()


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
    

  // ------------- game life cycle methods ------------
  // called by the JFrame's window listener methods


  public void resumeGame()
  // called when the JFrame is activated / deiconified
  {  isPaused = false;  } 


  public void pauseGame()
  // called when the JFrame is deactivated / iconified
  { isPaused = true;   } 


  public void stopGame() 
  // called when the JFrame is closing
  {  running = false;   }

  // ----------------------------------------------

	private void getSettings() {
		// Get settings from Manager
   	period = mgr.getRefreshPeriod();
	if(PWIDTH == mgr.getPanelWidth() && PHEIGHT == mgr.getPanelHeight())
		return;
    PWIDTH = mgr.getPanelWidth();
  	PHEIGHT = mgr.getPanelHeight();
		Coordinate dummy = new Coordinate(0,0);
		System.out.println("height width resettt");
		dummy.setWidthScale((double)PWIDTH );
		dummy.setHeightScale((double)PHEIGHT);

	  setPreferredSize( new Dimension(PWIDTH, PHEIGHT));
    // set up message font
    font = new Font("SansSerif", Font.BOLD, (int)(mgr.getUnit()/2));
    metrics = this.getFontMetrics(font);

	}
  public void run()
  /* The frames of the animation are drawn inside the while loop. */
  {
    long beforeTime, afterTime, timeDiff, sleepTime;
    long overSleepTime = 0L;
    int noDelays = 0;
    long excess = 0L;

    gameStartTime = System.currentTimeMillis();
    prevStatsTime = gameStartTime;
    beforeTime = gameStartTime;

		running = true;

		while(running) {
			getSettings();
			gameUpdate();
			gameRender();
			paintScreen();

			/********Statistics related procedures. DO NOT modify!**********/
      afterTime = System.currentTimeMillis();
      timeDiff = afterTime - beforeTime;
      sleepTime = (period - timeDiff) - overSleepTime;  

      //for debug
      sleepTime=1000;
      
      if (sleepTime > 0) {   // some time left in this cycle
        try {
          Thread.sleep(sleepTime);
        }
        catch(InterruptedException ex){}
        overSleepTime = (System.currentTimeMillis() - afterTime) - sleepTime;
      }
      else {    // sleepTime <= 0; the frame took longer than the period
        excess -= sleepTime;  // store excess time value
        overSleepTime = 0L;

        if (++noDelays >= NO_DELAYS_PER_YIELD) {
          Thread.yield();   // give another thread a chance to run
          noDelays = 0;
        }
      }

      beforeTime = System.currentTimeMillis();

      /* If frame animation is taking too long, update the game state
         without rendering it, to get the updates/sec nearer to
         the required FPS. */
      int skips = 0;
      while((excess > period) && (skips < MAX_FRAME_SKIPS)) {
        excess -= period;
	    	gameUpdate();    // update state but don't render
        skips++;
      }
      framesSkipped += skips;

      storeStats();
	}

    printStats();
    /********************************************************/

    System.exit(0);   // so window disappears
  } // end of run()


  private void gameUpdate() 
  {
  	// Game is always paused in applet so just remove this;
  	//if (!isPaused)
  		//return;
		ArrayList roads = map.getRoad();
		for (int i=0; i<roads.size(); i++)
		{
			Road r = (Road)roads.get(i);
			java.util.List animatedCar = r.getAnimatedCar();
			//System.out.println("Animated car no.: "+animatedCar.size());
			for(int j=0; j<animatedCar.size(); j++)
			{
				AnimatedCar c = (AnimatedCar)animatedCar.get(j);
				if(c.readyForRender())
					c.rendered(map);
				//System.out.println("Car updated: "+c);
			}
		}
  }  // end of gameUpdate()


  private void gameRender()
  {
	  	
    if (dbImage == null||dbImage.getWidth(null)!=PWIDTH||dbImage.getHeight(null)!=PHEIGHT){
      dbImage = createImage(PWIDTH, PHEIGHT);
      if (dbImage == null) {
        System.out.println("dbImage is null");
        return;
      }
      else
        dbg = dbImage.getGraphics();
    }

    // clear the background
    dbg.setColor(Color.green);
    dbg.fillRect (0, 0, PWIDTH, PHEIGHT);
    


	dbg.setColor(Color.blue);
    dbg.setFont(font);

		if (listener != null)
		{
			// report frame count & average FPS and UPS
			listener.setUPS(averageUPS);
			listener.setFPS(averageFPS);
		}
		
		dbg.setColor(Color.black);

    // draw game elements: the map
    drawMap(dbg);
  }  // end of gameRender()

	// Hard coded to draw 2 roads only. It will be modified in the future
	private void drawMap(Graphics dbg)
	{
		dbg.setColor(Color.YELLOW);
		
		double startX = 0;
		double startY = 0;
		
		BufferedImage pic = imsLoader.getImage("real_map");
		
		dbg.drawImage(pic, 0, 0, (int)PWIDTH, (int)PHEIGHT, null);
		
		ArrayList roads = map.getRoad();

		// 1. Draw the roads
		//for (int i=0; i<roads.size(); i++)
		//	drawRoad (dbg, (Road)roads.get(i));
		// 2. Draw the sensors on each road
		//if (mgr.drawSensor())
		//{
		//	for (int i=0; i<roads.size(); i++)
		//		drawSensor (dbg, (Road)roads.get(i));
		//}
		// 3. Draw the cars
		for (int i=0; i<roads.size(); i++)
			drawCar(dbg, (Road)roads.get(i));
		
	}
	
	/**
	 *	draw a single road on the map
	 *	<p>
	 *	Road's information: startX, startY, endX, endY.
	 *	1. draw a circle at the start point
	 *	2. draw a circle at the end point
	 *	3. calculate angle = arctan((endY-startY)/(endX-startX))
	 *	4. use angle to find out the four points for the road
	 *	5. draw a polygon using these points.
	 */

	/**
	 *	draw all the sensors on a single road
	 *	<p>
	 *	Road's information: startX, startY, endX, endY.
	 *	For each iteration, use the following steps to draw the sensor:
	 *	1. calculate the centre coordinate of the sensor
	 *	2. Draw a small circle around the center
	 */
	private void drawSensor (Graphics dbg, Road r)
	{
		double startX = r.getStart().getX();
		double startY = r.getStart().getY();
		double endX = r.getEnd().getX();
		double endY = r.getEnd().getY();
		ArrayList sensor = r.getSensor();
		double unit = mgr.getUnit();
		double halfunit = 0.5*unit;
		
		for (int i=0; i<sensor.size(); i++)
		{
			DefaultSensor s = (DefaultSensor)sensor.get(i);
			
			// Adjust sensor's color
			if (s.getLastData() == SENSOR_UNCOVERED)
				dbg.setColor(Color.GREEN);
			else
				dbg.setColor(Color.RED);
			
			if (endX != startX && endY != startY)
			{
				// Step1
				double sensorX = (Math.abs(startX-endX))*s.getPercent();
				if(startX<endX)
					sensorX = startX - halfunit + sensorX;
				else
					sensorX = startX - halfunit - sensorX;

				double sensorY = (Math.abs(startY-endY))*s.getPercent();
				if(startY<endY)
					sensorY = startY - halfunit + sensorY;
				else
					sensorY = startY - halfunit - sensorY;
				// Step 2
				dbg.fillOval((int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit), (int)(unit/2), (int)(unit/2));
				if (mgr.drawSensorID())
					dbg.drawString(Integer.toString(s.getID()), (int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit));
			}
			// Special case handling (road that lies horizontally)
			else if (endX != startX && endY == startY)
			{
				double sensorX = (Math.abs(startX-endX))*s.getPercent();
				if(startX<endX)
					sensorX = startX - halfunit + sensorX;
				else
					sensorX = startX - halfunit - sensorX;

				double sensorY = startY-halfunit;
				dbg.fillOval((int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit), (int)(unit/2), (int)(unit/2));
				if (mgr.drawSensorID())
					dbg.drawString(Integer.toString(s.getID()), (int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit));
			}
			// Special case handling (road that lies vertically)
			else if (endX == startX && endY != startY)
			{
				double sensorX = startX-halfunit;
				double sensorY = (Math.abs(startY-endY))*s.getPercent();
				if(startY<endY)
					sensorY = startY - 0.5 + sensorY;
				else
					sensorY = startY - 0.5 - sensorY;

				dbg.fillOval((int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit), (int)(unit/2), (int)(unit/2));
				if (mgr.drawSensorID())
					dbg.drawString(Integer.toString(s.getID()), (int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit));
			}
			// Should not happen (road that is just a single point)
			else
			{
				double sensorX = startX - 0.5;
				double sensorY = startY - 0.5;
				dbg.fillOval((int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit), (int)(unit/2), (int)(unit/2));
				if (mgr.drawSensorID())
					dbg.drawString(Integer.toString(s.getID()), (int)((sensorX-0.25)*unit),(int)((sensorY-0.25)*unit));
			}
		}
	} // end of drawSensor()
	
	private void drawCar(Graphics dbg, Road r)
	{
		
		dbg.setColor(Color.YELLOW);
		
		double startX = r.getStart().getX();
		double startY = r.getStart().getY();
		double endX = r.getEnd().getX();
		double endY = r.getEnd().getY();
		java.util.List animatedCar = r.getAnimatedCar();
		double unit = mgr.getUnit();
		double halfunit = 0.5*unit;







	/*	
		java.util.List cars = r.getCar();
		for(int i=0; i<cars.size(); i++)
		{

			Car c = cars.get(i);
			
			// Initialize the image if it hasn't been
			if (c.getImageID()==0)
				c.setImageID(i+1); 
			//whj: previous
			//c.setImageID((int)(Math.random()*imsLoader.size())+1);
		
			// Load the image file
			BufferedImage pic = imsLoader.getImage(Integer.toString(c.getImageID()), c.getOrient());
			
			if (endX != startX && endY != startY)
			{
				// Step1
				double carX = (Math.abs(startX-endX))*c.getPercent();
				if(startX<endX)
					carX = startX - halfunit + carX;
				else
					carX = startX - halfunit - carX;
	
				double carY = (Math.abs(startY-endY))*c.getPercent();
				if(startY<endY)
					carY = startY - halfunit + carY;
				else
					carY = startY - halfunit - carY;
				// Step 2
				//dbg.fillOval((int)((carX-0.5)*unit),(int)((carY-0.5)*unit), unit, unit);
				dbg.drawImage(pic, (int)carX,(int)carY, (int)(unit), (int)unit, null);
				//imageSfx.drawResizedImage((Graphics2D)dbg, pic, (int)((carX-0.5)*unit), (int)((carY-0.5)*unit), unit/65.0, unit/65.0);
			}
				// Special case handling (road that lies horizontally)
			else if (endX != startX && endY == startY)
			{
				double carX = (Math.abs(startX-endX))*c.getPercent();
				if(startX<endX)
					carX = startX - halfunit + carX;
				else
					carX = startX - halfunit - carX;
	
				double carY = startY-halfunit;
				dbg.drawImage(pic, (int)carX,(int)carY, (int)(unit), (int)unit, null);
			}
				// Special case handling (road that lies vertically)
			else if (endX == startX && endY != startY)
			{
				double carX = startX- halfunit;
				double carY = (Math.abs(startY-endY))*c.getPercent();
				if(startY<endY)
					carY = startY -halfunit+ carY;
				else
					carY = startY - halfunit - carY;
	
				dbg.drawImage(pic, (int)carX,(int)carY, (int)unit, (int)unit, null);
			}
				// Should not happen (road that is just a single point)
			else
			{
				double carX = startX - halfunit;
				double carY = startY - halfunit;
				dbg.drawImage(pic, (int)carX,(int)carY, (int)unit, (int)unit, null);
			}
		}
		if(true)
			return;
			*/
		for(int i=0; i<animatedCar.size(); i++)
		{

			AnimatedCar c = (AnimatedCar)animatedCar.get(i);
			//dbg.drawImage(bridge1, 305, 589, bridge1.getWidth(), bridge1.getHeight(), null);
			//dbg.drawImage(bridge1, 263, 548, bridge1.getWidth(), bridge1.getHeight(), null);
			System.out.println("car size  !" + animatedCar.size());
			
			if(!c.readyForRender())
			{
				System.out.println("car not ready!!!"+ c.getID());
				continue;
			}
			// Initialize the image if it hasn't been
			//if (==0)
			//	c.setImageID(c.getImageID()); 
			//whj: previous
			//c.setImageID((int)(Math.random()*imsLoader.size())+1);
		
			// Load the image file
/////		
//			System.out.println("r.getID()="+ r.getID()+";c.getPercent()="+c.getPercent());
////			System.out.println("AnimatedCar: imageId="+c.getImageID()+",Orient="+ c.getOrient());
//			System.out.println("Road id="+r.getID()+";"+r.getPreviousSensor(c.getCurPos()).getID()+";"+r.getEndCrossPoint());
			
			BufferedImage pic = imsLoader.getImage(Integer.toString(c.getImageID()), c.getOrient());
			
//// handle the turning case			
//			if((r.getID()==7&&c.getPercent()>0.93) || (r.getID()==6&&c.getPercent()<0.04)){
//				System.out.println("AnimatedCar: imageId="+"c.getImageID(),Orient=3");
//				pic = imsLoader.getImage(Integer.toString(c.getImageID()), 3);
//			}
			
			if (endX != startX && endY != startY)
			{
				// Step1
				double carX = (Math.abs(startX-endX))*c.getPercent();
				if(startX<endX)
					carX = startX - halfunit + carX;
				else
					carX = startX - halfunit - carX;
	
				double carY = (Math.abs(startY-endY))*c.getPercent();
				if(startY<endY)
					carY = startY - halfunit + carY;
				else
					carY = startY - halfunit - carY;
				// Step 2
				//dbg.fillOval((int)((carX-0.5)*unit),(int)((carY-0.5)*unit), unit, unit);
				System.out.println("carX="+carX+",carY="+ carY+",unit="+unit);
				dbg.drawImage(pic, (int)carX,(int)carY, (int)(unit), (int)unit, null);
				
				
				//imageSfx.drawResizedImage((Graphics2D)dbg, pic, (int)((carX-0.5)*unit), (int)((carY-0.5)*unit), unit/65.0, unit/65.0);
			}
			// Special case handling (road that lies horizontally)
///			
			else if (endX != startX && endY == startY)
			{
				double carX = (Math.abs(startX-endX))*c.getPercent();
				if(startX<endX)
					carX = startX - halfunit + carX;
				else
					carX = endX - halfunit + carX;
				//System.out.println("Car X is " + carX + " halfunit is " + halfunit + " pre is " + (Math.abs(startX-endX))*c.getPercent() + " percent is " + c.getPercent());
				double carY = startY-halfunit;
				dbg.drawImage(pic, (int)carX,(int)carY, (int)(unit), (int)unit, null);
			}
			// Special case handling (road that lies vertically)
			else if (endX == startX && endY != startY)
			{
				
				double carX = startX- halfunit;
				double carY = (Math.abs(startY-endY))*c.getPercent();		
///				System.out.println("startY="+startY+",endY="+ endY+",carY="+carY+",percent="+c.getPercent());
				if(startY<endY)
					carY = startY - halfunit + carY;
				else
					carY = endY - halfunit + carY;
				//System.out.println("Car Y is " + carY + " halfunit is " + halfunit + " preY is " + (Math.abs(startY-endY))*c.getPercent() + " percent is " + c.getPercent());	
///				System.out.println("carX="+carX+",carY="+ carY+",unit="+unit);
				dbg.drawImage(pic, (int)carX,(int)carY, (int)unit, (int)unit, null);
				
				//System.out.println(r.getID());
				
				//dbg.setColor(Color.gray);
				//dbg.setColor(new Color(128,120,128));
				//System.out.println("Color-----------"+dbg.getColor());				
				//dbg.fillRect(305,590,30,50);
				//dbg.drawImage(bridge1, 305, 589, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge1, 323, 620, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge1, 305, 589, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge1, 258, 548, bridge1.getWidth(), bridge1.getHeight(), null);
				dbg.drawImage(bridge1, 258, 509, bridge1.getWidth(), bridge1.getHeight(), null);
				
                //dbg.fillRect(480,590,70,50);
                //dbg.drawImage(bridge2, 480, 589, bridge1.getWidth(), bridge1.getHeight(), null);
                //dbg.drawImage(bridge2, 505, 620, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge2, 480, 589, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge2, 412, 548, bridge1.getWidth(), bridge1.getHeight(), null);
				dbg.drawImage(bridge2, 412, 509, bridge1.getWidth(), bridge1.getHeight(), null);
				
                //dbg.fillRect(715,590,70,50);
                //dbg.drawImage(bridge3, 715, 589, bridge1.getWidth(), bridge1.getHeight(), null);
                //dbg.drawImage(bridge3, 750, 620, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge3, 715, 589, bridge1.getWidth(), bridge1.getHeight(), null);
				//dbg.drawImage(bridge3, 615, 548, bridge1.getWidth(), bridge1.getHeight(), null);
				dbg.drawImage(bridge3, 615, 509, bridge1.getWidth(), bridge1.getHeight(), null);
                
                //java.awt.Toolkit.getDefaultToolkit().beep();   
               
                
                //SummaryWindow s=new SummaryWindow((SensorManager)(this.mgr));
                //int sele=JOptionPane.showConfirmDialog((Component)(this.getParent()),"message","title",JOptionPane.OK_CANCEL_OPTION,JOptionPane.WARNING_MESSAGE); 
                //
                //if(sele==JOptionPane.OK_OPTION){                
                //} 
			}
			// Should not happen (road that is just a single point)
			else
			{
				double carX = startX - halfunit;
				double carY = startY - halfunit;
				dbg.drawImage(pic, (int)carX,(int)carY, (int)unit, (int)unit, null);
			}
			//c.rendered();
		}
	}

  private void paintScreen()
  // use active rendering to put the buffered image on-screen
  { 
    Graphics g;
    try {
      g = this.getGraphics();
      if ((g != null) && (dbImage != null))
        g.drawImage(dbImage, 0, 0, null);
      g.dispose();
    }
    catch (Exception e)
    { System.out.println("Graphics context error: " + e);e.printStackTrace(); }
  } // end of paintScreen()


	/********Statistics related method, DO NOT modify!*********/
  private void storeStats()
  /* The statistics:
       - the summed periods for all the iterations in this interval
         (period is the amount of time a single frame iteration should take), 
         the actual elapsed time in this interval, 
         the error between these two numbers;

       - the total frame count, which is the total number of calls to run();

       - the frames skipped in this interval, the total number of frames
         skipped. A frame skip is a game update without a corresponding render;

       - the FPS (frames/sec) and UPS (updates/sec) for this interval, 
         the average FPS & UPS over the last NUM_FPSs intervals.

     The data is collected every MAX_STATS_INTERVAL  (1 sec).
  */
  { 
    frameCount++;
    statsInterval += period;

    if (statsInterval >= MAX_STATS_INTERVAL) {     // record stats every MAX_STATS_INTERVAL
      long timeNow = System.currentTimeMillis();
      timeSpentInGame = (int) ((timeNow - gameStartTime)/1000L);  // ms --> secs
      //wcTop.setTimeSpent( timeSpentInGame );

      long realElapsedTime = timeNow - prevStatsTime;   // time since last stats collection
      totalElapsedTime += realElapsedTime;

      double timingError = 
         ((double)(realElapsedTime - statsInterval) / statsInterval) * 100.0;

      totalFramesSkipped += framesSkipped;

      double actualFPS = 0;     // calculate the latest FPS and UPS
      double actualUPS = 0;
      if (totalElapsedTime > 0) {
        actualFPS = (((double)frameCount / totalElapsedTime) * 1000L);
        actualUPS = (((double)(frameCount + totalFramesSkipped) / totalElapsedTime) 
                                                             * 1000L);
      }

      // store the latest FPS and UPS
      fpsStore[ (int)statsCount%NUM_FPS ] = actualFPS;
      upsStore[ (int)statsCount%NUM_FPS ] = actualUPS;
      statsCount = statsCount+1;

      double totalFPS = 0.0;     // total the stored FPSs and UPSs
      double totalUPS = 0.0;
      for (int i=0; i < NUM_FPS; i++) {
        totalFPS += fpsStore[i];
        totalUPS += upsStore[i];
      }

      if (statsCount < NUM_FPS) { // obtain the average FPS and UPS
        averageFPS = totalFPS/statsCount;
        averageUPS = totalUPS/statsCount;
      }
      else {
        averageFPS = totalFPS/NUM_FPS;
        averageUPS = totalUPS/NUM_FPS;
      }
/*
      System.out.println(timedf.format( (double) statsInterval/1000000000L) + " " + 
                    timedf.format((double) realElapsedTime/1000000000L) + "s " + 
			        df.format(timingError) + "% " + 
                    frameCount + "c " +
                    framesSkipped + "/" + totalFramesSkipped + " skip; " +
                    df.format(actualFPS) + " " + df.format(averageFPS) + " afps; " + 
                    df.format(actualUPS) + " " + df.format(averageUPS) + " aups" );
*/
      framesSkipped = 0;
      prevStatsTime = timeNow;
      statsInterval = 0L;   // reset
    }
  }  // end of storeStats()
	/********************************************************/

  private void printStats()
  {
    System.out.println("Frame Count/Loss: " + frameCount + " / " + totalFramesSkipped);
	System.out.println("Average FPS: " + df.format(averageFPS));
	System.out.println("Average UPS: " + df.format(averageUPS));
    System.out.println("Time Spent: " + timeSpentInGame + " secs");
  }  // end of printStats()




}  // end of WormPanel class
