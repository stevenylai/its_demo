package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPpop extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		printDebug("Popping "+num1.intValue());
	}
}
