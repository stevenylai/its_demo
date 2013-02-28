package pubsub.edl2.backendPSware;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import java.util.regex.*;

public class ScriptAssembler {

	private ConstantMapper mapper;

	// The pattern is:
	//   group 1: 0 or 1 labels, which are <word>:
	//   group 2: the instruction proper
	//   group 3: 0 or 1 embedded opreands, which are <number>
	Pattern regexp = Pattern.compile("(\\w+:\\s*)?(\\w+)(\\s*\\w+)?");
	Pattern opcodePattern = Pattern.compile("(\\d*)(\\D+)(\\d*)"); 
	//Pattern regexp = Pattern.compile("(\\w+)\\s*(\\w+)?"); 
	
	public ScriptAssembler(ConstantMapper mapper) {
		this.mapper = mapper;
	}
	
	public String toHexString(AssemblyTokenizer tokenizer) throws IOException {
		byte[] program = toByteCodes(tokenizer);
		String bytes = "";
		for (int i = 0; i < program.length; i++) {
			String val = Integer.toHexString(program[i] & 0xff);
			if (val.length() == 1) {
				val = "0" + val;
			}
			bytes += val;
			bytes += " ";
		}
		return bytes;
	}

	public boolean hasEmbeddedOperand(String instr) {
		char ch = instr.charAt(instr.length() - 1);
		return (ch <= '9' && ch >= '0');
	}
	
	private Hashtable computeLabels(Vector program) {
		int count = 0;
		Hashtable table = new Hashtable();

		for (int i = 0; i < program.size(); i++) {
			int width = 1; 
			String line = (String)program.elementAt(i);
			Matcher match = regexp.matcher(line);
			if (!match.matches()) {
				System.out.println("Could not parse " + line);
			}
			String label = match.group(1);
			if (label == null) {label = "";}
			String opcode = match.group(2);
			String operand = match.group(3);
			//System.out.println(line + " -> " + label + " " + opcode + " " + operand);
			if (!label.equals("")) {
				label = label.trim();
				label = label.replace(':', ' ');
				label = label.trim();
				table.put(label, "" + count);
				System.out.println("Binding " + label + " to " + count);
			}

			char ch = opcode.charAt(0);
			if (ch >= '0' && ch <= '9') {
				width = (ch - '0'); 
			}

			count += width;
		}
		return table;
	}

	private Vector processLabels(Vector program, Hashtable labels) {
		Vector processedProgram = new Vector();
		for (int i = 0; i < program.size(); i++) {
			String line = (String)program.elementAt(i);
			Matcher match = regexp.matcher(line);
			if (!match.matches()) {
				System.out.println("Could not parse " + line);
			}
			String label = match.group(1);
			String opcode = match.group(2);
			String operand = match.group(3);
			if (operand == null) {operand = "";}
			else {
				//System.out.println("Operand: " + operand);
			}
			operand = operand.trim();
			if (labels.containsKey(operand)) {
				//System.out.println("Mapping " + operand + " to " + labels.get(operand));
				operand = (String)labels.get(operand);
			}
	
			String processed = opcode + " " + operand;
			processed = processed.trim();
			processedProgram.add(processed);
		}
		return processedProgram;
	}
	
	private void addByteCodes(Vector dest, String instruction) {
	//System.out.println("<" + instruction + ">");
	Matcher instrMatch = regexp.matcher(instruction);
	if (!instrMatch.matches()) {
		System.out.println("Could not parse " + instruction);
	}
	String opcode = instrMatch.group(2);
	String operand = instrMatch.group(3);
	Matcher opMatch = opcodePattern.matcher(opcode);
	if (!opMatch.matches()) {
		System.out.println("Could not parse " + opcode);
	}
		
	int width = 1;
	int embedded = 0;
	byte opcodeVal = mapper.nameToCode(opcode);
	long operandVal = 0;
	if (!opMatch.group(1).equals("")) {
		width = Integer.parseInt(opMatch.group(1));
	}
	if (!opMatch.group(3).equals("")) {
		embedded = Integer.parseInt(opMatch.group(3));
	}
	//System.out.println(opcode + " has width " + width);
	if (operand != null) {
		operand = operand.trim();
		operandVal = Long.parseLong(operand);
	}

	
	if (operandVal > (1 << embedded)) {
		System.out.println(opcode + " has " + width + " bits of operand, but " + operand + " was specified (too large).");
	}

	byte[] result = new byte[width];
	result[0] = opcodeVal;
	
	for (int i = width - 1; i >0 ; i--) {
		result[i] |= (byte)(operandVal & 0xff);
		operandVal = operandVal >> 8;
	}

	for (int i = 0; i < result.length; i++) {
		dest.addElement(new Byte(result[i]));
	}
	}
	
	public byte[] toByteCodes(AssemblyTokenizer tokenizer) throws IOException {
		Vector program = new Vector();
		//System.out.println("Adding instructions");
		while (tokenizer.hasMoreInstructions()) {
			String instr = tokenizer.nextLine();
			if (!instr.equals("")) {
				program.add(instr);
			}
		}
		//System.out.println("Computing labels.");
		Hashtable labels = computeLabels(program);
		//System.out.println("Processing labels.");
		Vector program2 = processLabels(program, labels);
		Vector bytecodes = new Vector();

		for (int i = 0; i < program2.size(); i++) {
			String instr = (String)program2.elementAt(i);
			addByteCodes(bytecodes, instr);
		}
		
		byte result[] = new byte[bytecodes.size()];
		for (int i = 0; i < bytecodes.size(); i++) {
			Byte code = (Byte)bytecodes.elementAt(i);
			result[i] = code.byteValue();
		}
		System.err.println();
		return result;
	}

	public static void main(String[] args) {
		try {
			ScriptAssembler assembler = new ScriptAssembler(new ConstantMapper("tConstants", "OP"));
			FileReader reader = new FileReader(args[0]);
			AssemblyTokenizer tokenizer = new AssemblyTokenizer(reader);
			String program = assembler.toHexString(tokenizer);
			System.out.println(program);
		}
		catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
