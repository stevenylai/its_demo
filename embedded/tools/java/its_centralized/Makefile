JAVAC = javac
MIG = mig
VEHICLE_DIR = ../../../apps/Vehicle
MESSAGES = MoteToBaseMsg MoteToBaseMsg

all: $(addsuffix .class,$(MESSAGES))
clean:
	rm -f *.class
	rm -f $(addsuffix .java,$(MESSAGES))

%Msg.java: $(VEHICLE_DIR)/Vehicle.h
	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(VEHICLE_DIR)/Vehicle.h $(patsubst %.java,%,$@) -o $@

%.class: %.java
	$(JAVAC) $<
