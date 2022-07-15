CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS= LinkedList.h LStack.h Node.h
OBJ= testLStack.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
testLStack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)