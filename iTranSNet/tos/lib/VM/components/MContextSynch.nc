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
	* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
	* AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
	* ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
	* PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
	*
	*/
/*									tab:4
	*  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.  By
	*  downloading, copying, installing or using the software you agree to
	*  this license.  If you do not agree to this license, do not download,
	*  install, copy or use the software.
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
	* Authors:   Philip Levis
	* History:   July 19, 2004 Inception
	*	      Jan 5, 2004   Implemented scalable (unique()) locks.
	*
	*/

/**
	* @author Philip Levis
	*/


includes Mate;

module MContextSynch {
	provides {
		interface MateContextSynch as Synch;
		interface MateAnalysis as Analysis;
		interface StdControl;
	} uses {
		interface MateError;
		interface MateLocks as Locks;
		interface MateQueue as Queue; 
		interface MateStacks as Stacks;
		interface MateBytecodeLock as CodeLocks[uint8_t param];
	}
} implementation {
	MateQueue readyQueue;

	command result_t StdControl.init() {
		call Queue.init(&readyQueue);
		return SUCCESS;
	}
	
	command result_t StdControl.start() {
		return SUCCESS;
	}
	
	command result_t StdControl.stop() {
		return SUCCESS;
	}

	command void Synch.reset() {
		call Queue.init(&readyQueue);
		call Locks.reset();
	}
	
	command bool Synch.isRunnable(MateContext* context) { 
		int8_t i;
		uint8_t* neededLocks = (context->acquireSet);
		dbg(DBG_USR2, "VM: Checking whether context %i runnable: ", (int)context->which);
		
		for (i = 0; i < MATE_HEAPSIZE; i++) {
			dbg_clear(DBG_USR2, "%i,", (int)i); 
			if ((neededLocks[i / 8]) & (1 << (i % 8))) {
				if (call Locks.isLocked(i)) {
					dbg_clear(DBG_USR2, " - no\n");
					return FALSE;
				}
			}
		}
		dbg_clear(DBG_USR2, " - yes\n");
		return TRUE;
	}

	command result_t Synch.obtainLocks(MateContext* caller, MateContext* obtainer) { 
		int8_t i;
		uint8_t* neededLocks = (obtainer->acquireSet);
		//dbg(DBG_USR2, "VM: Attempting to obtain necessary locks for context %i: ", obtainer->which);
		for (i = 0; i < MATE_HEAPSIZE; i++) {
			//dbg_clear(DBG_USR2, "%i", (int)i);
			if ((neededLocks[i / 8]) & (1 << (i % 8))) {
				//dbg_clear(DBG_USR2, "+"); 
				call Locks.lock(obtainer, i);
			}
			//dbg_clear(DBG_USR2, ","); 
		}
		for (i = 0; i < (MATE_HEAPSIZE + 7) / 8; i++) {
			obtainer->acquireSet[i] = 0;
		}
		//dbg_clear(DBG_USR2, "\n");
		return SUCCESS;		
	}

	command result_t Synch.releaseLocks(MateContext* caller, MateContext* releaser) {
		int8_t i;
		uint8_t* lockSet = (releaser->releaseSet);
		//dbg(DBG_USR2, "VM: Attempting to release specified locks for context %i.\n", releaser->which);
		for (i = 0; i < MATE_HEAPSIZE; i++) {
			if ((lockSet[i / 8]) & (1 << (i % 8))) {
				call Locks.unlock(releaser, i);
			}
		}
		for (i = 0; i < (MATE_HEAPSIZE + 7) / 8; i++) {
			releaser->releaseSet[i] = 0;
		}
		return SUCCESS;		
	}

	command result_t Synch.releaseAllLocks(MateContext* caller, MateContext* releaser) {
		int8_t i;
		uint8_t* lockSet = (releaser->heldSet);
		dbg(DBG_USR2, "VM: Attempting to release all locks for context %i.\n", releaser->which);
		for (i = 0; i < MATE_HEAPSIZE; i++) {
			if ((lockSet[i / 8]) & (1 << (i % 8))) {
				call Locks.unlock(releaser, i);
			}
		}
		for (i = 0; i < (MATE_HEAPSIZE + 7) / 8; i++) {
			releaser->releaseSet[i] = 0;
		}
		return SUCCESS;
	}

	command void Analysis.analyzeCapsuleVars(MateCapsuleBuffer* buf) {
		int i;
		dbg(DBG_USR2, "VM: Analyzing capsule vars for capsule %i: ", (int)(buf->capsule.type & MATE_OPTION_MASK));
		for (i = 0; i < (MATE_HEAPSIZE + 7) / 8; i++) {
			buf->usedVars[i] = 0;
		}

		for (i = 0; i < MATE_PGMSIZE; i++) {
			uint8_t instr = buf->capsule.code[i];
			int16_t lock = call CodeLocks.lockNum[instr](instr);
			if (lock >= 0) {
				dbg_clear(DBG_USR2, "%i,", (int)lock);
				buf->usedVars[lock / 8] |= (1 << (lock % 8)); 
			}
		}
		dbg_clear(DBG_USR2, "\n");
		buf->haveSeen = 1;
	}

	void capsuleCallsDeep(MateCapsuleBuffer* capsules[], int which) {
		int i;
		MateCapsuleBuffer* buf = capsules[which];
		if (buf->haveSeen) {
			return;
		}
		buf->haveSeen = 1;
		for (i = 0; i < MATE_PGMSIZE; i++) {
			/*if ((buf->capsule.code[i] & 0xfc) == OPcall2) {
				uint8_t arg = (buf->capsule.code[i]) & 0x3;
				buf->usedVars |= capsuleCallsDeep(capsules, arg);
			}*/
		}
		return;
	}

	command void Analysis.analyzeCapsuleCalls(MateCapsuleBuffer* capsules[]) {
		int i;
		int numCapsules = uniqueCount("MateCapsuleConstant");

		for (i = 0; i < numCapsules; i++) {
			if (capsules[i] != NULL) {
			 capsuleCallsDeep(capsules, i);
			}
		}
	}
	
	command void Synch.initializeContext(MateContext* context) {
		int i;
		for (i = 0; i < (MATE_HEAPSIZE + 7) / 8; i++) {
			context->heldSet[i] = 0;
			context->releaseSet[i] = 0;
		}
		context->currentCapsule = context->rootCapsule;
		nmemcpy(context->acquireSet, context->currentCapsule->usedVars, (MATE_HEAPSIZE + 7) / 8);
		context->pc = 0;
		call Stacks.resetStacks(context);
		context->queue = 0;
		context->state = MATE_STATE_HALT;
	}

	command void Synch.yieldContext(MateContext* context) {
		MateContext* start = NULL;
		MateContext* current = NULL;
		//dbg(DBG_USR2, "VM (%i): Yielding.\n", (int)context->which);
		if (!call Queue.empty(&readyQueue)) {
			do {
			 current = call Queue.dequeue(context, &readyQueue);
			 if (!call Synch.resumeContext(context, current)) {
				 dbg(DBG_USR2, "VM (%i): Context %i not runnable.\n", (int)context->which, (int)current->which);
				 if (start == NULL) {
				   start = current;
				 }
				 else if (start == current) {
				   dbg(DBG_USR2, "VM (%i): Looped on ready queue. End checks.\n", (int)context->which);
				   break;
				 }
			 }
			}
			while (!call Queue.empty(&readyQueue));
		}
		else {
			//dbg(DBG_USR2, "VM (%i): Ready queue empty.\n", (int)context->which);
		}
	}
	
	/* New simple (and dirty) scheduling algorithm */
	MateContext * currentContext=NULL;
	
	bool readyToRun(MateContext* context) {
		// No running context
		
		if (currentContext==NULL||currentContext->state!=MATE_STATE_RUN) {
			dbg(DBG_USR1, "VM (%i): No running context, switching to %i\n", (int)context->which, (int)context->which);
			currentContext=context;
			return TRUE;
		} else if (currentContext->which!=context->which) {
			dbg(DBG_USR1, "VM (%i): Context %i is running, switching to %i\n", (int)context->which, (int)currentContext->which, (int)context->which);
			call Synch.haltContext(currentContext);
			currentContext=context;
			return TRUE;
		} else {
			dbg(DBG_USR1, "VM (%i): Context %i is running, cannot preempt\n", (int)context->which, (int)currentContext->which, (int)context->which);
			return FALSE;
		}
	}
	command bool Synch.resumeContext(MateContext* caller, MateContext* context) {
		if (readyToRun(context)) {
			context->state = MATE_STATE_RESUMING;
			call Synch.obtainLocks(caller, context);
			signal Synch.makeRunnable(context);
			//dbg(DBG_USR2, "VM (%i): Resumption of %i successful.\n", (int)caller->which, (int)context->which);
			return TRUE;
		} else
			return FALSE;
	}
	/*
	command bool Synch.resumeContext(MateContext* caller, MateContext* context) {
		context->state = MATE_STATE_RESUMING;
		if (call Synch.isRunnable(context)) {
			call Synch.obtainLocks(caller, context);
			signal Synch.makeRunnable(context);
			dbg(DBG_USR2, "VM (%i): Resumption of %i successful.\n", (int)caller->which, (int)context->which);
			return TRUE;
		}
		else {
			dbg(DBG_USR2, "VM (%i): Resumption of %i unsuccessful, putting on the queue.\n", (int)caller->which, (int)context->which);
			call Queue.enqueue(caller, &readyQueue, context);
			return FALSE;
		}
	}*/

	command void Synch.haltContext(MateContext* context) {
		call Synch.releaseAllLocks(context, context);
		call Synch.yieldContext(context);
		context->state = MATE_STATE_HALT;
		// !!! Need something better here... it should
		// dequeue a waiting context from any waiting situation
		/*
		if ((context->which == MATE_CAPSULE_SEND_INDEX) && !call Queue.empty(&state->sendrWaitQueue)) {
			MateContext* waiter = call Queue.dequeue(context, &state->sendrWaitQueue);
			call Synch.resumeContext(context, waiter, &(state->readyQueue), state->locks);
		}*/
	}

	default command int16_t CodeLocks.lockNum[uint8_t ival](uint8_t instr) {
		return -1;
	}
}    

