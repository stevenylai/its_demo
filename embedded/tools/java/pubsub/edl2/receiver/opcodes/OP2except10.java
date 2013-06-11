package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

// May be replaced by 2pushc10???
public class OP2except10 extends OPCodes{
	public void execute(EventReceiver vm) {
		vm.exception = operand;
	}
}
