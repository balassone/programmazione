#Makefile for the Polynomial example

CC = g++
CFLAGS = -std=c++11
DEPS = polynomial.h
OBJ = polynomial.o testPolynomial.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
		
testPolynomial: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)