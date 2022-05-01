CC=g++
CFLAGS=-std=c++11 -Wall -pedantic -Wextra
DEPS=Date.h
OBJ=Date.cpp testdate.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
testdate: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
