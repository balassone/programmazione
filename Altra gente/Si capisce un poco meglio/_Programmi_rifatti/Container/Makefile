CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Box.h CLinkedList.h CLinkedList.cpp CNode.h Container.h DList.h DList.cpp DNode.h Iterator.h Iterator.cpp Queue.h Queue.cpp
OBJ=Box.o Container.o main.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)