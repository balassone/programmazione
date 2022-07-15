CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Polynomial.h
OBJ=Polynomial.o testPolynomial.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testPolynomial: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)	

