CC=g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = DLinkedList.h DLinkedList.cpp DNode.h Date.h Libro.h Quicksort.h Prestito.h
OBJ = Date.o Libro.o main.o Prestito.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)