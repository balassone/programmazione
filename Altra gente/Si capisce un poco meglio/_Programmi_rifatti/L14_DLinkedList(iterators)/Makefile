CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=DNode.h DList.h DList.cpp Iterator.h Iterator.cpp
OBJ=testDList.o 

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testDList: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)