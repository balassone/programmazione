CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Articolo.h
OBJ1=Articolo.o Magazzino.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Magazzino: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)	


