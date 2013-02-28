package itransnet_base.tracking.Server.Manager;

import java.util.ArrayList;
import java.util.List;
import java.io.IOException;

// TinyOS related
import net.tinyos.util.*;
import net.tinyos.message.*;

// Project related modules
import itransnet_base.tracking.Server.Display.*;
import itransnet_base.tracking.Server.Message.*;
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Utility.*;

public class Initializer implements Runnable, SensorConstants
{
	// Sequence number for the messages sent from server to sensors.
	public static int bcast_seqno = 0;
	// For registering the manager as a Mote listener
	MoteIF mote;
	// Contains all of the information needed.
	private Map map;
	private SensorManager mgr;
	private static int MSG_TRY = 2;
	final private static boolean PC_MODE = false;

	public Initializer (MoteIF mote)
	{
		this.mote = mote;
		if (PC_MODE)
			MSG_TRY=10;
	}

	public void setMap (Map map) { this.map = map; }
	public void setManager (SensorManager mgr) { this.mgr = mgr; }
	
	public void startCars () {
		BcastMsg bcm = new BcastMsg();
		bcast_seqno = (bcast_seqno + 1) % 256;
		bcm.set_seqno((short)bcast_seqno);
		SensorControlMsg scm = new SensorControlMsg(bcm,bcm.offset_data(0));
		scm.set_sensorID(MoteIF.TOS_BCAST_ADDR);
		scm.set_sensorType(SENSOR_TYPE_CAR);
		scm.set_operationMode(OPER_START);
		try {
			System.out.println("packet to be sent for: cars");
			System.out.println("packet: "+scm);
			mote.send(MoteIF.TOS_BCAST_ADDR, bcm);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void stopCars () {
		BcastMsg bcm = new BcastMsg();
		bcast_seqno = (bcast_seqno + 1) % 256;
		bcm.set_seqno((short)bcast_seqno);
		SensorControlMsg scm = new SensorControlMsg(bcm,bcm.offset_data(0));
		scm.set_sensorID(MoteIF.TOS_BCAST_ADDR);
		scm.set_sensorType(SENSOR_TYPE_CAR);
		scm.set_operationMode(OPER_STOP);
		try {
			System.out.println("packet to be sent for: cars");
			System.out.println("packet: "+scm);
			mote.send(MoteIF.TOS_BCAST_ADDR, bcm);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	public void run()
	{
		ArrayList roads = map.getRoad();
		for (int i=0; i<roads.size(); i++)
		{
			Road r = (Road)roads.get(i);
			List sensors = r.getSensor();
			//for (int j=0; j< sensors.size(); j++)
			for (int j=sensors.size()-1; j>=0; j--)
			{
				Sensor s = (Sensor)sensors.get(j);
				BcastMsg bcm = new BcastMsg();
				bcast_seqno = (bcast_seqno + 1) % 256;
				bcm.set_seqno((short)bcast_seqno);
				
				ITSCmdMsg packet = new ITSCmdMsg(bcm,bcm.offset_data(0));
				//ITSCmdMsg packet = new ITSCmdMsg();
				
				packet.set_initTime_high32(0);
				packet.set_initTime_low32(0);
				packet.set_sensorID(s.getID());
				packet.set_operationMode(mgr.getOperationMode());
				if (mgr.simpleMode())
					packet.set_sensorType(SENSOR_TYPE_SIMPLE);
				else if (r.getType()==LIFO_ROAD)
					packet.set_sensorType(SENSOR_TYPE_PARK);
				else if (j==0 && j==(sensors.size()-1))
					packet.set_sensorType(SENSOR_TYPE_ONLY);
				else if (j==0)
					packet.set_sensorType(SENSOR_TYPE_START);
				else if (j==(sensors.size()-1))
					packet.set_sensorType(SENSOR_TYPE_END);
				else
					packet.set_sensorType(SENSOR_TYPE_NORM);

				int totalStore = ITSCmdMsg.numElements_sensors_sensorID();
				int [] sensor_id = new int [totalStore];
				int [] distance = new int [totalStore];
				int k=0;

				// Sensor is in the middle of the road or is at the beginning of the road
				if (packet.get_sensorType() == SENSOR_TYPE_NORM || packet.get_sensorType() == SENSOR_TYPE_START)
				{
					for (; k<totalStore && k+j+1<sensors.size(); k++)
					{
						Sensor nextS = (Sensor)sensors.get(k+j+1);
						sensor_id[k] = nextS.getID();
						distance[k] = (int)((nextS.getPos()-s.getPos())*1000);
						//System.out.println("Sensor ID: "+sensor_id[k]+" Distance: "+distance[k]);
					}
				}
				// Sensor is at the end of the road
				else if (packet.get_sensorType() == SENSOR_TYPE_END || packet.get_sensorType() == SENSOR_TYPE_ONLY ||
					packet.get_sensorType() == SENSOR_TYPE_PARK)
				{
					CrossRoad cr = r.getEndCrossPoint();
					if(cr!=null)
					{
						ArrayList allEndRoad = cr.getEndList();
						int l = 0;
						for (; k<totalStore && l<allEndRoad.size(); l++)
						{
							Road otherRoad = (Road)allEndRoad.get(l);
							if (otherRoad == r || otherRoad.getType() == LIFO_ROAD) continue;
	
							List otherSensor = otherRoad.getSensor();
							Sensor lastSensorOnOther = (Sensor)otherSensor.get(otherSensor.size()-1);
	
							sensor_id[k] = lastSensorOnOther.getID();
							//System.out.println(otherRoad.getLength()+" "+lastSensorOnOther.getPos());
							distance[k] = (int)((r.getLength()-s.getPos()+otherRoad.getLength()-lastSensorOnOther.getPos()+1.0)*1000);
							//System.out.println("Sensor ID: "+sensor_id[k]+" Distance: "+distance[k]);
							k++;
						}
					}
				}
				
				// Fill up the rest of the data with empty stuff
				if (k<totalStore)
				{
					for (; k<totalStore; k++)
						sensor_id[k] = distance[k] = 0;
				}

				packet.set_sensors_distance(distance);
				packet.set_sensors_sensorID(sensor_id);
				/*
				try {
					// Send each message for 10 times to make sure
					System.out.println("packet to be sent for: "+s.getID());
					System.out.println("packet: "+packet);
					for (int m=0; m<MSG_TRY; m++)
					{
					mote.send(MoteIF.TOS_BCAST_ADDR, bcm);
					Thread.sleep(500);
					}
					}
									catch (Exception e)
				{
					e.printStackTrace();
				} // End of catch

					*/
				
			} // End of for loop of each sensor
		} // End of for loop of each road
		// Last, send 10 dummy messages
		//System.out.println("Sending dummy messages to clear way");
		
		if (PC_MODE)
		{
			for (int i=0; i<MSG_TRY; i++)
			{
				BcastMsg bcm = new BcastMsg();
				bcast_seqno = (bcast_seqno + 1) % 256;
				bcm.set_seqno((short)bcast_seqno);
				try {
					mote.send(MoteIF.TOS_BCAST_ADDR, bcm);
					Thread.sleep(500);
				}
				catch (Exception e) {}
			}
		}
		System.out.println("Initialization completed");
	}
/* old trash:
	private void initializeSensor()
	{
		int count = 0;
		// BcastMsg is the wrapper of ITS Message
		BcastMsg bcm = new BcastMsg();
		bcast_seqno = (bcast_seqno + 1) % 256;
		bcm.set_seqno((short)bcast_seqno);
		
		ITSCmdMsg packet = new ITSCmdMsg(bcm,bcm.offset_data(0));
		//ITSCmdMsg packet = new ITSCmdMsg();
		
		packet.set_sensorID(4);
		packet.set_sensorType((short)3);
		System.out.println(packet);
		while (true)
		{
			try {
				mote.send(MoteIF.TOS_BCAST_ADDR, bcm);
				System.out.println("Sent "+(++count)+" packet");
				Thread.sleep(800);
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
	}*/
}
