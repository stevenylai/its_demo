includes Mate;

configuration OPadd {
  provides interface MateBytecode;
}

implementation {
  components OPaddM, MStacksProxy;
  
  MateBytecode = OPaddM;

  OPaddM.Stacks -> MStacksProxy;
  OPaddM.Types -> MStacksProxy;
}
