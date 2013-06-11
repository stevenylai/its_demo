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
 * History:   March 10, 2004   Extended version (includes routing).
 *	     
 *
 */

/**
 * @author Philip Levis
 */


includes Mate;

module MVirusExtended {
  provides interface StdControl;
  provides interface MateVirus as Virus;
  uses {
    interface MateError;

    interface Timer as VersionTimer;
    interface ReceiveMsg as VersionReceive;
    interface SendMsg as VersionSend;

    interface Timer as CapsuleTimer;
    interface ReceiveMsg as CapsuleReceive;
    interface SendMsg as CapsuleSend;
    
    interface Random as Random;
    interface StdControl as SubControl;

    interface Receive as ReceiveRouted;
    interface Intercept as InterceptRouted;

    interface Timer as BCastTimer;
    interface ReceiveMsg as BCastReceive;
    interface SendMsg as BCastSend;
  }
}


implementation {

  typedef enum {
    BVIRUS_TIMER_VERSION = 100,
    BVIRUS_TIMER_CAPSULE = 1000,
    BVIRUS_CAPSULE_INIT = 1,
    BVIRUS_CAPSULE_MAX = 16,
    BVIRUS_VERSION_THRESHOLD_INIT = 1,
    BVIRUS_VERSION_THRESHOLD_MAX = 300,
    TAU_INIT = 10,
    TAU_MAX = 600,
    BVIRUS_VERSION_HEARD_THRESHOLD = 1
  } MVirusConstants;

  typedef enum {
    BVIRUS_IDLE,
    BVIRUS_PULLING,
    BVIRUS_PUSHING
  } MVirusState;

  MateCapsule* capsules[MATE_CAPSULE_NUM];
  uint8_t capsuleTimerThresholds[MATE_CAPSULE_NUM];
  uint8_t capsuleHeard[MATE_CAPSULE_NUM];
  uint8_t capsuleTimerCounters[MATE_CAPSULE_NUM];
  uint8_t bCastIdx;
  
  uint16_t versionCounter;
  uint16_t versionThreshold;
  uint16_t versionCancelled;
  uint16_t tau;
  uint16_t versionHeard;
  
  
  MVirusState state;
  bool sendBusy;
  bool capsuleBusy;
  bool amBCasting;
  
  TOS_Msg sendMessage;
  TOS_MsgPtr sendPtr;
  TOS_Msg receiveMsg;
  TOS_MsgPtr receivePtr;

  void cancelVersionCounter() {
    versionCancelled = 1;
  }

  void newVersionCounter() {
    versionThreshold = (tau/2) + (((uint16_t)call Random.rand()) % (tau/2));
    //printf("%i: MVirus: resetting t to %i (%i)\n", (int)TOS_LOCAL_ADDRESS, (int)versionThreshold, (int)tau);
    versionHeard = 0;
    versionCounter = 0;
    versionCancelled = 0;
  }
  
  uint8_t typeToIndex(uint8_t type) {
    type &= MATE_OPTION_MASK;
    if (type <= MATE_CAPSULE_NUM) {
      return type;
    }
    else {
      return MATE_CAPSULE_INVALID;
    }
  }
  
  command result_t StdControl.init() {
    int i;
    call SubControl.init();
    call Random.init();
    
    for (i = 0; i < MATE_CAPSULE_NUM; i++) {
      capsuleTimerCounters[i] = 0;
      capsuleTimerThresholds[i] = BVIRUS_CAPSULE_MAX + 1;
      capsules[i] = NULL;
    }
    state = BVIRUS_IDLE;
    tau = TAU_MAX;
    
    sendPtr = (TOS_MsgPtr)&sendMessage;
    receivePtr = (TOS_MsgPtr)&receiveMsg;
    newVersionCounter();
    dbg(DBG_USR3, "MVirus initialized.\n");
    sendBusy = FALSE;
    capsuleBusy = FALSE;
    
    return SUCCESS;
  }

  command result_t StdControl.start() {
    call SubControl.start();
    state = BVIRUS_PULLING;
    dbg(DBG_USR3, "MVirus started.\n");
    call VersionTimer.start(TIMER_REPEAT, BVIRUS_TIMER_VERSION);
    dbg(DBG_USR3, "MVirus version timer started.\n");
    return SUCCESS;
  }

  command result_t StdControl.stop() {
    call VersionTimer.stop();
    call CapsuleTimer.stop();
    dbg(DBG_USR3, "MVirus stopped.\n");
    return call SubControl.stop();
  }


  command result_t Virus.registerCapsule(uint8_t type, MateCapsule* capsule) {
    uint8_t idx = typeToIndex(type);
    if (idx >= MATE_CAPSULE_NUM) {
      return FAIL;
    }
    capsules[idx] = capsule;
    
    return SUCCESS;
  }

  result_t receiveCapsule(MateCapsule* capsule, uint16_t payloadLen, char* type, int backoff) {
    uint8_t idx = typeToIndex(capsule->type);
    if ((capsules[idx] != NULL) &&
	(capsule->version > capsules[idx]->version)) {
      int len = (payloadLen < sizeof(MateCapsule))? payloadLen : sizeof(MateCapsule);
#ifdef PLATFORM_PC
      {
	char timeVal[128];
	printTime(timeVal, 128);
	dbg(DBG_USR3|DBG_TEMP,"MVirus: Received and installing %s capsule %i, version %i @ %s\n", type, (int)capsule->type, (int)capsule->version, timeVal);
      }
#endif
      if (capsule->type & MATE_OPTION_FORCE) {
	signal Virus.capsuleForce(capsule->type & MATE_OPTION_MASK);
	nmemcpy(capsules[idx], capsule, len);
	signal Virus.capsuleInstalled(capsules[idx]);
	dbg(DBG_USR3, "MVirus: installed a routed forced capsule: %i\n", (int)idx);
	tau = TAU_INIT * backoff;
	newVersionCounter();
	tau = TAU_INIT;
	return SUCCESS;
      }
      else if (signal Virus.capsuleHeard(capsule->type) == SUCCESS) {
	nmemcpy(capsules[idx], capsule, len);
	signal Virus.capsuleInstalled(capsules[idx]);
	dbg(DBG_USR3, "MVirus: installed a routed capsule\n");
	tau = TAU_INIT * backoff;
	newVersionCounter();
	tau = TAU_INIT;
	return SUCCESS;
      }
      else {
	dbg(DBG_USR3, "MVirus: routed capsule installation rejected\n");
	
      }
    }
    else {
     dbg(DBG_USR3, "%i: MVirus: Received capsule %i (idx %i), version %i, no such capsule or already have it.\n", (int)capsule->type, (int)idx, (int)capsule->version);
    }
    return FAIL;
  }
  
  result_t sendCapsule(uint8_t idx) {
    MateCapsule* capsule = capsules[idx];
    MateCapsuleMsg* msg = (MateCapsuleMsg*)sendPtr->data;
    if (sendBusy) {return FAIL;}
    else {
      // Fill in random bits to packet
      sendBusy = TRUE;
      // Fill in capsule
      nmemcpy(&msg->capsule, capsule, sizeof(MateCapsule));
      
      if (!call CapsuleSend.send(TOS_BCAST_ADDR, sizeof(MateCapsuleMsg), sendPtr)) {
	sendBusy = FALSE;
	return FAIL;
      }
      else {
#ifdef PLATFORM_PC
	char timeVal[128];
	printTime(timeVal, 128);
	dbg(DBG_USR3, "Sending capsule %i @ %s\n", (int)idx, timeVal);
#endif	    
	return SUCCESS;
      }
    }
  }

  result_t sendBCastCapsule(uint8_t idx) {
    MateCapsule* capsule = capsules[idx];
    MateCapsuleMsg* msg = (MateCapsuleMsg*)sendPtr->data;
    if (sendBusy) {return FAIL;}
    else {
      // Fill in random bits to packet
      sendBusy = TRUE;
      // Fill in capsule
      nmemcpy(&msg->capsule, capsule, sizeof(MateCapsule));
      
      if (!call BCastSend.send(TOS_BCAST_ADDR, sizeof(MateCapsuleMsg), sendPtr)) {
	sendBusy = FALSE;
	return FAIL;
      }
      else {
#ifdef PLATFORM_PC
	char timeVal[128];
	printTime(timeVal, 128);
	printf("%i: Broadcasting capsule %i @ %s\n", (int)TOS_LOCAL_ADDRESS, (int)idx, timeVal);
#else
	dbg(DBG_USR3, "Sending capsule %i\n", (int)idx);
#endif	    
	return SUCCESS;
      }
    }
  }
  
  result_t sendVersionPacket() {
    int i;
    MateVersionMsg* msg = (MateVersionMsg*)sendPtr->data;
    dbg(DBG_USR3, "Sending version vector packet:\n  ");
    if (sendBusy) {return FAIL;}
    sendBusy = TRUE;

    msg->type = MATE_VERSION_VECTOR;
    for (i = 0; i < MATE_CAPSULE_NUM; i++) {
      if (capsules[i] != NULL &&
	  (capsules[i]->type & MATE_OPTION_FORWARD)) {
	msg->versions[i] = capsules[i]->version;
      }
      else {
	msg->versions[i] = 0;
      }
      dbg_clear(DBG_USR3, "%08x ", msg->versions[i]);
    }
    dbg_clear(DBG_USR3, "\n");
    if (!call VersionSend.send(TOS_BCAST_ADDR, sizeof(MateVersionMsg), sendPtr)) {
      dbg(DBG_USR3|DBG_ERROR, "MVirus: Version vector send failed\n");
      sendBusy = FALSE;
      return FAIL;
    }
    else {
      return SUCCESS;
    }
  }

  task void versionTimerTask() {
    versionCounter++;
    if (versionCounter >= tau) {
      tau *= 2;
      if (tau > TAU_MAX) {
	tau = TAU_MAX;
      }
      newVersionCounter();
    }
    else if (versionCounter == versionThreshold) {
#ifdef PLATFORM_PC
      char timeBuf[128];
      printTime(timeBuf, 128);
      dbg(DBG_USR3, "MVirus: Version timer counter expired (hrd: %i, thr: %i, cancel: %i): %s\n",(int)versionHeard, (int)versionThreshold, (int)versionCancelled, timeBuf);
#endif
      if (!versionCancelled) {
	dbg(DBG_USR3, "MVirus: Sending version packet\n");
	sendVersionPacket();
	versionCancelled = 1;
      }
    }
    else {
      // do nothing
    }
  }

  event result_t VersionTimer.fired() {
    if (state == BVIRUS_PULLING) {
      post versionTimerTask();
    }
    return SUCCESS;
  }

  TOS_MsgPtr receiveProgram(TOS_MsgPtr msg) {
    dbg(DBG_USR3, "MVirus: Received program vector.\n");
    return msg;
  }
  
  TOS_MsgPtr receiveVector(TOS_MsgPtr msg) {
    uint8_t i;
    bool same = TRUE; // Is this vector the same as mine?
    MateVersionMsg* versions = (MateVersionMsg*)msg->data;
    //dbg(DBG_USR3, "MVirus: Received version vector.\n");
    
    for (i = 0; i < MATE_CAPSULE_NUM; i++) {
      if (capsules[i] != NULL) {
	if(versions->versions[i] > capsules[i]->version) {
	  // I have something older, send my version vector
	  // ASAP so he'll send capsules
	  dbg(DBG_USR3, "MVirus: heard newer version vector\n");
	  tau = TAU_INIT;
	  newVersionCounter();
	  same = FALSE;
	  break;
	}
	else if (versions->versions[i] < capsules[i]->version) {
	  // I have something newer, mark capsule to send
	  // if not already doing so.
	  dbg(DBG_USR3, "MVirus: heard older version vector, send out capsule.\n");
	  capsuleTimerThresholds[i] = BVIRUS_CAPSULE_INIT;
	  capsuleTimerCounters[i] = 0;
	  if (state != BVIRUS_PUSHING) {
	    call CapsuleTimer.start(TIMER_REPEAT, BVIRUS_TIMER_CAPSULE);
	    state = BVIRUS_PUSHING;
	  }
	  same = FALSE;
	  break;
	}
      }
    }
    if (same == TRUE) {
      dbg(DBG_USR3, "MVirus: Heard same version vector as mine.\n");
      versionHeard++;
      if (versionHeard >= BVIRUS_VERSION_HEARD_THRESHOLD) {
	cancelVersionCounter();
      }
    }
    return msg;
  }

  event TOS_MsgPtr VersionReceive.receive(TOS_MsgPtr msg) {
    MateVersionMsg* versions = (MateVersionMsg*)msg->data;
    dbg(DBG_USR3, "Received version packet, type %i\n", versions->type);
    if (versions->type == MATE_VERSION_VECTOR) {
      return receiveVector(msg);
    }
    else if (versions->type == MATE_VERSION_PROGRAM) {
      return receiveProgram(msg);
    }
    else {
      return msg;
    }
  }

  // Increment all of the timers. Try to send (only) the first capsule
  // with an expired timer. If the send request succeeds, decay the
  // timer.
  task void capsuleTimerTask() {
    uint8_t i;
    bool halt = TRUE;
    dbg(DBG_USR3, "MVirus: Capsule task running.\n");
    for (i = 0; i < MATE_CAPSULE_NUM; i++) {
      capsuleTimerCounters[i]++;
    }
    for (i = 0; i < MATE_CAPSULE_NUM; i++) {
      if (capsuleTimerThresholds[i] <= BVIRUS_CAPSULE_MAX) {
	halt = FALSE;
	if (capsuleTimerCounters[i] >= capsuleTimerThresholds[i]) {
	  if (sendCapsule(i)) {
	    capsuleTimerThresholds[i] <<= 2;
	    capsuleTimerCounters[i] = 0;
	  }
	  break;
	}
      }
    }
    if (halt) {
      call CapsuleTimer.stop();
      state = BVIRUS_PULLING;
    }
    return;
  }
  
  event result_t CapsuleTimer.fired() {
    post capsuleTimerTask();
    return SUCCESS;
  }

  event result_t InterceptRouted.intercept(TOS_MsgPtr msg,
					   void* payload,
					   uint16_t payloadLen) {
    MateCapsuleMsg* cMsg = (MateCapsuleMsg*)payload;
    MateCapsule* capsule = &(cMsg->capsule);
    if (msg->type != 66) {return FAIL;}
    //dbg(DBG_TEMP, "Received intercepted capsule.\n");
    receiveCapsule(capsule, payloadLen, "intercepted", 3);
    return SUCCESS;
  }
  
  event TOS_MsgPtr ReceiveRouted.receive(TOS_MsgPtr msg,
					 void* payload,
					 uint16_t payloadLen) {
    MateCapsuleMsg* cMsg = (MateCapsuleMsg*)payload;
    MateCapsule* capsule = &(cMsg->capsule);
    //dbg(DBG_TEMP, "Received routed capsule.\n");
    receiveCapsule(capsule, payloadLen, "routed", 1);
    return msg;
  }
  
  event TOS_MsgPtr CapsuleReceive.receive(TOS_MsgPtr msg) {
    MateCapsuleMsg* cMsg = (MateCapsuleMsg*)msg->data;
    MateCapsule* capsule = &(cMsg->capsule);
    //dbg(DBG_TEMP, "Received normal capsule.\n");
    receiveCapsule(capsule, sizeof(MateCapsule), "trickle", 1);
    return msg;
  }

  event TOS_MsgPtr BCastReceive.receive(TOS_MsgPtr msg) {
    MateCapsuleMsg* cMsg = (MateCapsuleMsg*)msg->data;
    MateCapsule* capsule = &(cMsg->capsule);
    //    dbg(DBG_TEMP, "Received broadcast capsule.\n");
    if (receiveCapsule(capsule, sizeof(MateCapsule), "bcast", 1) == SUCCESS) {
      amBCasting = TRUE;
      bCastIdx = typeToIndex(capsule->type);
      call BCastTimer.start(TIMER_ONE_SHOT, 10 + call Random.rand() % 90);
    }
    else if (amBCasting) {
      call BCastTimer.stop();
      call BCastTimer.start(TIMER_ONE_SHOT, 10 + call Random.rand() % 90);
    }
    return msg;
  }

  event result_t BCastTimer.fired() {
    sendBCastCapsule(bCastIdx);
    amBCasting = FALSE;
    return SUCCESS;
  }
  
  event result_t CapsuleSend.sendDone(TOS_MsgPtr msg, result_t success) {
    if (msg == sendPtr) {
      sendBusy = FALSE;
      //dbg(DBG_USR3, "Capsule send done event handled.\n");
    }
    return SUCCESS;
  }

  event result_t VersionSend.sendDone(TOS_MsgPtr msg, result_t success) {
    if (msg == sendPtr) {
      sendBusy = FALSE;
      //dbg(DBG_USR3, "Version send done event handled.\n");
    }
    return SUCCESS;
  }

  event result_t BCastSend.sendDone(TOS_MsgPtr msg, result_t success) {
    if (msg == sendPtr) {
      sendBusy = FALSE;
    }
    return SUCCESS;
  }
}
