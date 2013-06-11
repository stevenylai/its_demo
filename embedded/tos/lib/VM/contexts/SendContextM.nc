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
 * History:   Apr 14, 2003         Inception.
 *
 */

/**
 * @author Philip Levis <pal@cs.berkeley.edu>
 * @author Neil Patel
 */


includes Mate;

module SendContextM {

  provides {
    interface MateBytecode as SendR;
    interface MateBytecode as SendRS;
    interface MateBytecode as SendBuf;
    event result_t sendDone();
    interface StdControl;
  }

  uses {
    interface MateQueue as Queue;
    interface MateContextSynch as Synch;
    interface MateError as Error;
    interface MateTypes as Types;
    interface MateStacks as Stacks;

    interface SendMsg as SendPacket;

    interface MateEngineControl as EngineControl;
    interface MateCapsuleStore as CapsuleStore;
    interface MateAnalysis as Analysis;
  }
}

implementation {
  MateQueue sendWaitQueue;
  MateContext* sendingContext = NULL;
  MateContext sendContext;
  MateDataBuffer sendrBuffer;
  TOS_Msg msg;

  command result_t StdControl.init() {
    result_t rval;
    sendContext.which = MATE_CONTEXT_SEND;
    sendContext.state = MATE_STATE_HALT;
    
    rval = call CapsuleStore.initializeCapsule();
    sendContext.rootCapsule = call CapsuleStore.getCapsule();
    sendContext.currentCapsule = sendContext.rootCapsule;

    call Queue.init(&sendWaitQueue);
    call Analysis.analyzeCapsuleVars(sendContext.rootCapsule);
    call EngineControl.registerCapsule(sendContext.rootCapsule);

    return rval;
  }

  command result_t StdControl.start() {
    return SUCCESS;
  }

  command result_t StdControl.stop() {
    return SUCCESS;
  }

  void alertSendContext(MateContext* caller,
                        MateStackVariable* arg) {
    if (sendContext.state == MATE_STATE_HALT) {
      nmemcpy(&sendrBuffer, arg->buffer.var, sizeof(MateDataBuffer));
      call Synch.initializeContext(&sendContext);
      call Synch.resumeContext(&sendContext, &sendContext);
      // This yield/resume allows locks to be yielded to the send context,
      // and if none are shared, then it will just continue executing
      if (caller->releaseSet) {
        call Synch.releaseLocks(caller, caller);
        call Synch.yieldContext(caller);
        call Synch.resumeContext(caller, caller);
      }
    }
    else {
      dbg(DBG_USR1, "VM: Send context not halted. Failing silently. \n");
      // Don't send, fail silently -- send context busy
    }
  }

  void executeSendr(MateContext* context, MateStackVariable* arg) { 
    if ((context->which != MATE_CONTEXT_SEND) || 
        (!call Types.checkTypes(context, arg, MATE_VAR_V))) {
      context->state = MATE_STATE_HALT;
      return;
    }
    else {
      uint16_t addr = arg->value.var;
      uint8_t size;
      arg = call Stacks.popOperand(context);
      if (!call Types.checkTypes(context, arg, MATE_VAR_B)) {return;}
      size = arg->buffer.var->size * sizeof(arg->buffer.var->entries[0]);
      size += sizeof(arg->buffer.var->type);
      size += sizeof(arg->buffer.var->size);
      nmemcpy(msg.data, arg->buffer.var, size);
      //nmemcpy(msg.data, context->header, MATE_HEADERSIZE);
      //if (state->sendingContext == NULL) { // do we assume Generic Commwill take care of this?
      if (call SendPacket.send(addr, size + MATE_HEADERSIZE, &msg)) {
        context->state = MATE_STATE_SENDING;
        sendingContext = context;
      }
      //}
      else {
        // Back up context so on being resumed it will try to send again
        context->pc--;
        call Stacks.pushOperand(context, arg);
        call Stacks.pushValue(context, addr);
        call Queue.enqueue(context, &sendWaitQueue, context);
        context->state = MATE_STATE_SEND_WAIT;
      }
    }
    call Synch.releaseLocks(context, context);
    call Synch.yieldContext(context);
    return;
  }

  command result_t SendR.execute(uint8_t instr, MateContext* context) {
    MateStackVariable* arg = call Stacks.popOperand(context);
    dbg(DBG_USR1, "VM (%i): Executing sendr.\n", (int)context->which);

    if (context->which == MATE_CONTEXT_SEND) {
      call Error.error(context, MATE_ERROR_INVALID_INSTRUCTION);
      return FAIL;
    }
    else if (!call Types.checkTypes(context, arg, MATE_VAR_B)) {
      return FAIL;
    }
    else {
      alertSendContext(context, arg);
    }

    return SUCCESS;
  }

  command result_t SendRS.execute(uint8_t instr, MateContext* context) {
    MateStackVariable* arg = call Stacks.popOperand(context);
    dbg(DBG_USR1, "VM (%i): Executing sendr2.\n", (int)context->which);

    if (context->which == MATE_CONTEXT_SEND)
      executeSendr(context, arg);
    else {
      call Error.error(context, MATE_ERROR_INVALID_INSTRUCTION);
      return FAIL;
    }
    return SUCCESS;
  }
    
  command result_t SendBuf.execute(uint8_t instr, MateContext* context) {
    dbg(DBG_USR1, "VM (%i): Executing sendbuf.\n", (int)context->which);

    if (context->which == MATE_CONTEXT_SEND) {
      return call Stacks.pushBuffer(context, &sendrBuffer);
    }
    else {
      call Error.error(context, MATE_ERROR_INVALID_INSTRUCTION);
      return FAIL;
    }
  }

  event result_t SendPacket.sendDone(TOS_MsgPtr mesg, result_t success) {
    MateContext* sender = sendingContext;

    if (sender == NULL) {
      return SUCCESS;
    }
    dbg(DBG_USR1, "VM: SendPacket.sendDone event fired in sendr op.\n");

    if (sender->state != MATE_STATE_SENDING) {
      call Error.error(sender, MATE_ERROR_QUEUE_INVALID);
      return FAIL;
    }

    sendingContext = NULL;
    call Synch.resumeContext(sender, sender);
    
    return SUCCESS;
  }
  
  event result_t sendDone() { // Generic sendDone
    MateContext* sender;
    //dbg(DBG_USR1, "VM: Send done event fired in sendr.\n");
    if (call Queue.empty(&sendWaitQueue)) {return FAIL;}
    sender = call Queue.dequeue(sendingContext, &sendWaitQueue);
    if (sender->state != MATE_STATE_SEND_WAIT) {
      call Error.error(sender, MATE_ERROR_QUEUE_INVALID);
    }
    call Synch.resumeContext(sender, sender);
    return SUCCESS;
  }

  event result_t Synch.makeRunnable(MateContext* context) {
    return SUCCESS;
  }
  
 
  event void CapsuleStore.capsuleChanged(MateCapsuleBuffer* buf) {
    dbg(DBG_TEMP, "OnceContext: Capsule changed.\n");
    sendContext.rootCapsule = buf;
    sendContext.currentCapsule = sendContext.rootCapsule;
    call Synch.initializeContext(&sendContext);
  }
  
}
