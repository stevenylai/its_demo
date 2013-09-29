# Top-level Makefile for ITRANSNET

SUBDIRS = tracking
ROOT = .

include $(ROOT)/Makefile.include
doc:
	javadoc -d doc -sourcepath . -subpackages itransnet_base
jar:
	echo 'jar cvfm itransnet_base/tracking/Client/Display/HTML/itransnet_base.jar mainclass '>tmp
	find . -name *.class >>tmp
	find . -name '*.properties' >>tmp
	#find . -name *.gif >>tmp
	cat tmp|sed 's/$$/ \\/g'|sed 's/\$$/\\\$$/g'>tmp2
	echo ' '>>tmp2
	chmod 775 tmp2
	sh<tmp2
.PHONY: doc jar
