CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Book.h Quicksort.h Date.h Borrow.h DLinkedList.h DLinkedList.cpp DNode.h
OBJ=Book.o test.o Date.o Borrow.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)