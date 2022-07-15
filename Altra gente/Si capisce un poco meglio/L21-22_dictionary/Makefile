CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=dict.h
OBJ=dict.o dizionario.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
dizionario:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 