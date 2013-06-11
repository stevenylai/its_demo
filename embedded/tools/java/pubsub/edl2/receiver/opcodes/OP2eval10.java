package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OP2eval10 extends OPCodes{
	public void execute(EventReceiver vm) {
		Integer arg = vm.opStack.pop();
		Integer instanceID = vm.opStack.pop();
		Integer subID = vm.opStack.pop();

		if (arg.intValue()!=0) {
			vm.matcher.eventDetectionResult(subID.intValue(), instanceID.intValue(), true);
		} else {
			vm.matcher.eventDetectionResult(subID.intValue(), instanceID.intValue(), false);
		}

		if (vm.matcher.moreEventMatch()) {
			LabelFinder finder = new LabelFinder(label, vm.codes);
			vm.pc = finder.getIdx();
		}
	}
}
