package pubsub.edl2.receiver;

import java.util.*;
import java.util.regex.*;
import java.lang.reflect.*;
// TinyOS related
import net.tinyos.util.*;
import net.tinyos.message.*;

import vm_specific.*;
import pubsub.edl2.*;
import pubsub.edl2.symbols.*;
import pubsub.edl2.middlend.*;
import pubsub.edl2.backendPSware.*;
import pubsub.edl2.receiver.opcodes.*;
import pubsub.edl2.receiver.notifier.*;

public class EventReceiver implements MessageListener, Runnable {
	// Event stuff
	public ArrayList <EventMetaInfo> meta;
	public ArrayList <EventInstanceInfo> instance;
	public EventMatcher matcher;
	// Opcode stuff
	Pattern regexp;
	public Vector <String> codes;
	// VM stuff
	public int pc;
	public String exception;
	public static final int MATE_STATE_STOPPPED=0;
	public static final int MATE_STATE_RUNNING=1;
	public int state;
	public int rounds;
	public Stack <Integer> opStack;
	// Other stuff
	public ArrayList <EventNotifier> notifiers;
	public Vector <PSWareListener> listeners;
	public PSWareClock clock;

	public EventReceiver () {
		matcher = new EventMatcher(this);
		notifiers = new ArrayList <EventNotifier>();
		notifiers.add(new DummyNotifier());

		//EventBuffer buffer = new EventBuffer();
		//buffer.notifiers.add(new DBNotifier());
		//notifiers.add(buffer);

		codes = new Vector<String>();
		instance = new ArrayList <EventInstanceInfo> ();
		meta = new ArrayList <EventMetaInfo> ();
		listeners = new  Vector <PSWareListener> ();
		regexp = Pattern.compile("(\\w+:\\s*)?(\\w+)(\\s*\\w+)?");
		rounds=0;
		startClock();
	}
	public void startClock () {
		clock = new PSWareClock();
		Thread clock_thread = new Thread(clock);
		clock_thread.start();
	}
	public void handleException () {
		System.out.println("Handling exception, handler label: "+exception);
		if (exception==null)
			state=EventReceiver.MATE_STATE_STOPPPED;
		else {
			opStack.push(new Integer(0));
			LabelFinder finder = new LabelFinder(exception, codes);
			pc = finder.getIdx();
		}
	}
	public void initVM () {
		pc=0;
		state=EventReceiver.MATE_STATE_RUNNING;
		exception=null;
		opStack = new Stack<Integer>();
	}
	public void printEventInfo () {
		EventInstanceProcessor processor = new EventInstanceProcessor(instance);
		for (int i=0; i<meta.size(); i++) {
			EventMetaInfo em = meta.get(i);
			System.out.print("Event meta ("+em.subID);
			if (em.isSubscribed())
				System.out.print(", subscribed");
			if (em.isComposite())
				System.out.print(", composite");
			System.out.print("): ");
			for (int j=0; j<processor.instanceAmount(em.subID); j++) {
				EventInstanceInfo ei = processor.getEventInstanceByIdx(em.subID, j);
				System.out.print(ei.instanceID+" ");

			}
			System.out.println("");
		}
	}
	public synchronized void execute() throws ClassNotFoundException, InstantiationException,
		NoSuchMethodException, IllegalAccessException, InvocationTargetException {
		initVM();
		while(pc<codes.size() && state==EventReceiver.MATE_STATE_RUNNING) {
			String instr = codes.get(pc++);
			Matcher match = regexp.matcher(instr);
			if (!match.matches()) {
				System.out.println("Could not parse " + instr);
				continue;
			}
			String label = match.group(1);
			if (label!=null) label=label.replace(':', ' ').trim();
			String opcode = match.group(2);
			String operand = match.group(3);
			if (operand!=null) operand=operand.trim();
			System.out.println("Executing opcode: "+opcode+" operand: "+operand+" label: "+label);

			Class cl = Class.forName("pubsub.edl2.receiver.opcodes.OP"+opcode);
			Object obj = cl.newInstance();

			Class partypes[];
			Object arglist[];

			partypes = new Class[1];
			partypes[0] = Class.forName("java.lang.String");
			Method m_operand = cl.getMethod("setOperand",partypes);
			arglist = new Object[1];
			arglist[0] = operand;
			m_operand.invoke(obj, arglist);

			partypes = new Class[1];
			partypes[0] = Class.forName("java.lang.String");
			Method m_label = cl.getMethod("setLabel",partypes);
			arglist = new Object[1];
			arglist[0] = label;
			m_label.invoke(obj, arglist);

			partypes = new Class[1];
			partypes[0] = Class.forName("pubsub.edl2.receiver.EventReceiver");
			Method m_exec = cl.getMethod("execute",partypes);
			arglist = new Object[1];
			arglist[0] = this;
			m_exec.invoke(obj, arglist);
		}
	}
	public void notify (EventInstanceInfo ei) {
		for (int i=0; i<notifiers.size(); i++) {
			EventNotifier notifier = notifiers.get(i);
			notifier.notify(ei);
		}
	}
	public void messageReceived(int dest_addr, Message msg) {
		EventInstanceMsg e = new EventInstanceMsg(msg.dataGet());
		EventMetaProcessor processor_meta = new EventMetaProcessor(this.meta);
		EventMetaInfo em = processor_meta.getEventMeta(e.get_subID());

		EventInstanceInfo ei = matcher.createEventInstance(e.get_subID());
		ei.sourceID=e.get_sourceID();
		ei.data=e.get_content();
		System.out.println("Event received: " +e);
		if (em.isSubscribed()) {
			notify(ei);
		} else {
			try {
				execute();
			} catch (Exception exception) {
				exception.printStackTrace();
			}
		}
	}
	public void run () {
		try {
			execute();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void main(String args[]) {
		OPCodes.displayDebugMsg=true;
		EventReceiver e = new EventReceiver();
		e.codes = new Vector<String>();
		e.codes.add("2pushc10 1");
		e.codes.add("2pushc10 2");
		e.codes.add("add");
		e.codes.add("halt");
		try {
			e.execute();
		} catch (Exception exception) {
			exception.printStackTrace();
		}
	}
}
