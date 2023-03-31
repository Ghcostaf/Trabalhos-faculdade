CC = g++
CFLAGS = -Wall -g

all: linkedlist

linkedlist: main.o linkedlist.o
	$(CC) $(CFLAGS) -o linkedlist main.o linkedlist.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

clean:
	rm -rf *.o linkedlist
