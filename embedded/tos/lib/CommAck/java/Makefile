MIG = mig java
ROOT = $(TOSROOT)/tools/java

MSGS = MsgACK.java
INITIAL_TARGETS = $(MSGS)
OTHER_CLEAN = cleanmig

include $(ROOT)/Makefile.include

MsgACK.java:
	$(MIG) -java-classname=MsgACK $(PCFLAGS) ../CommAck.h MsgACK -o $@
	$(JAVAC) $@

cleanmig:
	rm -f $(MSGS)
