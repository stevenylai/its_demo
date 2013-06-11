/*
 * "Copyright (c) 2004 and The Regents of the University 
 * of California.  All rights reserved.
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
 * Authors:		Philip Levis
 *                      Neil Patel
 * Date last modified:  3/10/04       Moved Mate to Mate
 *
 */

/**
 * @author Philip Levis
 * @author Neil Patel
 */


includes Mate;
includes MVirus;

configuration MVirusProxy {

  provides {
    interface MateVirus;
    interface StdControl;
  }
  
}


implementation {
  components MVirus as Virus; // if Virus component changes,
                                        // just alter this line

  components TimerC, RandomLFSR, Main;
  components GenericCommPromiscuous as Comm;

  MateVirus = Virus;
  StdControl = Virus;
  
  Main.StdControl -> Virus;
  Virus.SubControl -> Comm;
  Virus.VersionTimer -> TimerC.Timer[unique("Timer")];
  Virus.VersionReceive -> Comm.ReceiveMsg[AM_MATEVERSIONMSG];
  Virus.VersionSend -> Comm.SendMsg[AM_MATEVERSIONMSG];

  Virus.CapsuleTimer -> TimerC.Timer[unique("Timer")];
  //Virus.CapsuleReceive -> ReceiveComm.ReceiveMsg[AM_MATECAPSULEMSG];
  //Virus.CapsuleSend -> SendComm.SendMsg[AM_MATECAPSULEMSG];

  Virus.CapsuleChunkReceive -> Comm.ReceiveMsg[AM_MATECAPSULECHUNKMSG];
  Virus.CapsuleChunkSend -> Comm.SendMsg[AM_MATECAPSULECHUNKMSG];

  Virus.CapsuleStatusReceive -> Comm.ReceiveMsg[AM_MATECAPSULESTATUSMSG];
  Virus.CapsuleStatusSend -> Comm.SendMsg[AM_MATECAPSULESTATUSMSG];
  
  Virus.Random -> RandomLFSR;
  
}
  
