package itransnet_base.tracking.Server.Manager;

import itransnet_base.tracking.Server.DataEngine.*;

public interface Manager
{
	public long getRefreshPeriod();
	public int getPanelWidth();
  public int getPanelHeight();
  public int getSumaryPanelWidth ();
  public int getSumaryPanelHeight();
  public double getUnit();
  
  public boolean drawSensor ();
  public boolean drawSensorID ();
  
  public Map getMap();
}
