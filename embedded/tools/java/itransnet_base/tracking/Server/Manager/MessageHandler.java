package itransnet_base.tracking.Server.Manager;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

// TinyOS related
import net.tinyos.util.*;
import net.tinyos.message.*;

// Project related modules
import itransnet_base.tracking.Server.Display.*;
import itransnet_base.tracking.Server.Message.*;
import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Server.DataEngine.XML.*;
import itransnet_base.tracking.Utility.*;

public class MessageHandler implements Runnable, SensorConstants
{
	private Message msg;
	private Map map;
	private String output;

	// Attributes of the message
	private int vid, moteID, moteData;
	//private int channelID, packetNum;
	private short operMode;
	private boolean flowEnabled;
	
	MessageHandler (Message m)
	{
		msg = m;
		flowEnabled = true;
	}

	public void setOutput (String output) { this.output = output; }
	public void setMap (Map m) { map = m; }

	public void run()
	{
		MapDumper dumper = new MapDumper(map);
		// The dump file should be obtained from manager in the future.
		dumper.setDumpFile (output);
		
		try {
			processMessage ();
		}
		catch (UnknownMessageException e)
		{
			return;
		}

	
		
	}
	private void processMessage () throws UnknownMessageException
	{
		System.out.println("processing message");
		int turningDirection =0;
		
		// Default operation mode
		operMode = OPER_EVERY_MSG;
		// Initialize all of the variables
		System.out.println("get Msg hahah" + (msg instanceof VehicleMsg));
		if (msg instanceof DummyMsg)
		{
			DummyMsg omsg = (DummyMsg)msg;
			moteID = omsg.get_sourceMoteID();
			moteData = omsg.getElement_data(omsg.numElements_data()-1);
						
			if(moteID==7||moteID==8||moteID==72||moteID==63 
				||moteID==5	|| moteID==48 || moteID==25 || moteID==27 || moteID==24
				|| moteID==2 || moteID==6 || moteID==33 || moteID==94|| moteID==99|| moteID==14
				||moteID==15||moteID==16||moteID==18||moteID==36||moteID==71||moteID==75
				)
			{
				turningDirection =2;
			}
			
			System.out.println("get dummy Msg, moteID:"+moteID+",moteData:"+moteData);
			//channelID = omsg.get_channel();
			//packetNum = omsg.get_lastSampleNumber();
		}
		else if(msg instanceof VehicleMsg)
		{
      VehicleMsg itsmsg = (VehicleMsg)msg;
			
			operMode = OPER_EVERY_MSG;
			vid = itsmsg.getSerialPacket().get_header_src();
			moteID = itsmsg.getSerialPacket().get_header_src();
			moteData = SENSOR_COVERED; //smsg.get_status();
			
			turningDirection=itsmsg.get_dir();
			if(turningDirection==1) turningDirection=2;
			
		}
		
		// Update the sensor's data.
		DefaultSensor s = (DefaultSensor)map.getSensor(moteID);
		System.out.println("Sensor ID:"+s.getID());
		if (s==null)  // Sensor not in the list
		{
			System.out.println("Sensor: "+moteID+" is not in the list!");
			return;
		}
		//s.setChannelID(channelID);
		//s.setPacketNum(packetNum);

		//System.out.println ("Message from sensor: " +moteID + ", and sensory value is "+ vid);
		//The mote is covered!

		if (operMode == OPER_SUMMARY_MSG)
		{
			System.out.println("Sensor: "+moteID+" just reported "+moteData+" cars passed.");
			Road r = s.getRoad();
			if (s.isBeginning())
				r.setNumOfCars(r.getNumOfCars()+moteData);
			else
				r.setNumOfCars(r.getNumOfCars()-moteData);
		}
		else
		{
			System.out.println("CAR init--------- ");
			
			// Road on which the car is driving.
			Road r = s.getRoad();
				// Car is passing the mote
			double pos = s.getPos();
			//System.out.println("position is: " + pos + " road is: " + r.getID());
			if(map.isNewCar(vid))
			{
				System.out.println("new car with vid= " + vid+",pos="+pos);
				Car c = new Car(vid);
				c.setAverageSpeed (0.0004);
				c.setLastPortionSpeed (0.0004);
				c.setTurnDirection(turningDirection);
				c.setPos (pos);				
				r.addCar(c);
				map.addCar(c);
				
			}
			else
			{
				System.out.println("update car loaction: road=" + r.getID() +",vid="+vid+",pos="+pos+",turningDirection="+turningDirection);
				map.updateCar(r, vid, pos,turningDirection);
				
			}
			//if (c.getAnimatedCar()!=null)
			//System.out.println("New Car: "+c.getAnimatedCar());
			//s.addData(moteData, c);
		}

	}

