includes CommAck;

module AckByIDM {
	uses {
		interface PacketReceiveControl;
	}
} implementation {
	event bool PacketReceiveControl.packetReceived (TOS_MsgPtr m, uint16_t sender) {
		return (m->addr==TOS_LOCAL_ADDRESS);
	}
	event uint16_t PacketReceiveControl.generateSig (TOS_MsgPtr msg, uint16_t receiver) {
		if (receiver==TOS_BCAST_ADDR || receiver==TOS_UART_ADDR)
			return INVALID_SIG;
		else
			return TOS_LOCAL_ADDRESS;
	}
}
