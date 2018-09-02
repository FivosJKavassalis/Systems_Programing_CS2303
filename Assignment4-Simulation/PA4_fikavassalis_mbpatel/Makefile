# Authors: Fivos Kavassalis and Milap Patel

CFLAGS = -g -Wall

all: qSim

# Compile the program:	
qSim: qSim.o Customers.o Events.o qSim.h Customers.h Events.h
	g++ $(CFLAGS)  qSim.o Customers.o Events.o -o qSim

qSim.o: qSim.cpp qSim.h
	g++ $(CFLAGS) -c qSim.cpp

Customers.o: Customers.cpp Customers.h
	g++ $(CFLAGS) -c Customers.cpp

Events.o: Events.cpp Events.h
	g++ $(CFLAGS) -c Events.cpp

# Give command "make docs" to create documentation.	
docs:
	doxygen


# Clean the program
clean:
	rm -f *.o qSim
