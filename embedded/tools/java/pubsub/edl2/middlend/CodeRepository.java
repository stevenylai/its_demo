package pubsub.edl2.middlend;
import java.util.*;
import pubsub.edl2.receiver.*;

public class CodeRepository extends CodeStore {
	private CodeStore maincode;
	private Vector<ClassCode> classCodes;
	public Vector<EventMetaInfo> meta;
	private Vector compositeCodes;
	public CodeRepository () {
		super();
		setTopLevelCode(this);
		classCodes=new Vector<ClassCode>();
		meta=new Vector<EventMetaInfo>();
		compositeCodes=new Vector();

		maincode = new CodeStore();
		maincode.setTopLevelCode(getTopLevelCode());
		//addInstruction("2pushc10 1");
		//addInstruction("2jumps10 main");
	}
	public CodeStore getMainCode () { return this.maincode; }
	public Vector getClasses() { return this.classCodes; }

	public void addClass (ClassCode c) {
		classCodes.add(c);
		c.setTopLevelCode(getTopLevelCode());
	}
	public void addComposite (CompositeCode wc) {
		compositeCodes.add(wc);
		wc.setTopLevelCode(getTopLevelCode());
	}
	// Human readable format
	public void printCodes(int level) {
		super.printCodes(level);
		for (int i=0; i<classCodes.size(); i++) {
			ClassCode c = classCodes.get(i);
			c.printCodes(level);
		}
		for (int i=0; i<compositeCodes.size(); i++) {
			CompositeCode c = (CompositeCode)compositeCodes.get(i);
			c.printCodes(level);
		}
		maincode.printCodes(level);
	}
	// Input to the receiver (in vector)
	public Vector getAllInstructions() {
		Vector codes=new Vector();
		codes.addAll(maincode.getInstructions());
		for (int i=0; i<classCodes.size(); i++) {
			ClassCode c =  classCodes.get(i);
			codes.addAll(c.getAllInstructions());
		}
		codes.add("housekeep");
		return codes;
	}
	// Input to the assembler (in string)
	public String getFilterCodes() {
		String codes = maincode.getCodes()+"\n";
		for (int i=0; i<classCodes.size(); i++) {
			ClassCode c = classCodes.get(i);
			codes = codes+c.getCodes();
		}
		codes=codes+"housekeep";
		return codes;
	}
	public String [] getCompositeCodes() {
		String codeHead = "";
		for (int i=0; i<classCodes.size(); i++) {
			ClassCode c = classCodes.get(i);
			codeHead = codeHead+c.getCodes();
		}
		String [] codes = new String[compositeCodes.size()];
		for (int i=0; i<codes.length; i++) {
			CompositeCode wc = (CompositeCode)compositeCodes.get(i);
			codes[i]=wc.getCodes()+codeHead;
		}
		return codes;
	}
}
