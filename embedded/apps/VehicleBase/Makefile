COMPONENT=VehicleBaseAppC

CFLAGS += -DCC2420_NO_ACKNOWLEDGEMENTS
CFLAGS += -DCC2420_NO_ADDRESS_RECOGNITION

BUILD_EXTRA_DEPS=MoteToBaseMsg.class
BUILD_EXTRA_DEPS+=BaseToMoteMsg.class
BUILD_EXTRA_DEPS+=MoteToVehicleMsg.class
BUILD_EXTRA_DEPS+=VehicleToMoteMsg.class

MoteToBaseMsg.class: MoteToBaseMsg.java
	javac MoteToBaseMsg.java
MoteToBaseMsg.java:
	mig java -target=null -java-classname=MoteToBaseMsg Vehicle.h MoteToBaseMsg -o $@

BaseToMoteMsg.class: BaseToMoteMsg.java
	javac BaseToMoteMsg.java
BaseToMoteMsg.java:
	mig java -target=null -java-classname=BaseToMoteMsg Vehicle.h BaseToMoteMsg -o $@

MoteToVehicleMsg.class: MoteToVehicleMsg.java
	javac MoteToVehicleMsg.java
MoteToVehicleMsg.java:
	mig java -target=null -java-classname=MoteToVehicleMsg Vehicle.h MoteToVehicleMsg -o $@

VehicleToMoteMsg.class: VehicleToMoteMsg.java
	javac VehicleToMoteMsg.java
VehicleToMoteMsg.java:
	mig java -target=null -java-classname=VehicleToMoteMsg Vehicle.h VehicleToMoteMsg -o $@


include $(MAKERULES)

