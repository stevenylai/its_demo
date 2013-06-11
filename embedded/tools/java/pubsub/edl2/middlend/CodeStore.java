package pubsub.edl2.middlend;
import java.util.*;

public class CodeStore {
	private CodeRepository topLevelCode;
	private boolean lastIsLabel;
	private Vector instructions;

	public CodeStore () {
		instructions = new Vector();
		lastIsLabel=false;
	}
	public void addLabel (String label) {
		if (!lastIsLabel)
			instructions.add(label);
		else
			System.out.println("Warning: duplicated labels found in the code.");

		lastIsLabel=true;
	}
	public void appendInstruction (String instr) {
		String lastInstruction = (String)instructions.remove(instructions.size()-1);
		instructions.add(lastInstruction+" "+instr);
	}
	public void addInstruction (String instr) {
		if (!lastIsLabel)
			instructions.add(instr);
		else {
			String lastLabel = (String)instructions.remove(instructions.size()-1);
			instructions.add(lastLabel+": "+instr);
		}
		lastIsLabel=false;
	}
	public void setTopLevelCode (CodeRepository top) { this.topLevelCode=top; }
	public CodeRepository getTopLevelCode () { return this.topLevelCode; }
	public Vector getInstructions () { return this.instructions; }
	public void printCodes(int level) {
		for (int i=0; i<instructions.size(); i++) {
			for (int j=0; j<level; j++)
				System.out.print(" ");
			System.out.println((String)instructions.get(i));
		}
	}
	public String getCodes() {
		String codes="";
		for (int i=0; i<instructions.size(); i++) {
			codes=codes+(String)instructions.get(i)+"\n";
		}
		return codes;
	}
}
