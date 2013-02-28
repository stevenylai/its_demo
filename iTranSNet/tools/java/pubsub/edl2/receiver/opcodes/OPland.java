package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPland extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer num1 = vm.opStack.pop();
		Integer num2 = vm.opStack.pop();
		printDebug("Taking logical and of "+num2.intValue()+" and "+num1.intValue());
		vm.opStack.push(new Integer(num2.intValue()&num1.intValue()));
	}
}
