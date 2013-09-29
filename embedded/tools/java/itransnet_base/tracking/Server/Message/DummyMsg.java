package itransnet_base.tracking.Server.Message;

// A very simple message for testing
public class DummyMsg extends net.tinyos.message.Message
{
    /** The default size of this message type in bytes. */
    public static final int DEFAULT_MESSAGE_SIZE = 26;

    /** The Active Message type associated with this message. */
    public static final int AM_TYPE = 10;
    
	private int moteID;
	private int data;

    /** Create a new OscopeMsg of size 26. */
    public DummyMsg() {
        super(DEFAULT_MESSAGE_SIZE);
        amTypeSet(AM_TYPE);
    }

	public int get_sourceMoteID()
	{
		return moteID;
	}
	public int getElement_data (int index)
	{
		return data;
	}
	
	public void setID (int ID) { moteID = ID; }
	public void setData (int data) { this.data = data; }
	public int getID () { return moteID; }
	public int getData () { return data; }
	
	// Rubbish methods:
	public int numElements_data()
	{
		return 1;
	}
	public int get_lastSampleNumber()
	{
		return 1;
	}
	public int get_channel ()
	{
		return 1;
	}
}
