configuration EventMetaTestC {
} implementation {
	components Main,
		EventMetaC,
		EventMetaTestM,
		ArrayListM,
		MsgBufferM,
		GenericComm as Comm;

	Main.StdControl -> EventMetaC;
	Main.StdControl -> EventMetaTestM;
	Main.StdControl -> Comm;
	Main.StdControl -> ArrayListM;
	Main.StdControl -> MsgBufferM;

	EventMetaTestM.EventMeta->EventMetaC.EventMeta;
}
