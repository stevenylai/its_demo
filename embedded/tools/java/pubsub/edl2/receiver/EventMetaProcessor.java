package pubsub.edl2.receiver;

import java.util.*;

// Helper class for the EventMetaInfo array list
public class EventMetaProcessor {
	public ArrayList <EventMetaInfo> meta;
	public EventMetaProcessor (ArrayList <EventMetaInfo> meta) {
		this.meta=meta;
	}
	public EventMetaInfo getEventMeta(int subID) {
		for (int i=0; i<meta.size(); i++) {
			EventMetaInfo e = meta.get(i);
			if ((int)(e.subID)==subID) {
				return e;
			}
		}
		return null;
	}
}

