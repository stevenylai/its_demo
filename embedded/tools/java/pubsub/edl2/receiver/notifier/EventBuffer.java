package pubsub.edl2.receiver.notifier;

import pubsub.edl2.receiver.*;
import pubsub.edl2.*;

import java.util.*;

public class EventBuffer implements Runnable, EventNotifier {
	public ArrayList <EventInstanceInfo> buffer;
	public ArrayList <EventNotifier> notifiers;
	public boolean isProcessing;

	public EventBuffer () {
		buffer = new ArrayList <EventInstanceInfo>();
		notifiers = new ArrayList <EventNotifier>();
		isProcessing=false;
	}
	public void notify(EventInstanceInfo e) {
		buffer.add(e);
		tryToNotify();
	}
	public void tryToNotify () {
		if (isProcessing)
			return;

		isProcessing=true;
		while (buffer.size()>0) {
			EventInstanceInfo e = buffer.remove(0);
			for (int i=0; i<notifiers.size(); i++) {
				EventNotifier notifier = notifiers.get(i);
				notifier.notify(e);
			}
		}
		isProcessing=false;
	}
	public void run () {
	}
}
