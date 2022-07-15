CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=ClientData.h
OBJ=creditProcessingRead.o ClientData.o

%.o:%.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
creditProcessingRead: $(OBJ)
	$(CC) -o $@ $^
