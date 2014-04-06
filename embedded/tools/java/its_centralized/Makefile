JAVAC = javac
MIG = mig
VEHICLE_DIR = ../../../apps/Vehicle
TRAFFICLIGHT_DIR = ../../../apps/TrafficLight
#ACK_DIR = ../../../apps/BaseStationAck
JAVA_CLASSES = $(patsubst %.java,%.class,$(wildcard *.java))
MESSAGES = VehicleMsg TrafficLightMsg #AckMsg

all: $(addsuffix .class,$(MESSAGES)) $(JAVA_CLASSES)
clean:
	rm -f *.class
	rm -f $(addsuffix .java,$(MESSAGES))

VehicleMsg.java: $(VEHICLE_DIR)/Vehicle.h
	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(VEHICLE_DIR)/Vehicle.h $(patsubst %.java,%,$@) -o $@
TrafficLightMsg.java: $(TRAFFICLIGHT_DIR)/TrafficLight.h
	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(TRAFFICLIGHT_DIR)/TrafficLight.h $(patsubst %.java,%,$@) -o $@
#AckMsg.java: $(ACK_DIR)/RelayAck.h
#	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(ACK_DIR)/RelayAck.h $(patsubst %.java,%,$@) -o $@

%.class: %.java
	$(JAVAC) $<
