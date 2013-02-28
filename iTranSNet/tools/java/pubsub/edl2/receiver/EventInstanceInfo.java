package pubsub.edl2.receiver;

public class EventInstanceInfo {
	public EventMetaInfo meta;
	public int sourceID;
	public int time;
	public int instanceID;
	public int [] data;

	public EventInstanceInfo (EventMetaInfo meta) {
		this.meta=meta;
		this.data = new int [meta.length];
	}
	public String toString () {
		return "EventInstance: ("+meta.subID+", "+instanceID+")";
	}
}

