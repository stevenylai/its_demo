package pubsub.edl2.receiver.opcodes;

import pubsub.edl2.receiver.*;

public class OPhalt extends OPCodes{
	public void execute(EventReceiver vm) {
		vm.state=EventReceiver.MATE_STATE_STOPPPED;
	}
}
