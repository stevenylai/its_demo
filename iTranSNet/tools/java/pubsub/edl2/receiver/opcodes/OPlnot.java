package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPlnot extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		printDebug("Taking logical not of "+num1.intValue());
		vm.opStack.push(new Integer(~num1.intValue()));
	}
}
