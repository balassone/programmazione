CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Node.h LinkedList.h LinkedList.cpp Stack.h Stack.cpp
OBJ=testStack.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testStack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)