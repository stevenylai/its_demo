includes CommAck;

module vehicleACKM {
	uses {
		interface PacketReceiveControl as PacketControlRelay;
		interface PacketReceiveControl as PacketControlTraffic;
	}
} implementation {
	event bool PacketControlRelay.packetReceived (TOS_MsgPtr m, uint16_t sender) {
		return (m->addr==TOS_LOCAL_ADDRESS);
	}
	event uint16_t PacketControlRelay.generateSig (TOS_MsgPtr m, uint16_t receiver) {
		return TOS_LOCAL_ADDRESS;
	}

	event bool PacketControlTraffic.packetReceived (TOS_MsgPtr m, uint16_t sender) {
		return (m->addr==TOS_LOCAL_ADDRESS);
	}
	event uint16_t PacketControlTraffic.generateSig (TOS_MsgPtr m, uint16_t receiver) {
		return TOS_LOCAL_ADDRESS;
	}
}
