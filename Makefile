CC= g++
CFLAGS = -Wall -Werror -c

all: main

main: geometry.o circlecheck.o circle.o
	$(CC) -o $@ $^

geometry.o: geometry.cpp
	$(CC) $(CFLAGS) $<
	
circlecheck.o: circlecheck.cpp
	$(CC) $(CFLAGS) $<	

circle.o: circle.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm *.o main
