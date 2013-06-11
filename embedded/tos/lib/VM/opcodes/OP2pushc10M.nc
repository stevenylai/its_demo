includes Mate;

module OP2pushc10M {
  provides interface MateBytecode;
  uses {
    interface MateStacks as Stacks;
    interface MateTypes as Types;
  }
} implementation {

  command result_t MateBytecode.execute(uint8_t instr,
					    MateContext* context) {
    //uint16_t arg1 = context->currentCapsule->capsule.code[context->pc++];
    //uint16_t arg2 = context->currentCapsule->capsule.code[context->pc];
    uint16_t arg1 = instr&0x03;
    uint16_t arg2 = context->currentCapsule->capsule.code[context->pc++];
    uint16_t real_arg=arg1<<8|arg2;

    dbg(DBG_USR1, "VM (%i): Pushing: %d to stack.\n", (int)context->which, (int)real_arg);

    call Stacks.pushValue(context, real_arg);
    return SUCCESS;
  }
	command uint8_t MateBytecode.byteLength() {return 2;}
}

