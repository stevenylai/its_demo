configuration CompilationTest {
} implementation {
	components Main,
		EventProcessorC,
		GenericComm as Comm;

	Main.StdControl -> EventProcessorC;
	Main.StdControl -> Comm;
}
