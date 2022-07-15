CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Heap.h Heap.cpp PriorityQueue.cpp PriorityQueue.h
OBJ=main.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)