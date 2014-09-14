
TOS = $(shell ncc -print-tosdir)
PACKAGE = itransnet_base.tracking.Server.Message
#MIG = mig java -target=pc
MIG = mig

# List of message classes to build
MSGS = VehicleMsg

INITIAL_TARGETS = $(addsuffix .class,$(MSGS))
OTHER_CLEAN = cleanmig

ROOT = ../../..
VEHICLE_DIR = $(ROOT)/../../../apps/Vehicle
ITRANSNETDIR = $(CONTRIB_DIR)
ITRANSNETNCDIR = $(ITRANSNETDIR)/apps/iTransLib
INCDIR = $(TOS)/lib/Broadcast -I$(TOS)/lib/CC2420Radio

include $(ROOT)/Makefile.include

%Msg.java: $(VEHICLE_DIR)/Vehicle.h
		$(MIG) java -target=micaz -java-classname=$(PACKAGE).$(patsubst %.java,%,$@) $(PCFLAGS) $(VEHICLE_DIR)/Vehicle.h $(patsubst %.java,%,$@) -o $@

%.class: %.java
	$(JAVAC) $<

cleanmig:
	rm -f $(MSGS)

