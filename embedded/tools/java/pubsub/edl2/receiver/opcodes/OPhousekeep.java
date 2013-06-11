package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPhousekeep extends OPCodes{
	public void execute(EventReceiver vm) {
		vm.matcher.gc();
	}
}
