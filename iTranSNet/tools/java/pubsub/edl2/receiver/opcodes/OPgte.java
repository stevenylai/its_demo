package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPgte extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		Integer num2 = vm.opStack.pop();
		printDebug("Comparing (gte) "+num2.intValue()+" and "+num1.intValue());
		if (num2.intValue()>=num1.intValue()) {
			vm.opStack.push(new Integer(1));
		} else {
			vm.opStack.push(new Integer(0));
		}
	}
}
