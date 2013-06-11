/*									tab:4
 *
 *
 * "Copyright (c) 2000-2002 The Regents of the University  of California.  
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
 *  Copyright (c) 2002 Intel Corporation 
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

module OPsendM {

  provides {
    interface MateBytecode;
    interface StdControl;
    event result_t sendDone();
  }

  uses {
    interface MateQueue as Queue;
    interface MateContextSynch as Synch;
    interface MateError as Error;
    interface MateTypes as Types;
    interface MateStacks as Stacks;
    interface MateVirus as Virus;

    interface Send as SendAdHoc;
  }
}

implementation {
  MateQueue sendWaitQueue;
  MateContext* sendingContext = NULL;
  TOS_Msg msg[uniqueCount("MateContext")];
    
  command result_t StdControl.init() {
    call Queue.init(&sendWaitQueue);
    return SUCCESS;
  }
  
  command result_t StdControl.start() {
    return SUCCESS;
  }
  
  command result_t StdControl.stop() {
    return SUCCESS;
  }

  command result_t MateBytecode.execute(uint8_t instr,
                                            MateContext* context) {
    MateStackVariable* arg = call Stacks.popOperand(context);
    dbg(DBG_USR1, "VM (%i): Sending packet with built-in ad-hoc routing.\n", (int)context->which);
    if (!call Types.checkTypes(context, arg, MATE_VAR_B)) {return FAIL;}
    else {
      uint16_t maxLen;
      MateDataBuffer* buffer = arg->buffer.var;
      uint8_t len = buffer->size * sizeof(buffer->entries[0]);
      MateDataBuffer* destBuffer = call SendAdHoc.getBuffer(&msg[context->which], &maxLen);
      len += sizeof(buffer->type) + sizeof(buffer->size);

      if (len > maxLen) {
	call Error.error(context, MATE_ERROR_BUFFER_OVERFLOW);
	return FAIL;
      }
      
      nmemcpy(destBuffer , buffer, len);
      //      if (state->sendingContext == NULL) {
      if (call SendAdHoc.send(&msg[context->which], len))  {
        context->state = MATE_STATE_SENDING;
        sendingContext = context;
      }
      // }
      else {
        // Back up context so on being resumed it will try to send again
        context->pc--;
        call Stacks.pushOperand(context, arg);
        call Queue.enqueue(context, &sendWaitQueue, context);
        context->state = MATE_STATE_SEND_WAIT;
      }
      call Synch.releaseLocks(context, context);
      call Synch.yieldContext(context);
      return SUCCESS;
    }
  }
  
  event result_t SendAdHoc.sendDone(TOS_MsgPtr mesg, result_t success) {
    MateContext* sender = sendingContext;
 
    if (sender == NULL) {
      return SUCCESS;
    }
    dbg(DBG_USR1, "VM: Ad hoc send completed with code %i\n", (int)success);

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
    //dbg(DBG_USR1, "VM: Send done event fired in send.\n");
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
  
  event result_t Virus.capsuleInstalled(MateCapsule* capsule) {
    sendingContext = NULL;
    call Queue.init(&sendWaitQueue);
    return SUCCESS;
  }

  event result_t Virus.enableExecution() {
    return SUCCESS;
  }

  event result_t Virus.disableExecution() {
    return SUCCESS;
  }

  event result_t Virus.capsuleHeard(uint8_t type) {
    return SUCCESS;
  }

  event void Virus.capsuleForce(uint8_t type) {
    return;
  }
}
