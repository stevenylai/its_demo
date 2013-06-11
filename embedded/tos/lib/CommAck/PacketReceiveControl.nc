interface PacketReceiveControl {
	// If the packet should be received but not ACK'd
	//event bool packetSnooped (TOS_MsgPtr m, uint16_t sender);
	// if the received packet should be returned to upper layer
	event bool packetReceived (TOS_MsgPtr m, uint16_t sender);
	// if ACK is needed for the msg to be sent out?
	// if so, return a 16-bit unique signiture for that packet
	event uint16_t generateSig(TOS_MsgPtr msg, uint16_t receiver);
}
