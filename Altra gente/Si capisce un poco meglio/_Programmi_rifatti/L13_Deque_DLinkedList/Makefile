CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=DNode.h DLinkedList.h DLinkedList.cpp Deque.h Deque.cpp
OBJ=testDeque.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testDeque: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)