package pubsub.edl2.middlend;
import pubsub.edl2.symbols.*;
import java.util.*;

public class ClassCode extends CodeStore{
	private String id;
	private String parentClassID;
	private Vector parentInterface;

	private Vector fields;
	private Vector methods;
	private int subscribeID;

	public ClassCode () {
		super();
		fields = new Vector();
		methods = new Vector();
	}
	public ClassCode (ClassEntry ce) {
		this();
		setID(ce.getID());
		setSubscribeID(ce.getSubscribeID());
	}
	public void setID (String id) { this.id=id; }
	public void setParentClassID(String parentClassID) { this.parentClassID=parentClassID; }
	public void setParentInterface(Vector parentInterface) { this.parentInterface=parentInterface; }
	public void setSubscribeID(int subscribeID) { this.subscribeID=subscribeID; }

	public String getID () { return id; }
	public String getParentClassID () { return parentClassID; }
	public Vector getParentInterface () { return parentInterface; }
	public int getSubscribeID () { return subscribeID; }

	public void addField (ClassFieldCode c) {
		fields.add(c);
		c.setTopLevelCode(getTopLevelCode());
	}
	public void addMethod (MethodCode c) {
		methods.add(c);
		c.setTopLevelCode(getTopLevelCode());
	}
	public Vector getAllInstructions() {
		Vector codes=new Vector();
		codes.addAll(getInstructions());
		for (int i=0; i<methods.size(); i++) {
			MethodCode c =  (MethodCode)methods.get(i);
			codes.addAll(c.getAllInstructions());
		}
		return codes;
	}
	public void printCodes(int level) {
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("Codes for class "+id);
		super.printCodes(level+1);
		for (int i=0; i<methods.size(); i++) {
			MethodCode mc = (MethodCode)methods.get(i);
			mc.printCodes(level+2);
		}
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("End of Codes for class "+id);
	}
	public String getCodes() {
		String codes ="";
		// FIXME: only method codes are output
		for (int i=0; i<getInstructions().size(); i++)
			codes=codes+(String)getInstructions().get(i)+"\n";
		for (int i=0; i<methods.size(); i++) {
			MethodCode mc = (MethodCode)methods.get(i);
			codes=codes+mc.getCodes()+"\n";
		}
		return codes;
	}
}
