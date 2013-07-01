JAVAC = javac
MIG = mig
HEADER_DIR = ..
JAVA_CLASSES = $(patsubst %.java,%.class,$(wildcard *.java))
MESSAGES = VehicleTurnMsg

all: $(addsuffix .class,$(MESSAGES)) $(JAVA_CLASSES)
clean:
	rm -f *.class
	rm -f $(addsuffix .java,$(MESSAGES))

%Msg.java: $(HEADER_DIR)/VehicleTurn.h
	$(MIG) java -target=micaz -java-classname=$(patsubst %.java,%,$@) $(HEADER_DIR)/VehicleTurn.h $(patsubst %.java,%,$@) -o $@

%.class: %.java
	$(JAVAC) $<