	private void calculateSpeed (Car c, Sensor s, Road r)
	{
		long curTime = System.currentTimeMillis();

		double average = c.getTotalDistance()/(curTime - c.getEntranceTime());
		c.setAverageSpeed (average);
		
		double instance = (1+c.getLength())/(curTime - s.getLastTime(c));
		c.setInstanceSpeed (instance);
		
		Sensor s2 = r.getPreviousSensor (s);
		if(s2!=null)
		{
			double lastPortion = (s.getPos()-s2.getPos())/(curTime-s2.getLastTime(c));
			c.setLastPortionSpeed (lastPortion);
		}
		else
			c.setLastPortionSpeed (average);
	}

	/**
	 *	Get a car that hasn't passed the sensor s yet but the next sensor it will pass is
	 *	s.
	 *	<p>
	 *	Maybe this method should not be placed within Road class because Road class is mainly
	 *	responsible for storing data, not for algorithm such as searching
	 *	@param	s the sensor which the car will pass next
	 *	@return the car that meets the criteria. Null returned if this is a new car.
	 */
	private Car getCarBefore (Road road, Sensor s, int vehicleid) throws CarNotFoundException
	{

		Car c = road.getCarById(vehicleid);

		if(c == null) // new car
			return null;
		else
			return c;
		/*
		{		ArrayList sensor = road.getSensor();
		CrossRoad startCross = road.getStartCrossPoint();
		List car = road.getCar();

			// An array list of candidate cars
			ArrayList candidates = new ArrayList();
			
			// Where the car will be inserted
			int insertPos = car.size();
			
			// First try to find the car in the current road
			// Find the previous sensor
			Sensor previous = road.getPreviousSensor(s);
			if (previous != null)
			{
				// For all the cars in the current road,
				// find one that is between current sensor and previous sensor
				// find one that is before current sensor (new)
				for (int i=0; i<car.size(); i++)
				{
					Car tc = (Car)car.get(i);
					double pos = tc.getPos();
					
					// If this car is between the 2 sensors, insert before this car
					// before the new car will be the first one to pass the current sensor
					//if (pos>previous.getPos() && pos<s.getPos())
					if (pos<s.getPos()) // (new)
					{
						insertPos = i;
						CandidateCar can = new CandidateCar ();
						can.car = tc;
						can.travelTime = (s.getPos()-c.getPos())/c.getGrandSpeed();
						candidates.add(can);
						//System.out.println("Candidate added: "+can);
						break;
					}
					// If this car is before or on the previous sensor, insert before this car
					// (new)
					//if (pos <= previous.getPos())
					//{
					//	insertPos = i;
					//	break;
					//}
				}
			}
			
			ArrayList neighbor = road.getNeighbor();
			// Now try to find the car in the neighboring roads
			for (int i=0; i<neighbor.size(); i++)
			{
				Road r = (Road)neighbor.get(i);
				previous = r.getPreviousSensor (s.getPos());
				if (previous != null)
				{
					List neighborCars = r.getCar();
					for(int j=0; j<neighborCars.size(); j++)
					{
						Car c = (Car)neighborCars.get(j);
						double pos = c.getPos();
						if (pos>previous.getPos() && pos<s.getPos())
						{
							CandidateCar can = new CandidateCar ();
							can.car = c;
							can.travelTime = (s.getPos()-c.getPos()+1.0)/c.getGrandSpeed();
							candidates.add(can);
							System.out.println("Candidate added: "+can);
							break;
						}
						if (pos <= previous.getPos())
							break;
					}
				}
			}
			
			if (candidates.size()>0)
			{
				// In all of the candidate cars, find the one that is nearest to the current sensor
				Collections.sort(candidates, new Comparator ()
					{
						public int compare (Object o1, Object o2)
						{
							double time1 = ((CandidateCar)o1).travelTime;
							double time2 = ((CandidateCar)o2).travelTime;
							if (time1 - time2 <0.0)
								return -1;
							else if (time1-time2 >0.0)
								return 1;
							else
								return 0;
						}
					});
				Car finalCar = ((CandidateCar)candidates.get(0)).car;
				
				//System.out.println("Final car: "+finalCar);
				Road r = finalCar.getRoad();
				
				if (r!=road)
				{
					r.removeCar(finalCar);
					car.add(insertPos, finalCar);
					finalCar.setRoad(road);
					return finalCar;
				}
				else
					return finalCar;
				
			}
			// A car cannot appear in the middle of a road so an exception must be thrown
			throw new CarNotFoundException();
		}
		*/
	} // end of getCarBefore ()

	private void checkSafety (Car c, Sensor s, Road r)
	{
	}
}

class CandidateCar
{
	public Car car;
	public double travelTime;
	public String toString () { return car.getID()+" time: "+travelTime; }
}
