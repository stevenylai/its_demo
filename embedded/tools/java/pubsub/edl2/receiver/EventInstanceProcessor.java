package pubsub.edl2.receiver;

import java.util.*;

// Helper class for the EventInstance array list
public class EventInstanceProcessor {
	public ArrayList <EventInstanceInfo> instance;
	public EventInstanceProcessor (ArrayList <EventInstanceInfo> instance) {
		this.instance=instance;
	}
	public int instanceAmount(int subID) {
		int total=0;
		for (int i=0; i<this.instance.size(); i++) {
			EventInstanceInfo e = this.instance.get(i);
			if (e.meta.subID==subID)
				total++;
		}
		return total;
	}
	public EventInstanceInfo getEventInstanceByIdx(int subID, int idx) {
		int count=0;
		for (int i=0; i<instance.size(); i++) {
			EventInstanceInfo e = instance.get(i);
			if ((int)(e.meta.subID)==subID) {
				if (count==idx) {
					count++;
					return e;
				} else
					count++;
			}
		}
		return null;
	}
	public EventInstanceInfo getEventInstance(int subID, int instanceID) {
		for (int i=0; i<instance.size(); i++) {
			EventInstanceInfo e = instance.get(i);
			if ((int)(e.meta.subID)==subID && e.instanceID==instanceID) {
				return e;
			}
		}
		return null;
	}
	public int getNewInstanceID(int subID) {
		int idx=0;
		for (int i=0; i<instance.size(); i++) {
			EventInstanceInfo e = instance.get(i);
			if ((int)(e.meta.subID)==subID) {
				idx=e.instanceID+1;
			}
		}
		return idx;
	}
}
