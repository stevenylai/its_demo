package pubsub.edl2.receiver.notifier;

import pubsub.edl2.receiver.*;
import pubsub.edl2.*;

import java.io.*;
import java.util.*;

public class TestNotifier implements Runnable, EventNotifier {
	MainComposite compiler;
	EventReceiver receiver;

	public TestNotifier() {
	}
	public void notify(EventInstanceInfo e) {
		/*System.out.println("Received event "+e.meta.subID+" from "+e.sourceID);
		if (e.meta.fields.size()>0) {
			System.out.print("Event Contents {");
			for (int i=0; i<e.meta.fields.size(); i++) {
				if (i<e.meta.fields.size()-1)
					System.out.print(e.meta.fields.get(i)+": "+e.data[i]+", ");
				else
					System.out.print(e.meta.fields.get(i)+": "+e.data[i]);
			}
			System.out.println("}");
		}*/
		System.out.println(e.sourceID+": "+e.meta.subID+": "+e.data[2]+": "+System.currentTimeMillis());
	}
	public void run () {
		EventBuffer buffer = new EventBuffer();
		buffer.notifiers.add(this);
		if (receiver!=null)
			receiver.notifiers.clear();
		receiver=new EventReceiver();
		receiver.notifiers.add(buffer);
		compiler=new MainComposite();
		MainComposite.version++;
		compiler.receiver=receiver;
		compiler.compile(new InputStreamReader(System.in));

		while (true) {
			try {
				Thread.sleep(1000);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args) throws Exception {
		TestNotifier n = new TestNotifier();
		Thread t = new Thread(n);
		t.start();
	}
}

