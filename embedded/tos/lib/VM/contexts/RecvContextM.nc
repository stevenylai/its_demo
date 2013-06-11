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
 * Authors:   Neil Patel
 * History:   Apr 11, 2003         Inception.
 *
 */

/**
 * @author Neil Patel
 */


includes AM;
includes Mate;

module RecvContextM {
  provides interface StdControl;
  provides interface MateBytecode as ReceiveBuf;
  
  uses {
    interface ReceiveMsg as ReceivePacket;
    interface Receive as ReceiveAdHoc;
    interface MateStacks as Stacks;
    interface MateContextSynch as Synch;
    interface MateEngineControl as EngineControl;
    interface MateCapsuleStore as CapsuleStore;
    interface MateAnalysis as Analysis;
    interface MateError as Error;
  }
}

implementation {
  MateContext recvContext;
  MateDataBuffer recvBuffer;

  command result_t StdControl.init() {
    result_t rval;
    recvContext.which = MATE_CONTEXT_RECV;
    recvContext.state = MATE_STATE_HALT;

    rval = call CapsuleStore.initializeCapsule();
    recvContext.rootCapsule = call CapsuleStore.getCapsule();
    recvContext.currentCapsule = recvContext.rootCapsule;

    call Analysis.analyzeCapsuleVars(recvContext.rootCapsule);
    call EngineControl.registerCapsule(recvContext.rootCapsule);

    return rval;
  }

  command result_t StdControl.start() {
    return SUCCESS;
  }

  command result_t StdControl.stop() {
    return SUCCESS;
  }

  void alertReceiveContext(TOS_MsgPtr msg) {
    if (!msg->crc) {return;}
    if (recvContext.state != MATE_STATE_HALT) {
      dbg(DBG_USR1, "VM (%i): Received packet, receive context busy, drop.\n", recvContext.which);
    }
    else {
      MatePacket* packet = (MatePacket*)(msg->data);
      MateDataBuffer* buffer = (MateDataBuffer*)&(packet->payload);
      nmemcpy(&recvBuffer, buffer, sizeof(MateDataBuffer));
      call Synch.initializeContext(&recvContext);
      call Synch.resumeContext(&recvContext, &recvContext);
    }
  }

  event TOS_MsgPtr ReceivePacket.receive(TOS_MsgPtr msg) {
    alertReceiveContext(msg);
    return msg;
  }
  
  event TOS_MsgPtr ReceiveAdHoc.receive(TOS_MsgPtr msg, void* payload, uint16_t payloadLen) {
    alertReceiveContext(msg);
    return msg;
  }

  command result_t ReceiveBuf.execute(uint8_t instr, MateContext* context) {
    dbg(DBG_USR1, "VM (%i): Executing receivebuf.\n", (int)context->which);
    if (context->which == MATE_CONTEXT_RECV) {
      return call Stacks.pushBuffer(context, &recvBuffer);
    }
    else {
      call Error.error(context, MATE_ERROR_INVALID_INSTRUCTION);
      return FAIL;
    }
  }
  
  event result_t Synch.makeRunnable(MateContext* context) {
    return SUCCESS;
  }

  
  event void CapsuleStore.capsuleChanged(MateCapsuleBuffer* buf) {
    recvContext.rootCapsule = buf;
    recvContext.currentCapsule = recvContext.rootCapsule;
    call Synch.initializeContext(&recvContext);
  }

}
