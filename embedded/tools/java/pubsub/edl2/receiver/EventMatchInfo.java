package pubsub.edl2.receiver;

import java.util.*;

public class EventMatchInfo {
	
	public int subID; // The subID of the subevent
	public int totalInstance; // Total number of instance of the event in the event instance list
	public int totalType; //The number of occurrence of the event type in the composite event
	public int count;
	public ArrayList <Integer> combination;
	public ArrayList <Integer> permutation;

	public EventMatchInfo () {
		totalInstance=0;
		totalType=0;
		count=0;
		combination = new ArrayList <Integer> ();
		permutation = new ArrayList <Integer> ();
	}
	public void initPermutation () {
		combination.clear();
		permutation.clear();
		for (int i=0; i<totalType && i<totalInstance; i++) {
			Integer n = new Integer(i); 
			combination.add(n);
			permutation.add(n);
		}
		//System.out.println("Permutation initialized");
	}
	public void resetPermutation () {
		for (int i=0; i<combination.size(); i++) {
			permutation.set(i, combination.get(i));
		}
	}
	public int getEventInstanceIdx() {
		return permutation.get(count).intValue();
	}
	public String getString(ArrayList <Integer> l) {
		String allStr="(";
		for (int i=0; i<l.size(); i++) {
			if (i<l.size()-1)
				allStr=allStr+l.get(i).toString()+", ";
			else
				allStr=allStr+l.get(i).toString();
		}
		return allStr+")";
	}
	// This algorithm is based on combination generation in lexicographic order
	public void nextCombination () {
		int max_val=totalInstance-1;
		for (int i=combination.size()-1; i>=0; i--, max_val--) {
			Integer m = combination.get(i);
			if (max_val!=m.intValue()) {
				for (int j=i; j<combination.size(); j++) {
					Integer n = new Integer(m.intValue()+j-i+1);
					combination.set(j, n);
				}
				break;
			}
		}
	}
	// This algorithm is based on permutation generation in lexicographic order
	public void nextPermutation () {
		boolean permutationFound=false;
		for (int i=permutation.size()-2; i>=0; i--) {
			// Find the rightmost entry (d) with the property such that (d<r)
			// r is d's right neighbor
			int d = permutation.get(i).intValue();
			int r = permutation.get(i+1).intValue();
			if (d<r) {
				//System.out.print("Permutation found! Original: "+getString(permutation));
				permutationFound=true;
				// Now we need to swap (d) with the first element (s) to its right
				// which is smaller than (d)
				for (int j=permutation.size()-1; j>=i+1; j--) {
					int  s = permutation.get(j).intValue();
					if (s>d) {
						swap(permutation, i, j);
						break;
					}
				}
				// Arrange the rest of the items next to (new) (d) in increasing order
				// (They were in decreasing order)
				for (int j=i+1, k=permutation.size()-1; j<k; j++, k--) {
					swap(permutation, j, k);
				}
				//System.out.println(". Now: "+getString(permutation));
				break;
			}
		}
		if (!permutationFound) {
			nextCombination();
			resetPermutation();
		}
	}
	private void swap (ArrayList <Integer> l, int i, int j) {
		Integer a1=l.get(i);
		Integer a2=l.get(j);
		l.set(j, a1);
		l.set(i, a2);
	}
}
