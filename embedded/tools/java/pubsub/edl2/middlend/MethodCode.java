package pubsub.edl2.middlend;
import pubsub.edl2.symbols.*;
import java.util.*;

public class MethodCode extends CodeStore {
	private Vector modifiers;
	private String type;
	private String id;
	private Vector parameters;
	public String label;

	public MethodCode (ClassMethod cm) {
		super();
		setType(cm.getType());
		setID(cm.getID());
		setModifiers(cm.getModifiers());
		setParameters(cm.getParameters());
		setLabel(cm.getLabel());
	}
	public MethodCode (String id) {
		super();
		setID(id);
	}
	public void setType (String type) { this.type=type; }
	public void setID (String id) { this.id=id; }
	public void setModifiers (Vector modifiers) { this.modifiers=modifiers; }
	public void setParameters (Vector parameters) { this.parameters=parameters; }
	public void setLabel (String label) { this.label=label; }

	public String getType () { return this.type; }
	public String getID () { return this.id; }
	public Vector getParameters () { return this.parameters; }
	public Vector getModifiers () { return this.modifiers; }
	public String getLabel () { return this.label; }

	public Vector getAllInstructions() {
		Vector codes=new Vector();
		codes.addAll(getInstructions());
		return codes;
	}
	public void printCodes(int level) {
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("Codes for method "+id);
		super.printCodes(level+1);
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println("End of Codes for method "+id);
	}
	public String getCodes() {
		//String codes = label+": ";
		return super.getCodes();
	}
}

