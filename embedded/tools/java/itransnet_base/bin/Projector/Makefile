TOS = $(shell ncc -print-tosdir)
PACKAGE = itransnet_base.tracking.Testbed.Projector
#MIG = mig java -target=pc
MIG = mig java

# List of message classes to build
MSGS = SensorControlMsg.java

INITIAL_TARGETS = $(MSGS)
OTHER_CLEAN = cleanmig

ROOT = ../../..
ITRANSNETDIR = $(CONTRIB_DIR)
ITRASNETNCDIR = $(ITRANSNETDIR)/apps/Freeway
INCDIR = $(TOS)/lib/Broadcast -I$(TOS)/lib/CC2420Radio

include $(ROOT)/Makefile.include

SensorControlMsg.java:
	$(MIG) -I $(INCDIR) -java-classname=$(PACKAGE).SensorControlMsg $(PCFLAGS) $(ITRASNETNCDIR)/ITSCmd.h SensorControlMsg -o $@
	$(JAVAC) $@

cleanmig:
	rm -f $(MSGS)
