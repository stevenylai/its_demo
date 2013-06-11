# Top-level Makefile for tools/java

SUBDIRS = Message DataEngine Display Manager

#all: Message Utility DataEngine Display Manager

# Module dependence
#DataEngine: Utility
#	$(MAKE) -C $<
#Display: Utility DataEngine
#	$(MAKE) -C $<
# Display & Manager has inter-dependence but anyway
# Java is able to resolve the depencence when compiling.
#Manager: Message Utility DataEngine 
#	$(MAKE) -C $<

ROOT = ../..
include $(ROOT)/Makefile.include
