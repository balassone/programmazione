CC=g++
CFLAGS=-std=c++11 
DEPS=Node.h LinkedList.h LinkedList.cpp
OBJ=testGenericList.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testGenericList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)