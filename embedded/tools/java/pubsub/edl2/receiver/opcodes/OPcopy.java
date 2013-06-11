package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPcopy extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		printDebug("Copying "+num1.intValue());
		vm.opStack.push(num1);
		vm.opStack.push(new Integer(num1.intValue()));
	}
}
