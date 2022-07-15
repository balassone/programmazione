CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=CNode.h CLinkedList.h CLinkedList.cpp Queue.h Queue.cpp
OBJ=testQueue.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testQueue: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)