package pubsub.edl2.receiver;

import java.util.*;

public class EventMatcherTest {
	static int totalType=5;
	static int maxInstance=5;
	public static int generateMask(int i) {
		int mask=0x80;
		mask=mask>>i;
		return mask;
	}
	public static byte generateType(boolean subscribed, boolean isPrimitiveEvent) {
		byte result = (byte)0;
		if (subscribed) {
			result=(byte)((int)result|generateMask(0));
		}
		if (!isPrimitiveEvent) {
			result=(byte)((int)result|generateMask(1));
		}
		return result;
	}
	public static void testType() {
		EventMetaInfo meta = new EventMetaInfo();
		meta.type=generateType(true, false);
		meta.printType();
	}
	public static void generateTestMeta(EventReceiver vm) {
		ArrayList <EventMetaInfo> metaList = new ArrayList <EventMetaInfo> ();

		for (int i=0; i<totalType; i++) {
			EventMetaInfo meta = new EventMetaInfo();
			meta.subID = (short)i;
			meta.length = (short)1;
			meta.type = (short)0;
			meta.rate = 1;
			meta.lifetime = 1;
			if (i==0)
				meta.type=generateType(true, false);
			metaList.add(meta);
		}

		EventMetaInfo meta = new EventMetaInfo();
		meta.subID = (short)totalType;
		meta.length = (short)1;
		meta.type = generateType(false, false);;
		meta.rate = 1;
		meta.lifetime = 1;
		metaList.add(meta);

		vm.meta=metaList;
	}
	public static void generateTestInstance(EventReceiver vm) {
		ArrayList <EventInstanceInfo> instanceList = new ArrayList <EventInstanceInfo> ();

		for (int i=0; i<vm.meta.size(); i++) {
			Random r = new Random();
			int inst_amt = r.nextInt(maxInstance);
			if (inst_amt==0)
				inst_amt=1;
			EventMetaInfo em = vm.meta.get(i);
			for (int j=0; j<inst_amt; j++) {
				EventInstanceInfo instance = new EventInstanceInfo(em);
				instance.instanceID = (short)j;
				instanceList.add(instance);
			}
		}
		vm.instance=instanceList;
	}

	public static void testEventOneRound(EventReceiver vm) {
		EventInstanceInfo e = vm.matcher.createEventInstance(totalType);
		EventInstanceInfo e1 = vm.matcher.findMatchInstance(0);
		EventInstanceInfo e2 = vm.matcher.findMatchInstance(1);
		EventInstanceInfo e3 = vm.matcher.findMatchInstance(1);
		vm.matcher.eventDetectionResult(0, 0, true);
		if (vm.matcher.moreEventMatch())
			vm.matcher.printMatcher();
	}
	public static void testEvent(EventReceiver vm) {
		testEventOneRound(vm);
		while (vm.matcher.moreEventMatch()) {
			testEventOneRound(vm);
		}
	}
	public static void testPermutation(EventMatcher matcher) {
		System.out.println(matcher.combinationTotal(5, 3));
	}

	public static void main (String args[]) {
		EventReceiver receiver = new EventReceiver();
		//testPermutation(receiver.matcher);
		//testType();
		generateTestMeta(receiver);
		generateTestInstance(receiver);
		receiver.printEventInfo();
		System.out.println("");
		testEvent(receiver);
		System.out.println("Finished testing");
	}
}
