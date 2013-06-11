package pubsub.edl2.middlend;

import java.util.*;
public class CompositeCode extends CodeStore {
	private int id;
	public CompositeCode (int id) {
		this.id = id;
	}
	public int getID () { return this.id; }

	public void printCodes(int level) {
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("Codes for composite: "+id);
		super.printCodes(level+1);
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("End of Codes for composite: "+id);
	}
	public String getCodes() {
		return super.getCodes();
	}
}
