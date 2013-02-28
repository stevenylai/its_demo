/*									tab:4
 *
 *
 * "Copyright (c) 2000-2004 The Regents of the University  of California.  
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright
 * notice, the following two paragraphs and the author appear in all
 * copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY
 * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
 * DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS
 * DOCUMENTATION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND THE UNIVERSITY OF
 * CALIFORNIA HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
 * UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 */
/*									tab:4
 *									
 *  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
 *  By downloading, copying, installing or using the software you
 *  agree to this license.  If you do not agree to this license, do
 *  not download, install, copy or use the software.
 *
 *  Intel Open Source License 
 *
 *  Copyright (c) 2004 Intel Corporation 
 *  All rights reserved. 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 * 
 *	Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *	Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *      Neither the name of the Intel Corporation nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *  this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *  PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE INTEL OR ITS
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *                              
 */

/*
 * Authors:   Philip Levis <pal@cs.berkeley.edu>
 *            Neil Patel
 * History:   Apr 11, 2003         Inception.
 *
 */

/**
 * @author Philip Levis <pal@cs.berkeley.edu>
 * @author Neil Patel
 */


includes AM;
includes Mate;

module MateEngineM {
	provides {
		interface StdControl;
		interface MateError as Error;
		interface MateEngineControl as EngineControl[uint8_t bytecode];
	} uses {
		interface Leds;
		interface MateContextSynch as Synch;
		interface MateQueue as Queue;
		interface MateBytecode as Bytecode[uint8_t bytecode] ;
		interface StdControl as SubControl;
		interface MateAnalysis as Analysis;
		interface Timer as ErrorTimer;
		interface SendMsg as SendError;
	}
} implementation {
	MateQueue runQueue;
	MateCapsuleBuffer* capsules[MATE_CAPSULE_NUM];

	MateContext* errorContext;
	MateErrorMsg errorMsg;
	bool inErrorState;
	bool errorFlipFlop; 
	bool halted;
	
	TOS_Msg msg;

	command result_t StdControl.init() {
		dbg(DBG_BOOT, "VM: Mate initializing.\n");
		call Leds.init();
		call Queue.init(&runQueue);
		call SubControl.init();
		inErrorState = FALSE;
		halted = FALSE;
		return SUCCESS;
	}
	
	command result_t StdControl.start() {
		dbg(DBG_BOOT, "VM: Starting.\n");
		call SubControl.start();
		return SUCCESS;
	}

	command result_t StdControl.stop() {
		dbg(DBG_BOOT, "VM: Stopping.\n");
		call SubControl.stop();
		return SUCCESS;
	}

	result_t computeInstruction(MateContext* context) {
		uint8_t instr = context->currentCapsule->capsule.code[(int)context->pc];
		//dbg(DBG_USR2, "VM (%hhi): Issuing instruction 0x%hhx.\n", context->which, instr);
		if (context->state != MATE_STATE_RUN) {
			dbg(DBG_ERROR, "VM: (%hhi) Tried to execute instruction in non-run state: %hhi\n", context->which, context->state);
			return FAIL;
		}
		context->pc++;
		call Bytecode.execute[instr](instr, context);
		return SUCCESS;  
	}
	
	task void RunTask() {
		int i;
		// FIFO style policy
		if (!inErrorState) {
			MateContext* context = call Queue.dequeue(NULL, &runQueue);
			for (i=0; i < 4; i++) { // this is an arbitrary number of instructions
				//dbg(DBG_ERROR, "VM: (%hhi) PC: %hhi\n", context->which, context->pc);
				computeInstruction(context);
				if (context->state != MATE_STATE_RUN || context->queue == &runQueue) {
					return;
				}
			}
			//if (context->queue != &runQueue) {
			call Queue.enqueue(context, &runQueue, context);
			post RunTask();
			//}
		}
	}
	
	result_t executeContext(MateContext* context) {
		if (context->state != MATE_STATE_RUN) {return FAIL;}
		call Queue.enqueue(context, &runQueue, context);
		post RunTask();
		return SUCCESS;
	}

	default command result_t Bytecode.execute[uint8_t opcode](uint8_t instr, MateContext* context) {
		dbg(DBG_ERROR|DBG_USR1, "VM: Unknown instruction: %#x. Executing default instruction: halt!\n", instr);
		context->state = MATE_STATE_HALT;
		context->pc = 0;
		return FAIL;
	}

	command void EngineControl.registerCapsule[uint8_t type](MateCapsuleBuffer* capsule) {
		capsules[type] = capsule;
	}

	command void EngineControl.reboot[uint8_t type]() {
		int i;
		dbg(DBG_USR1, "VM: Mate rebooting.\n");
		call Synch.reset();
		call Queue.init(&runQueue);

		for (i = 0; i < uniqueCount("MateCapsuleConstant"); i++) {
			if (capsules[i] != NULL) {
				capsules[i]->haveSeen = 0;
			}
		}
		dbg(DBG_USR1, "VM: Analyzing lock sets.\n");
		for (i = 0; i < uniqueCount("MateCapsuleConstant"); i++) {
			if (capsules[i] != NULL) {
				call Analysis.analyzeCapsuleVars(capsules[i]);
			}
		}
		call Analysis.analyzeCapsuleCalls(capsules);
				       
		inErrorState = FALSE;
		errorContext = NULL;
		halted = FALSE;
	}

	command void EngineControl.halt[uint8_t type]() {
		halted = TRUE;
	}

	command void EngineControl.resume[uint8_t type]() {
		halted = FALSE;
	}
	
	event result_t Synch.makeRunnable(MateContext* context) {
		context->state = MATE_STATE_RUN;
		return executeContext(context);
	}

	command result_t Error.error(MateContext* context, uint8_t cause) {
		inErrorState = TRUE;
		dbg(DBG_ERROR|DBG_USR1, "VM: Entering ERROR state. Context: %i, cause %i\n", (int)context->which, (int)cause);
		call Leds.redOn();
		call Leds.greenOn();
		call Leds.yellowOn();
		call ErrorTimer.start(TIMER_REPEAT, 1000);
		errorContext = context;
		if (context != NULL) {
			errorContext = context;
			errorMsg.context = context->which;
			errorMsg.reason = cause;
			errorMsg.capsule = context->currentCapsule->capsule.type;
			errorMsg.instruction = context->pc - 1;
			context->state = MATE_STATE_HALT;
		}
		else {
			errorMsg.context = MATE_CAPSULE_INVALID;
			errorMsg.reason = cause;
			errorMsg.capsule = MATE_CAPSULE_INVALID;
			errorMsg.instruction = 255;
		}
		return SUCCESS;
	}

	event result_t ErrorTimer.fired() {
		dbg(DBG_USR1|DBG_ERROR, "VM: ERROR\n");
		if (!inErrorState) {
			call ErrorTimer.stop();
			return FAIL;
		}
		call Leds.redToggle();
		call Leds.greenToggle();
		call Leds.yellowToggle();
		nmemcpy(msg.data, &errorMsg, sizeof(MateErrorMsg));

		if (errorFlipFlop) {
			call SendError.send(TOS_UART_ADDR, sizeof(MateErrorMsg), (TOS_MsgPtr)&(msg));
		}
		else {
			call SendError.send(TOS_BCAST_ADDR, sizeof(MateErrorMsg), (TOS_MsgPtr)&(msg));
		}
		errorFlipFlop = !errorFlipFlop;
		return SUCCESS;
	}

	event result_t SendError.sendDone(TOS_MsgPtr mesg, result_t success) {
		return SUCCESS;
	}
}
