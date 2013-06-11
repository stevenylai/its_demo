includes Mate;

module OPaddM {
	provides interface MateBytecode;
	uses interface MateStacks as Stacks;
	uses interface MateTypes as Types;
}

implementation {

	command result_t MateBytecode.execute(uint8_t instr, MateContext* context) {
		MateStackVariable* arg1 = call Stacks.popOperand(context);
		MateStackVariable* arg2 = call Stacks.popOperand(context);
	 
		dbg(DBG_USR1, "VM (%i): Executing add.\n", (int)context->which);
		if (!call Types.checkTypes(context, arg1, MATE_VAR_V) ||
				!call Types.checkTypes(context, arg2, MATE_VAR_V)) {return FAIL;}
		call Stacks.pushValue(context, arg2->value.var + arg1->value.var);
		return SUCCESS;
	}
	command uint8_t MateBytecode.byteLength() {return 1;}
}
