package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OP2ref8 extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer subID = new Integer(operand);
		EventInstanceInfo e = vm.matcher.findMatchInstance(subID);
		if (e==null) {
			vm.handleException();
		} else {
			vm.opStack.push(new Integer(e.meta.subID));
			vm.opStack.push(new Integer(e.instanceID));
		}
	}
}
