CC=g++
CFLAGS=-std=c++11
DEPS=CNode.h CircleLinkedList.h CircleLinkedList.cpp
OBJ=testCLinkedList.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
testCLinkedList:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)