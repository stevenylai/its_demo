package pubsub.edl2.receiver;

import java.util.*;

public class EventMatcher {
	public EventReceiver vm;
	public ArrayList <EventMatchInfo> matchList;
	public boolean typeInProgress;
	public int totalEventPermutation;
	public int currentEventPermutation;
	private EventInstanceInfo detecting;

	public EventMatcher(EventReceiver vm) {
		this.vm=vm;
		deleteEventMatchInfo();
	}

	public EventInstanceInfo findMatchInstance(int subID) {
		if (detecting!=null && detecting.meta.subID==subID)
			return detecting;
		if (matchList==null)
			return null;
		EventInstanceProcessor processor = new EventInstanceProcessor(vm.instance);
		int totalAmount = processor.instanceAmount(subID);
		EventMatchInfo e = getEventMatchInfo(subID);
		if (e==null) {
			e = new EventMatchInfo();
			e.subID=subID;
			e.totalInstance = totalAmount;
			matchList.add(e);
		}
		if (typeInProgress) {
			e.totalType++;
			e.initPermutation();
		}

		EventInstanceInfo ei=null;
		if (e.count<totalAmount)
			 ei = processor.getEventInstanceByIdx(subID, e.getEventInstanceIdx());
		e.count++;

		return ei;
	}
	public int permutationTotal (int n, int r) {
		int total=1;
		if (n<r)
			return 0;
		for (int i=n-r+1; i<=n; i++) {
			total=total*i;
		}
		return total;
	}
	public int combinationTotal (int n, int r) {
		int total = permutationTotal(n, r);
		for (int i=2; i<=r; i++) {
			total=total/i;
		}
		return total;
	}
	public boolean moreEventMatch () {
		if (totalEventPermutation>currentEventPermutation)
			return true;
		else
			return false;
	}
	public void deleteEventMatchInfo () {
		totalEventPermutation=0;
		currentEventPermutation=0;
		typeInProgress=false;
		matchList=null;
		detecting=null;
	}
	public void createEventMatchInfo (int subID) {
		if (matchList==null) {
			matchList = new ArrayList <EventMatchInfo> ();
			typeInProgress=true;
		}
	}
	public EventMatchInfo getEventMatchInfo (int subID) {
		for (int i=0; i<matchList.size(); i++) {
			EventMatchInfo e = matchList.get(i);
			if ((int)(e.subID)==subID) {
				return e;
			}
		}
		return null;
	}
	public void eventDetectionResult(int subID, int instanceID, boolean result) {
		EventInstanceProcessor processor = new EventInstanceProcessor(vm.instance);
		EventInstanceInfo e = processor.getEventInstance(subID, instanceID);
		if (!result) {
			vm.instance.remove(e);
		} else if (e.meta.isSubscribed()) {
			vm.notify(e);
		}
		if (typeInProgress) {
			typeInProgress=false;
			totalEventPermutation=getTotalEventPermutation();
		}
		resetEventCounters();
		if (currentEventPermutation>=totalEventPermutation)
			deleteEventMatchInfo();
		else {
			nextPermutation();
			currentEventPermutation++;
		}
	}
	public void resetEventCounters() {
		if (matchList==null)
			return;
		for (int i=0; i<matchList.size(); i++) {
			EventMatchInfo e = matchList.get(i);
			e.count=0;
		}
	}
	public int getTotalEventPermutation() {
		int total=1;
		for (int i=0; i<matchList.size(); i++) {
			EventMatchInfo e = matchList.get(i);
			total=total*permutationTotal(e.totalInstance, e.totalType);
		}
		return total;
	}
	public void nextPermutation () {
		int currentTotal=1;
		EventMatchInfo e;
		for (int i=0; i<matchList.size(); i++) {
			e = matchList.get(i);
			if (permutationTotal(e.totalInstance, e.totalType)==1)
				continue;

			currentTotal = currentTotal*permutationTotal(e.totalInstance, e.totalType);
			if (currentEventPermutation%currentTotal!=0) {
				e.nextPermutation();
				break;
			} else
				e.initPermutation();
		}
	}
	public EventInstanceInfo createEventInstance(int subID) {
		EventInstanceProcessor processor = new EventInstanceProcessor(vm.instance);
		EventMetaProcessor processor_meta = new EventMetaProcessor(vm.meta);
		EventMetaInfo em = processor_meta.getEventMeta(subID);
		int newInstanceID = processor.getNewInstanceID(subID);
		if (em!=null) {
			EventInstanceInfo e = new EventInstanceInfo(em);
			e.instanceID=newInstanceID;
			e.time=vm.clock.getClock();
			vm.instance.add(e);
			if (em.isComposite()) {
				createEventMatchInfo(subID);
			}
			detecting=e;
			return e;
		}
		return null;
	}
	public void gc() {
		for (int i=vm.instance.size()-1; i>=0; i--) {
			EventInstanceInfo e = vm.instance.get(i);
			int currentTime=vm.clock.getClock();
			if (currentTime-e.time>e.meta.lifetime) {
				vm.instance.remove(i);
			}
		}
	}

	public void printMatcher () {
		System.out.print(toString());
	}
	public String toString() {
		String allStr = "Total event permutation: "+totalEventPermutation+
			". working on: "+currentEventPermutation+"\n";
		for (int i=0; i<matchList.size(); i++) {
			EventMatchInfo e = matchList.get(i);
			allStr = allStr+"Matches for "+e.subID+
				", Total type: "+e.totalType+
				", Total instance: "+e.totalInstance+
				", Count: "+e.count+"\n";

			allStr = allStr+"Combination ("+e.combination.size()+"): (";
			for (int j=0; j<e.combination.size(); j++) {
				allStr = allStr+e.combination.get(j).toString();
				if (j<e.combination.size()-1)
					allStr = allStr+", ";
			}
			allStr = allStr+")\n";

			allStr = allStr+"Permutation ("+e.permutation.size()+"): (";
			for (int j=0; j<e.permutation.size(); j++) {
				allStr = allStr+e.permutation.get(j).toString();
				if (j<e.permutation.size()-1)
					allStr = allStr+", ";
			}
			allStr = allStr+")\n";
		}
		return allStr;
	}
}
