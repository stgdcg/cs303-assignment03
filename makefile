CC = g++
CFLAGS = -g -Wall

TARGET = main

all: main

main: main.o PostfixConverter.o
	$(CC) $(CFLAGS) -o main main.o PostfixConverter.o

main.o: main.cpp PostfixConverter.h Queue.h
	$(CC) $(CFLAGS) -c main.cpp

PostfixConverter.o: PostfixConverter.h
	$(CC) $(CFLAGS) -c PostfixConverter.cpp

clean:
	rm main.o PostfixConverter.o
