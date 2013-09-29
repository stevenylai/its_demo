package itransnet_base.tracking.Server.DataEngine;

public class DataLog
{
	private int data;
	private long logTime;
	
	public DataLog (int data) {this.data = data;}
	
	public int getData () { return data;}
	public long getTime () {return logTime;}
	
	public void setData (int data) { this.data = data;}
	public void setTime (long t) { logTime = t;}
}