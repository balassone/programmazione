CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=DNode.h DLinkedList.h DLinkedList.cpp
OBJ=testDLinkedList.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testDLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)