MESSAGES=MateConstants.java CapsuleMsg.java CapsuleChunkMsg.java EventMetaMsg.java EventInstanceMsg.java
ifeq ($(filter "reinstall",$(EXTRAS)),)
BUILD_EXTRA_DEPS=cleanmessage
endif
BUILD_EXTRA_DEPS+=$(MESSAGES)

SOURCEDIR=..
DESTDIR=.
LIBDIR=../../../tos/lib

CFLAGS+=-I$(LIBDIR)/VM/opcodes -I$(LIBDIR)/VM/contexts -I$(LIBDIR)/VM/languages  -I$(LIBDIR)/VM/components -I$(LIBDIR)/VM/types -I$(LIBDIR)/VM/interfaces -I$(LIBDIR)/ArrayList -I$(SOURCEDIR) -I$(SOURCEDIR)/../iTransLib -I$(TOSROOT)/tos/sensorboards/micasb -I$(TOSDIR)/lib/CC2420Radio
OTHER_CLEAN = cleanmessage

all: $(BUILD_EXTRA_DEPS)

MateConstants.java: $(SOURCEDIR)/MateConstants.h
	ncg java -target=$(TARGETS) $(CFLAGS) -java-classname=vm_specific.MateConstants ${SOURCEDIR}/PSWareTopLevel.nc MateConstants.h -o $(DESTDIR)/$@ 
	javac $@

CapsuleMsg.java: $(LIBDIR)/VM/types/Mate.h
	mig java -target=$(TARGETS) $(CFLAGS) -java-classname=vm_specific.CapsuleMsg $(LIBDIR)/VM/types/Mate.h MateCapsuleMsg -o $(DESTDIR)/$@
	javac $@

CapsuleChunkMsg.java: $(LIBDIR)/VM/types/Mate.h
	mig java -target=$(TARGETS) $(CFLAGS) -java-classname=vm_specific.CapsuleChunkMsg $(LIBDIR)/VM/types/Mate.h MateCapsuleChunkMsg -o $(DESTDIR)/$@
	javac $@

EventMetaMsg.java: $(SOURCEDIR)/PEvent.h
	mig java -target=$(TARGETS) $(CFLAGS) -java-classname=vm_specific.EventMetaMsg $(SOURCEDIR)/PEvent.h EventMetaMsg -o $(DESTDIR)/$@
	javac $@

EventInstanceMsg.java: $(SOURCEDIR)/PEvent.h
	mig java -target=$(TARGETS) $(CFLAGS) -java-classname=vm_specific.EventInstanceMsg $(SOURCEDIR)/PEvent.h EventInstanceMsg -o $(DESTDIR)/$@
	javac $@

cleanmessage:
	rm -f $(MESSAGES)
