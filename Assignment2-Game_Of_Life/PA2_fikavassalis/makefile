
# Fivos Kavassalis/fikavassalis

# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called life
all:life

life: life.o game.o helpers.o
	gcc $(CFLAGS) life.o game.o helpers.o -lm -o life
life.o: life.c life.h
	gcc $(CFLAGS) -c life.c
game.o: game.c life.h
	gcc $(CFLAGS) -c game.c
helpers.o: helpers.c life.h
	gcc $(CFLAGS) -c helpers.c
clean:
	rm -f *.o life
	rm -f -r html latex
# Give command "make docs" to create documentation.
docs:
	doxygen
