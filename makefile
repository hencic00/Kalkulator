CC = g++ -std=c++11
CFLAGS = -Wall -pedantic -g -w

DEPENDENCIES = ./dependencies/

all: main

main: main.o
		$(CC) $(CFLAGS) main.o -o main -lncurses

main.o:
		$(CC) $(CFLAGS) -c main.cpp -lncurses -I$(DEPENDENCIES)

clean:
		rm *o main