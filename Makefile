# makefile for scheduling program

CC=gcc
CFLAGS=-Wall -g

clean:
	rm -rf *.o
	rm -rf main

all: main.o list.o
	$(CC) $(CFLAGS) -o main main.o list.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c