package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPCodes {
	public static boolean displayDebugMsg=false;
	public String operand;
	public String label;
	public void printDebug(String msg) {
		if (OPCodes.displayDebugMsg) {
			System.out.println("OPCodes: "+msg);
		}
	}
	public void execute(EventReceiver vm) {
		printDebug("Executing default instruction");
	}
	public void setOperand(String operand) {
		printDebug("Operand set as: "+operand);
		this.operand=operand;
	}
	public void setLabel(String label) {
		printDebug("Label set as: "+label);
		this.label=label;
	}
}
