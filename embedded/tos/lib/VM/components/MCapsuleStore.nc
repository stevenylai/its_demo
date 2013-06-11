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
 * History:   March 10, 2004   Creation
 *
 */

/**
 * @author Philip Levis
 */


includes Mate;

module MCapsuleStore {
  provides {
    interface StdControl;
    interface MateCapsuleStore as CapsuleStore[uint8_t id];
  }
  uses {
    interface StdControl as SubControl;
    interface MateVirus as Virus;
    interface MateAnalysis as Analysis;
    interface MateEngineControl as EngineControl;
    interface MateContextSynch as Synch;
  }
  
}

implementation {

  MateCapsuleBuffer capsules[MATE_CAPSULE_NUM];

  command result_t StdControl.init() {
		dbg(DBG_USR3, "CapsuleStore: Initializing ...\n");
    return call SubControl.init();
  }

  command result_t StdControl.start() {
    return call SubControl.start();
  }

  command result_t StdControl.stop() {
    return call SubControl.stop();
  }

  command MateCapsuleBuffer* CapsuleStore.getCapsule[uint8_t which]() {
    return &capsules[which];
  }

  command result_t CapsuleStore.initializeCapsule[uint8_t which]() {
      memset(&capsules[which], sizeof(MateCapsuleBuffer), 0);
      capsules[which].capsule.type = which;
      capsules[which].capsule.options = 0;
      capsules[which].capsule.version = 0;
      capsules[which].capsule.codeLen = 1;
      capsules[which].capsule.code[0] = OPhalt;
      call Virus.registerCapsule(which, &(capsules[which].capsule));
			dbg(DBG_USR3, "CapsuleStore: capsule registered for %d\n", which);
      return SUCCESS;
  }
  
  event result_t Virus.capsuleInstalled(MateCapsule* capsule) {
    uint8_t which = capsule->type & MATE_OPTION_MASK;
    nmemcpy(&capsules[which].capsule, capsule, sizeof(MateCapsule));
    call Analysis.analyzeCapsuleVars(&capsules[which]);
    call EngineControl.reboot();
    {
#ifdef PLATFORM_PC
      int i;
      dbg(DBG_USR3, "CapsuleStore: Installing capsule %i:\n\t", (int)which);
      for (i = 0; i < capsule->codeLen; i++) {
	dbg_clear(DBG_USR3, "[%hhx]", capsule->code[i]);
      }
      dbg_clear(DBG_USR3, "\n");
#endif
    }
		//dbg(DBG_USR3, "Signaling capsule changed\n");
    signal CapsuleStore.capsuleChanged[which](&capsules[which]);
    return SUCCESS;
  }

  default event void CapsuleStore.capsuleChanged[uint8_t which](MateCapsuleBuffer* buf) {
    dbg(DBG_USR1|DBG_ERROR, "CapsuleStore: Default capsule changed called for id %hhx: invalid capsule ID (no mask?)...\n", which);
  }
  
  event result_t Virus.capsuleHeard(uint8_t type) {
    return SUCCESS;
  }

  event result_t Virus.disableExecution() {
    return SUCCESS;
  }

  event result_t Virus.enableExecution() {
    return SUCCESS;
  }

  event result_t Synch.makeRunnable(MateContext* context) {
    return SUCCESS;
  }
  
  event void Virus.capsuleForce(uint8_t type) {}

  
}
