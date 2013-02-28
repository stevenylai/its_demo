configuration MVirusDebugC {
  provides interface StdControl;
  provides interface MateVirus as Virus;
  uses {
    interface MateError;
    interface MateEngineControl as EngineControl;
    
    interface Timer as VersionTimer;
    interface ReceiveMsg as VersionReceive;
    interface SendMsg as VersionSend;

    interface Timer as CapsuleTimer;
    interface ReceiveMsg as CapsuleChunkReceive;
    interface Receive as CapsuleChunkRouteReceive;
    interface Intercept as CapsuleChunkRouteIntercept;
    
    interface SendMsg as CapsuleChunkSend;
    interface ReceiveMsg as CapsuleStatusReceive;
    interface SendMsg as CapsuleStatusSend;
    
    interface Random as Random;
    interface StdControl as SubControl;
  }
} implementation {
	components LedsC, GenericCommPromiscuous as Comm, MVirusDebugM;

	StdControl=MVirusDebugM.StdControl;
	Virus=MVirusDebugM.Virus;

	MateError=MVirusDebugM.MateError;
	EngineControl=MVirusDebugM.EngineControl;

	VersionTimer=MVirusDebugM.VersionTimer;
	VersionReceive=MVirusDebugM.VersionReceive;
	VersionSend=MVirusDebugM.VersionSend;

	CapsuleTimer=MVirusDebugM.CapsuleTimer;
	CapsuleChunkReceive=MVirusDebugM.CapsuleChunkReceive;
	CapsuleChunkRouteReceive=MVirusDebugM.CapsuleChunkRouteReceive;
	CapsuleChunkRouteIntercept=MVirusDebugM.CapsuleChunkRouteIntercept;

	CapsuleChunkSend=MVirusDebugM.CapsuleChunkSend;
	CapsuleStatusReceive=MVirusDebugM.CapsuleStatusReceive;
	CapsuleStatusSend=MVirusDebugM.CapsuleStatusSend;

	Random=MVirusDebugM.Random;
	SubControl=MVirusDebugM.SubControl;

	MVirusDebugM.Leds->LedsC;
	MVirusDebugM.SendDebug->Comm.SendMsg[17];
}
