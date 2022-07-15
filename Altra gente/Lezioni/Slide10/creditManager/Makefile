#MakeFile for the processing project
CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = ClientData.h
OBJ1 = ClientData.o creditProcessing.o
OBJ2 = ClientData.o creditProcessingWrite.o
OBJ3 = ClientData.o creditProcessingRead.o
OBJ4 = ClientData.o transactionProcessing.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

all: creditProcessing creditProcessingWrite creditProcessingRead transactionProcessing
	
creditProcessing: $(OBJ1)
		$(CC) -o $@ $^ $(CFLAGS)
creditProcessingWrite: $(OBJ2)
		$(CC) -o $@ $^ $(CFLAGS)
creditProcessingRead: $(OBJ3)
		$(CC) -o $@ $^ $(CFLAGS)
transactionProcessing: $(OBJ4)
		$(CC) -o $@ $^ $(CFLAGS)