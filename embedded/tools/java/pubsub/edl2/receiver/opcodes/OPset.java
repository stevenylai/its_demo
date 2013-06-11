package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPset extends OPCodes {
	public void execute(EventReceiver vm) {
		Integer offset = vm.opStack.pop();
		Integer instanceID = vm.opStack.pop();
		Integer subID = vm.opStack.pop();
		Integer arg = vm.opStack.pop();

		EventInstanceProcessor processor = new EventInstanceProcessor(vm.instance);
		EventInstanceInfo e = processor.getEventInstance(subID.intValue(), instanceID.intValue());
		if (e==null) {
			vm.handleException();
		} else {
			e.data[offset.intValue()]=arg.intValue();
		}
	}
}
