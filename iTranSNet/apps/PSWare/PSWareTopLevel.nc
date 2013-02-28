includes Mate;
includes MateConstants;

configuration PSWareTopLevel {
} implementation {
	components GenericCommPromiscuous as Comm, TimerC, Main;
	components MsgBufferM, ArrayListM;
	components MateEngine as VM, EventProcessorC;
	components ITransNetDriverC as PSWareDriver;
	//components TimerContextImpC, SystemEventC as PSWareDriver;

	components	// Instructions
		OPhalt,
		OP2pushc10,
		OPadd,
		OPand,
		OPcopy,
		OPdiv,
		OPeq,
		OPgte,
		OPgt,
		OPinv,
		OPland,
		OPled,
		OPlnot,
		OPlor,
		OPlte,
		OPlt,
		OPlxor,
		OPmod,
		OPmul,
		OPneq,
		OPnot,
		OPor,
		OPpop,
		OPshiftl,
		OPshiftr,
		OPsub;

	Main.StdControl -> Comm;
	Main.StdControl -> TimerC;
	Main.StdControl -> ArrayListM;
	Main.StdControl -> MsgBufferM;
	Main.StdControl -> VM;
	Main.StdControl -> EventProcessorC;
	//Main.StdControl -> TimerContextImpC;
	Main.StdControl -> PSWareDriver;

	EventProcessorC.SystemClock -> PSWareDriver;
	EventProcessorC.SystemEvent -> PSWareDriver;

	VM.Bytecode[NOPhalt] -> OPhalt;
	VM.Bytecode[NOPadd] -> OPadd;
	VM.Bytecode[NOPand] -> OPand;
	VM.Bytecode[NOPcopy] -> OPcopy;
	VM.Bytecode[NOPdiv] -> OPdiv;
	VM.Bytecode[NOPeq] -> OPeq;
	VM.Bytecode[NOPgte] -> OPgte;
	VM.Bytecode[NOPgt] -> OPgt;
	VM.Bytecode[NOPinv] -> OPinv;
	VM.Bytecode[NOPland] -> OPland;
	VM.Bytecode[NOPled] -> OPled;
	VM.Bytecode[NOPlnot] -> OPlnot;
	VM.Bytecode[NOPlor] -> OPlor;
	VM.Bytecode[NOPlte] -> OPlte;
	VM.Bytecode[NOPlt] -> OPlt;
	VM.Bytecode[NOPlxor] -> OPlxor;
	VM.Bytecode[NOPmod] -> OPmod;
	VM.Bytecode[NOPmul] -> OPmul;
	VM.Bytecode[NOPneq] -> OPneq;
	VM.Bytecode[NOPnot] -> OPnot;
	VM.Bytecode[NOPor] -> OPor;
	VM.Bytecode[NOPpop] -> OPpop;
	VM.Bytecode[NOPshiftl] -> OPshiftl;
	VM.Bytecode[NOPshiftr] -> OPshiftr;
	VM.Bytecode[NOPsub] -> OPsub;

	VM.Bytecode[NOP2pushc10] -> OP2pushc10;
	VM.Bytecode[NOP2pushc10+1] -> OP2pushc10;
	VM.Bytecode[NOP2pushc10+2] -> OP2pushc10;
	VM.Bytecode[NOP2pushc10+3] -> OP2pushc10;

	VM.Bytecode[NOP2ref8] -> EventProcessorC.RefBytecode;
	VM.Bytecode[NOP2offset8] -> EventProcessorC.OffsetBytecode;
	VM.Bytecode[NOPset] -> EventProcessorC.SetBytecode;
	VM.Bytecode[NOPget] -> EventProcessorC.GetBytecode;
	VM.Bytecode[NOP2create8] -> EventProcessorC.CreateBytecode;
	VM.Bytecode[NOP2eval10] -> EventProcessorC.EvalBytecode;
	VM.Bytecode[NOP2eval10+1] -> EventProcessorC.EvalBytecode;
	VM.Bytecode[NOP2eval10+2] -> EventProcessorC.EvalBytecode;
	VM.Bytecode[NOP2eval10+3] -> EventProcessorC.EvalBytecode;
	VM.Bytecode[NOPhousekeep] -> EventProcessorC.HousekeepBytecode;
	VM.Bytecode[NOP2except10] -> EventProcessorC.ExceptBytecode;
	VM.Bytecode[NOP2except10+1] -> EventProcessorC.ExceptBytecode;
	VM.Bytecode[NOP2except10+2] -> EventProcessorC.ExceptBytecode;
	VM.Bytecode[NOP2except10+3] -> EventProcessorC.ExceptBytecode;
}
