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
 * History:   Apr 14, 2003         Inception.
 *
 */

/**
 * @author Philip Levis <pal@cs.berkeley.edu>
 */


includes Mate;

module OPcall2M {
  provides {
    interface MateBytecode;
    interface StdControl;
  }
  uses {
    interface MateStacks as Stacks;
    interface MateVirus as Virus;
    interface MateAnalysis as Analysis;

    interface MateContextComm as Comm0;
    interface MateContextComm as Comm1;
    interface MateContextComm as Comm2;
    interface MateContextComm as Comm3;
  }
}

implementation {
  MateCapsuleBuffer subrs[4];
    
  command result_t StdControl.init() {
    int i;

    subrs[MATE_CAPSULE_SUB0].capsule.type = MATE_CAPSULE_SUB0;
    subrs[MATE_CAPSULE_SUB1].capsule.type = MATE_CAPSULE_SUB1;
    subrs[MATE_CAPSULE_SUB2].capsule.type = MATE_CAPSULE_SUB2;
    subrs[MATE_CAPSULE_SUB3].capsule.type = MATE_CAPSULE_SUB3;

    for (i = 0; i <= MATE_CAPSULE_SUB3; i++) {
      subrs[i].capsule.type |= MATE_OPTION_FORWARD;
      subrs[i].capsule.version = 0;
      call Virus.registerCapsule(subrs[i].capsule.type,
                                 &(subrs[i].capsule));
      call Analysis.analyzeCapsuleVars(&subrs[i]);
    }

    call Comm0.registerCapsule(&subrs[0]);
    call Comm1.registerCapsule(&subrs[1]);
    call Comm2.registerCapsule(&subrs[2]);
    call Comm3.registerCapsule(&subrs[3]);

    return SUCCESS;
  }

  command result_t StdControl.start() {
    return SUCCESS;
  }

  command result_t StdControl.stop() {
    return SUCCESS;
  }

  event result_t Comm0.analyzeLockSets(MateCapsuleBuffer* capsules[]) {
    call Analysis.analyzeCapsuleCalls(capsules);
    return SUCCESS;
  }

  event result_t Comm1.analyzeLockSets(MateCapsuleBuffer* capsules[]) {
    return SUCCESS;
  }

  event result_t Comm2.analyzeLockSets(MateCapsuleBuffer* capsules[]) {
    return SUCCESS;
  }

  event result_t Comm3.analyzeLockSets(MateCapsuleBuffer* capsules[]) {
    return SUCCESS;
  }

  command result_t MateBytecode.execute(uint8_t instr,
                                            MateContext* context) {
    dbg(DBG_USR1, "VM (%i): Calling subroutine %hhu\n", (int)context->which, (uint8_t)(instr & 0x3));
    call Stacks.pushReturnAddr(context);
    context->currentCapsule = &subrs[instr & 0x3];
    context->pc = 0;
    return SUCCESS;
  }

  event result_t Virus.capsuleInstalled(MateCapsule* capsule) {
    uint8_t id = capsule->type;
    if (id <= (MATE_CAPSULE_SUB3 | MATE_OPTION_FORWARD)) {
      dbg(DBG_USR1, "VM: Installing subroutine capsule %i\n", id);
      subrs[id & 0x3].capsule = *capsule;
      call Comm0.reboot();
    }
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
