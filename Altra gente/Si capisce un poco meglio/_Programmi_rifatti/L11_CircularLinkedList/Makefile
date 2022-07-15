CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=CNode.h CLinkedList.h CLinkedList.cpp
OBJ=testCLinkedList.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testCLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)