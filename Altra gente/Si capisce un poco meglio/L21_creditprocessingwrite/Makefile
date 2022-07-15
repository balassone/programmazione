CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
OBJ=ClientData.o creditProcessingWrite.o
DEPS=ClientData.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
creditProcessingWrite: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)