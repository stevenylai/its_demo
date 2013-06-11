package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OP2offset8 extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num = new Integer(operand);
		printDebug("Pushing offset "+num.intValue());
		vm.opStack.push(num);
	}
}
