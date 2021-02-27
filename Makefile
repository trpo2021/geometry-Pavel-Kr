CC= g++
CFLAGS = -Wall -Werror

all: main

main: geometry.o circlecheck.o
	$(CC) -o $@ $^

geometry.o: geometry.cpp
	$(CC) $(CFLAGS) -c $<
	
circlecheck.o: circlecheck.cpp
	$(CC) $(CFLAGS) -c $<	

clean:
	rm *.o main
