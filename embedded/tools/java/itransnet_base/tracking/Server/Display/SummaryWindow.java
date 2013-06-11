package itransnet_base.tracking.Server.Display;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import itransnet_base.tracking.Server.Manager.*;
import itransnet_base.tracking.Server.DataEngine.*;

public class SummaryWindow extends JFrame implements Runnable
{
	private SensorManager mgr;
	private SummaryPanel dp;
	
	private ArrayList numLabels;
	
	public SummaryWindow (SensorManager mgr)
	{
		super("Number of cars in each road");
		this.mgr = mgr;
	}
	
	public void run()
	{
		makeGUI();

    pack();
    setVisible(true);
	}

  private void makeGUI()
  {
		Container c = getContentPane();    // default BorderLayout used
		
		dp = new SummaryPanel(mgr);
		
		c.add(dp, "Center");
	}
	/*
	public void run()
	{
		// Create layout
		container = getContentPane();
		container.setLayout(new GridLayout(road.size(), 2));
		
		// Initialize all GUI
		for (int i=0; i<road.size(); i++)
		{
			Road r = (Road)road.get(i);
			// Road name
			JLabel jlRoad = new JLabel(r.getName());
			container.add(jlRoad);
			
			// Number of cars
			int num = getNumOfCars(r);
			JLabel jlNum = new JLabel(Integer.toString(num));
			numLabels.add(jlNum);
			container.add(jlNum);
		}
		
		pack();
		setVisible(true);
		
		while (true) {
			try {
				Thread.sleep(500);
			} catch (Exception e) {}
			updateWindow ();
			Thread.yield();
		}
	}
	
	public void updateWindow ()
	{
		ArrayList road = map.getRoad();
		// Initialize all GUI
		for (int i=0; i<road.size(); i++)
		{
			Road r = (Road)road.get(i);
			// Number of cars
			int num = getNumOfCars(r);
			JLabel jlNum = (JLabel)numLabels.get(i);
			jlNum.setText(Integer.toString(num));
		}
	}
	
	private int getNumOfCars (Road r)
	{
		if (r.getCar().size()>0)
			return r.getCar().size();
		else
			return r.getNumOfCars();
	}*/
		
}