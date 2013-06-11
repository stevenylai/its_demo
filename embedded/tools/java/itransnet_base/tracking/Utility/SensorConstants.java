package itransnet_base.tracking.Utility;

public interface SensorConstants
{
	public static final short FIFO_ROAD = 0;
	public static final short LIFO_ROAD = 1;

	public static final short DIRECTION_FORWARD = 0;
	public static final short DIRECTION_BACKWARD = 1;
	public static final short DIRECTION_LEFT = 2;
	public static final short DIRECTION_RIGHT = 3;

	public static final short SENSOR_TYPE_UNKNOWN = 0;
	public static final short SENSOR_TYPE_END = 1;
	public static final short SENSOR_TYPE_START = 2;
	public static final short SENSOR_TYPE_NORM = 3;
	public static final short SENSOR_TYPE_SIMPLE = 4;
	public static final short SENSOR_TYPE_ONLY = 8;
	public static final short SENSOR_TYPE_PARK = 9;
	public static final short SENSOR_TYPE_CAR = 10;
	
	public static final short OPER_EVERY_MSG = 5;
	public static final short OPER_SUMMARY_MSG = 6;
	public static final short OPER_LIGHT = 7;
	public static final short OPER_START	= 0x31;
	public static final short OPER_COLLISION	= 0x32;
	public static final short OPER_NO_COLLISION	= 0x33;
	public static final short OPER_STOP	= 0x34;
	public static final short OPER_TURN_RIGHT	= 0x35;
	public static final short OPER_TURN_LEFT	= 0x36;
	
	public static final short SENSOR_UNCOVERED = 0;
	public static final short SENSOR_COVERED = 1;
}
