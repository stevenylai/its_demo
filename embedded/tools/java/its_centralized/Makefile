JAVAC = javac
MIG = mig
VEHICLE_DIR = ../../../apps/Vehicle
JAVA_CLASSES = $(patsubst %.java,%.class,$(wildcard *.java))
MESSAGES = MoteToBaseMsg BaseToMoteMsg

all: $(addsuffix .class,$(MESSAGES)) $(JAVA_CLASSES)
clean:
	rm -f *.class
	rm -f $(addsuffix .java,$(MESSAGES))

%Msg.java: $(VEHICLE_DIR)/Vehicle.h
	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(VEHICLE_DIR)/Vehicle.h $(patsubst %.java,%,$@) -o $@

%.class: %.java
	$(JAVAC) $<
