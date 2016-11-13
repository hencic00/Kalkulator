CC = g++ -std=c++11
CFLAGS = -Wall -pedantic -g -w

DEPENDENCIES = ./dependencies/

all: main

main: main.o
		$(CC) $(CFLAGS) main.o -o main

main.o:
		$(CC) $(CFLAGS) -c main.cpp -I$(DEPENDENCIES)

clean:
		rm *o main