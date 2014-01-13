package itransnet_base.tracking.Server.Display;

import java.io.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import itransnet_base.tracking.Server.Manager.*;
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Utility.*;

public class ConfigureWindow extends JFrame implements Runnable, SensorConstants
{
	private SensorManager mgr;
	private Map map;
	JCheckBoxMenuItem operItems[];
	
	public ConfigureWindow (SensorManager mgr)
	{
		super("Configure");
		this.mgr=mgr;
	}
	
	public void run()
	{
		makeGUI();

    pack();
    setVisible(true);
	}
	
  private void makeGUI()
  {
  	/****************Menu Items******************/
  	JMenuBar bar = new JMenuBar();
  	
  	// Sensor
  	JMenu sensorMenu = new JMenu ("Sensor");
  	
  	// Sensor -> Operation
  	JMenu operMenu = new JMenu ("Operation");
  	String operName [] = {"Receive all messages", "Receive summary messages", "Light"};
  	operItems = new JCheckBoxMenuItem[operName.length];
  	OperHandler operHandler = new OperHandler();
  	
  	for (int i=0; i<operName.length; i++)
  	{
  		operItems[i]=new JCheckBoxMenuItem(operName[i]);
  		operMenu.add(operItems[i]);
  		operItems[i].setSelected(true);
  		operItems[i].addItemListener(operHandler);
  	}
  	
  	sensorMenu.add(operMenu);

		sensorMenu.addSeparator();

		// Sensor -> Start Cars
		JMenuItem startCar = new JMenuItem("Start Cars");
		startCar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
			    //mgr.startCars();
			}
		});

		sensorMenu.add(startCar);
  
		// Sensor -> Stop Cars
		JMenuItem stopCar = new JMenuItem("Stop Cars");
		stopCar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
			    //mgr.stopCars();
			}
		});

		sensorMenu.add(stopCar);	

  	bar.add(sensorMenu);
  	
  	// Map
  	JMenu mapMenu = new JMenu ("Map");
  	
  	// Map -> Reload
  	JMenuItem reloadMap = new JMenuItem("Reload");
  	reloadMap.addActionListener(new ActionListener(){
  		public void actionPerformed(ActionEvent event)
  		{
  			// Actions for reloading map
  			mgr.reloadMap();
  		}
  	});
  	mapMenu.add(reloadMap);

    // Map -> Clear
  	JMenuItem clearMap = new JMenuItem("Clear");
  	clearMap.addActionListener(new ActionListener(){
  		public void actionPerformed(ActionEvent event)
  		{
  			// Actions for clearing map
  			mgr.clearMap();
  		}
  	});
  	mapMenu.add(clearMap);	

  	// Map -> Change...
  	JMenuItem changeMap = new JMenuItem("Change...");
  	changeMap.addActionListener(new ActionListener(){
  		public void actionPerformed(ActionEvent event)
  		{
  			// Actions for changing map
  			selectFile();
  		}
  	});
  	mapMenu.add(changeMap);
  	
  	bar.add(mapMenu);

  	setJMenuBar(bar);
		/*****************End of Menu Items*************/
	}
	
	private void selectFile()
	{
		JFileChooser fileChooser = new JFileChooser(mgr.getMapDir());
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		
		int result = fileChooser.showOpenDialog(this);
		if (result == JFileChooser.CANCEL_OPTION)
			return;

		File filename = fileChooser.getSelectedFile();
		
		if (filename == null||
			filename.getName().trim().equals(""))
				JOptionPane.showMessageDialog(this, "Invalid File Name",
				"Invalid File Name", JOptionPane.ERROR_MESSAGE);
		else
		{
			mgr.changeMap(filename);
		}
	}
	
  private class OperHandler implements ItemListener{
  	public void itemStateChanged (ItemEvent e)
  	{
  		int operCode=1;
  		
  		// Actions for changing operation mode
  		if (operItems[0].isSelected())
  			operCode *= OPER_EVERY_MSG;
  		if (operItems[1].isSelected())
  			operCode *= OPER_SUMMARY_MSG;
  		if (operItems[2].isSelected())
  			operCode *= OPER_LIGHT;
  		mgr.updatOperation(operCode);
  	}
	}
}
