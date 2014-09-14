package itransnet_base.tracking.Server.DataEngine;

import itransnet_base.tracking.Utility.SensorConstants;

import java.util.HashMap;

public interface Sensor extends SensorConstants {
    public int getPacketNum();
    public int getChannelID();
    public int getID();
    public double getPos ();

    public void setPacketNum(int i);
    public void setChannelID(int i);
    public void setID(int i);
    public void setPos (double pos);

    public void addData(int i, Car c);
    public long getLastTime (Car c);

    public HashMap getAdjectSensorMap();
    public  void setAdjectSensorMap(HashMap adjectSensorMap) ;

    public Road getRoad ();
}
