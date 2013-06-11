package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPnot extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		printDebug("Taking relational not of "+num1.intValue());
		if (num1.intValue()==0)
			vm.opStack.push(new Integer(1));
		else
			vm.opStack.push(new Integer(0));
	}
}
