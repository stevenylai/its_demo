package pubsub.edl2.receiver.notifier;

import pubsub.edl2.receiver.*;
import java.util.*;

public interface EventNotifier {
	public void notify(EventInstanceInfo e);
}
