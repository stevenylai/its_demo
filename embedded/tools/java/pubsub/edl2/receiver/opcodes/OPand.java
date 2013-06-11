package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPand extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		Integer num2 = vm.opStack.pop();
		printDebug("Taking relational and of "+num2.intValue()+" and "+num1.intValue());
		if (num2.intValue()!=0 && num1.intValue()!=0) {
			vm.opStack.push(new Integer(1));
		} else {
			vm.opStack.push(new Integer(0));
		}

	}
}
