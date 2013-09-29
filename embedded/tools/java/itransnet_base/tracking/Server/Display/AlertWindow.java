package itransnet_base.tracking.Server.Display;

import itransnet_base.tracking.Server.DataEngine.Map;
import itransnet_base.tracking.Server.Manager.SensorManager;
import itransnet_base.tracking.Server.Message.DummyMsg;
import itransnet_base.tracking.Utility.SensorConstants;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;

public class AlertWindow extends JFrame implements Runnable, ActionListener, SensorConstants
{
	// Total no. of sensors
	private int sensorCount = 4;
	private SensorManager mgr;
	// Messages that will be sent to the manager when a specific key is pressed.
	private DummyMsg msg [];
	JButton jbSensor [];
	String errorStr="";
	public void setErrStr(String err)
	{
		errorStr = err;
		Container c = getContentPane();
		c.removeAll();
		c.setLayout(new FlowLayout());
		c.add(new Label(errorStr));
	}
	public AlertWindow (SensorManager mgr)
	{
		super("Alert");
		this.mgr = mgr;
		errorStr="";
		
		// Count the total number of sensors in the area.
		//itransnet_base.tracking.Server.DataEngine.Map m = mgr.getMap();
		/*
		sensorCount = m.numOfSensors();
		
		sensorCount=1;
		
		jbSensor = new JButton [sensorCount+1];
		msg = new DummyMsg [sensorCount+1];
		for (int i=1; i<=sensorCount; i++)
		{
			msg[i] = new DummyMsg();
			msg[i].setID (i);
			msg[i].setData(SENSOR_UNCOVERED);
			//System.out.println("------i="+i+",motoId="+msg[i].getID());
			
		}*/
		
		//errorStr="";
		//ArrayList errorList=Map.defaultMap.getErrorList();
		//for(int i=0;i<errorList.size();i++){
		//	errorStr+=errorList.get(i)+"\n";
			
		//}
		//errorList.clear();
		
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

    /*
    for (int i=1; i<=sensorCount; i++)
    {
    	jbSensor[i] = new JButton(Integer.toString(msg[i].getID()));
    	jbSensor[i].addActionListener (this);
    	c.add(jbSensor[i]);
    }
    */
    pack();
    setVisible(true);
  }
  
  public void actionPerformed (ActionEvent e)
  {
  	System.out.println("closed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
  }
}
