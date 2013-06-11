
TOS = $(shell ncc -print-tosdir)
PACKAGE = itransnet_base.tracking.Server.Message
APP = $(TOS)/../apps/Oscilloscope
#MIG = mig java -target=pc
MIG = mig java

# List of message classes to build
MSGS = BcastMsg.java ITSMsg.java ITSCmdMsg.java MultiHop.java SensorControlMsg.java FlowCtlMsg.java

INITIAL_TARGETS = $(MSGS)
OTHER_CLEAN = cleanmig

ROOT = ../../..
ITRANSNETDIR = $(CONTRIB_DIR)
ITRANSNETNCDIR = $(ITRANSNETDIR)/apps/Freeway
INCDIR = $(TOS)/lib/Broadcast -I$(TOS)/lib/CC2420Radio
FLOWCTL_MSG=$(ITRANSNETDIR)/apps/FlowControl/FlowControl.h

include $(ROOT)/Makefile.include

BcastMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).BcastMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h _BcastMsg -o $@
	$(JAVAC) $@

MultiHop.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).MultiHop $(PCFLAGS) $(TOS)/lib/Route/MultiHop.h MultihopMsg -o $@
	$(JAVAC) $@

FlowCtlMsg.java:
	$(MIG) -java-classname=$(PACKAGE).FlowCtlMsg $(PCFLAGS) $(FLOWCTL_MSG) FlowCtlMsg -o $@
	$(JAVAC) $@

ITSMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITS.h ITSMsg -o $@
	$(JAVAC) $@

ITSCmdMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSCmdMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h ITSCmdMsg -o $@
	$(JAVAC) $@
	
SensorControlMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).SensorControlMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h SensorControlMsg -o $@
	$(JAVAC) $@

cleanmig:
	rm -f $(MSGS)

