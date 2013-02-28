COMPONENT=PSWareTopLevel
#COMPONENT=CompilationTest
#COMPONENT=ArrayListTestC
#COMPONENT=EventInstanceTestC
#COMPONENT=EventRoutingTestC

SOURCEDIR=.
LIBDIR=../../tos/lib

CFLAGS=-I$(LIBDIR)/VM/opcodes -I$(LIBDIR)/VM/contexts -I$(LIBDIR)/VM/languages  -I$(LIBDIR)/VM/components -I$(LIBDIR)/VM/types -I$(LIBDIR)/VM/interfaces -I$(LIBDIR)/ArrayList -I$(SOURCEDIR) -I$(TOSROOT)/tos/sensorboards/micasb -I../iTransLib
PFLAGS=-v
BUILD_EXTRA_DEPS=java

include $(TOSROOT)/apps/Makerules
#export the target to submake for generating Java class files
export TARGETS
export EXTRAS

java:
	$(MAKE) -C vm_specific
