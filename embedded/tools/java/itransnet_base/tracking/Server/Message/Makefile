
TOS = $(shell ncc -print-tosdir)
PACKAGE = itransnet_base.tracking.Server.Message
APP = $(TOS)/../apps/Oscilloscope
#MIG = mig java -target=pc
MIG = mig java

# List of message classes to build
MSGS = BcastMsg.java ITSMsg.java ITSWarnMsg.java ITSStatisticsMsg.java ITSCmdMsg.java MultiHop.java SensorControlMsg.java

INITIAL_TARGETS = $(MSGS)
OTHER_CLEAN = cleanmig

ROOT = ../../..
ITRANSNETDIR = $(CONTRIB_DIR)
ITRANSNETNCDIR = $(ITRANSNETDIR)/apps/iTransLib
INCDIR = $(TOS)/lib/Broadcast -I$(TOS)/lib/CC2420Radio

include $(ROOT)/Makefile.include

BcastMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).BcastMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h _BcastMsg -o $@
	$(JAVAC) $@

MultiHop.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).MultiHop $(PCFLAGS) $(TOS)/lib/Route/MultiHop.h MultihopMsg -o $@
	$(JAVAC) $@

ITSMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITS.h ITSMsg -o $@
	$(JAVAC) $@

ITSWarnMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSWarnMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSWarn.h ITSWarnMsg -o $@
	$(JAVAC) $@

ITSStatisticsMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSStatisticsMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSStatistics.h ITSStatisticsMsg -o $@
	$(JAVAC) $@

ITSCmdMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).ITSCmdMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h ITSCmdMsg -o $@
	$(JAVAC) $@
	
SensorControlMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).SensorControlMsg $(PCFLAGS) $(ITRANSNETNCDIR)/ITSCmd.h SensorControlMsg -o $@
	$(JAVAC) $@

cleanmig:
	rm -f $(MSGS)

