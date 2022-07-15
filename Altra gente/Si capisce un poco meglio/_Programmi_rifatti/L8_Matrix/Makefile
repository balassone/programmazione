CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Matrix.h
OBJ=Matrix.o testMatrix.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testMatrix: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)	

