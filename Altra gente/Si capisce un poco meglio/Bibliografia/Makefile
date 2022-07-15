CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Libro.h Convegno.h Rivista.h Pubblicazione.h
OBJ=Pubblicazione.o Libro.o Convegno.o Rivista.o main.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)