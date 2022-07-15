CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = heap.h heap.cpp
OBJ = main.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)