package itransnet_base.tracking.Server.DataEngine;

import java.util.HashMap;
import java.util.Hashtable;

public class DefaultSensor implements Sensor {
    public static Integer DIRECTION_F=Integer.valueOf(0);
    public static Integer DIRECTION_B=Integer.valueOf(1);
    public static Integer DIRECTION_L=Integer.valueOf(2);
    public static Integer DIRECTION_R=Integer.valueOf(3);

    private int packetNum, channelID, moteID;

    // Key: car's ID, Value: Last data that belong to the car
    private Hashtable data;
    // Last obtained data (used to check if the new data is worth logging)
    private int lastData;
	
    public HashMap adjectSensorMap=new HashMap();

    private void initadjectSensorMap(int id){
	adjectSensorMap.clear();
	if(id==2){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(3));	
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(34));
	}
	if(id==5){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(6));	
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(62));
	}
	if(id==6){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(7));
	}
	if(id==7){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(8));
	}
	if(id==8){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(9));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(74));
	}
	if(id==10){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(11));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(84));
	}
	if(id==12){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(13));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(92));
	}		
	if(id==14){
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(15));
	}
	if(id==15){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(16));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(95));
	}
	if(id==16){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(17));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(49));
	}
	if(id==18){
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(19));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(35));
	}
	if(id==24){			
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(1));
	}
	if(id==25){	
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(26));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(76));
	}
	if(id==27){	
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(28));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(65));
	}
	if(id==33){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(3));
	}
	if(id==36){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(19));
	}
	if(id==48){			
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(17));
	}		
	if(id==51){			
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(53));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(91));
	}
	if(id==55){			
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(57));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(83));
	}
	if(id==59){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(61));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(73));
	}	
	if(id==63){			
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(6));
	}
	if(id==71){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(73));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(58));
	}		
	if(id==72){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(70));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(61));
	}
	if(id==75){					
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(9));
	}
	if(id==82){		
	    adjectSensorMap.put(DIRECTION_F, Integer.valueOf(80));
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(57));
	}	
	if(id==85){		
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(11));			
	}
	if(id==90){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(53));
	}
	if(id==93){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(13));
	}
	if(id==94){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(16));
	}
	if(id==99){				
	    adjectSensorMap.put(DIRECTION_L, Integer.valueOf(7));
	}
		
    }
    public DefaultSensor() {data = new Hashtable(); lastData = SENSOR_UNCOVERED;}
    public DefaultSensor(int id) {
	this(); 
	moteID=id;
	initadjectSensorMap(id);
    }
	
    public int getPacketNum() {return packetNum;}
    public int getChannelID() {return channelID;}
    public int getID() {return moteID;}
	
    public void setPacketNum(int i) {packetNum=i;}
    public void setChannelID(int i) {channelID=i;}
	
    public void setID(int id) {
	moteID=id;
	initadjectSensorMap(id);
    }
    /**
     *	Add a new data log entry
     *	<p>
     *	This method is called to add the data entry and the corresponding car information
     *	into the sensor's data log.
     *	@param	i	The data value to be added
     *	@param	c	The car which is related to this data log
     */
    synchronized public void addData(int i, Car c)
    {
	lastData = i;
		
	// Update the data in the log
	DataLog d = (DataLog)data.get(new Integer(c.getID()));
		
	if (d != null)
	    {
		d.setTime(System.currentTimeMillis());
		d.setData(i);
	    }
	else
	    {
		d = new DataLog (i);
		d.setTime(System.currentTimeMillis());
		data.put (new Integer(c.getID()), d);
	    }
    }
    // Return the last data for a specific car
    synchronized public int getLastData (Car c)
    {
	DataLog d = (DataLog)data.get(new Integer(c.getID()));
	if (d == null)
	    return 0;
	else
	    return d.getData();
    }
    // Return the last time when the car has updated the sensor's data
    synchronized public long getLastTime (Car c)
    {
	DataLog d = (DataLog)data.get(new Integer(c.getID()));
	if (d == null)
	    return 0;
	else
	    return d.getTime();
    }
    public void setLastData( int d ) {lastData =d;}
    // Used to check if the new data is worth logging
    public int getLastData ()
    {

	return lastData;
    }

    private Road road; // The road it belongs to
    private double pos=0.0; // Position of the sensor
    private double percent=0.0; // Relative position in the road (starting from the road's beginning point

    public void setRoad (Road r) { road = r; }
    public void setPos (double pos) { this.pos = pos; }

    public Road getRoad () { return road; }
    public double getPos () { return pos; }

    public double getPercent ()
    {
	if (percent==0.0 && pos!=0.0 && road!=null)
	    percent = (pos-1.0)/road.getLength();
	return percent;
    }
	
    // FIX ME!!!!!
    public boolean isBeginning()
    {
	if (road.getSensor().get(0) == this)
	    return true;
	else
	    return false;
    }
	
    public boolean isEnd()
    {
	int total = road.getSensor().size()-1;
	if (road.getSensor().get(total) == this)
	    return true;
	else
	    return false;
    }
    // FIX ME!!!!!
    public boolean isNearCross()
    {
	if (road.getSensor().get(1) == this)
	    return true;
	else
	    return false;
    }
    public  HashMap getAdjectSensorMap() {
	return adjectSensorMap;
    }
    public void setAdjectSensorMap(HashMap adjectSensorMap) {
	this.adjectSensorMap = adjectSensorMap;
    }
}