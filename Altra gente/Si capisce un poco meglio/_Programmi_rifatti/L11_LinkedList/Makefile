CC=g++
CFLAGS=-std=c++11 
DEPS=Node.h LinkedList.h LinkedList.cpp
OBJ=testLinkedList.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testLinkedList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)