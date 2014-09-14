package itransnet_base.tracking.Server.Display;

import itransnet_base.tracking.Server.DataEngine.Map;
import itransnet_base.tracking.Server.Manager.SensorManager;
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
		setAlwaysOnTop(true);
	}
	
	public void run()
	{

    pack();
    setVisible(true);
  }
  
  public void actionPerformed (ActionEvent e)
  {
  	System.out.println("closed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
  }
}
