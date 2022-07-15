#Makefile for testDLinkedList
CC = g++
CFLAGS = -std=c++11
DEPS = Dnode.h DLinkedList.h DLinkedList.cpp
OBJ = testDLinkedList.o

%o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testDLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


