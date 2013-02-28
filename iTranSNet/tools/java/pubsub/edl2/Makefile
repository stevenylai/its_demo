SUBDIRS = middlend symbols frontendComposite backendPSware receiver
COMPILER_BASIC = frontendComposite backendPSware

ROOT = ../..

INITIAL_TARGETS = compiler

include $(ROOT)/Makefile.include

compiler:
	for dir in $(COMPILER_BASIC); do \
		$(MAKE) -C $$dir; \
	done
	
