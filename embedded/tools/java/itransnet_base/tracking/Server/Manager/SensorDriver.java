package itransnet_base.tracking.Server.Manager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

import itransnet_base.tracking.Server.Message.DummyMsg;
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Utility.*;

public class SensorDriver extends JFrame implements Runnable, ActionListener, SensorConstants
{
	// Total no. of sensors
	private int sensorCount = 4;
	private SensorManager mgr;
	// Messages that will be sent to the manager when a specific key is pressed.
	private DummyMsg msg [];
	JButton jbSensor [];

	public SensorDriver (SensorManager mgr)
	{
		super("Sensor Driver");
		this.mgr = mgr;
		
		// Count the total number of sensors in the area.
		itransnet_base.tracking.Server.DataEngine.Map m = mgr.getMap();
		sensorCount = m.numOfSensors();
		
		sensorCount=100;
		
		jbSensor = new JButton [sensorCount+1];
		msg = new DummyMsg [sensorCount+1];
		for (int i=1; i<=sensorCount; i++)
		{
			msg[i] = new DummyMsg();
			msg[i].setID (i);
			msg[i].setData(SENSOR_UNCOVERED);
			//System.out.println("------i="+i+",motoId="+msg[i].getID());
			
		}
		/*
		for(int i=15;i<35;i++){			
			msg[i].setID (i+44);
			msg[i].setData(SENSOR_UNCOVERED);
			//System.out.println("------i="+i+",motoId="+msg[i].getID());
			
		}
		*/
		setAlwaysOnTop(true);
	}
	
	public void run()
	{
    Container c = getContentPane();
    c.setLayout(new FlowLayout());
    for (int i=1; i<=sensorCount; i++)
    {
    	jbSensor[i] = new JButton(Integer.toString(msg[i].getID()));
    	jbSensor[i].addActionListener (this);
    	c.add(jbSensor[i]);
    }
    pack();
    setVisible(true);
  }
  
  public void actionPerformed (ActionEvent e)
  {
  	for (int i=1; i<=sensorCount; i++)
  	{
  		if (e.getSource() == jbSensor[i])
  		{
  			int data = msg[i].getData();
  			if (data == SENSOR_UNCOVERED )
					data = SENSOR_COVERED;
				else
					data = SENSOR_UNCOVERED;
					
				msg[i].setData(data);
				System.out.println("-----------------Press button:"+msg[i].getID());
				mgr.messageReceived (1, msg[i]);
  		}
  	}
  }
}
