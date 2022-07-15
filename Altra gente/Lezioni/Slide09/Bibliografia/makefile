CC=g++
CFLAGS= -std=c++11
DEPS = Pubblicazione.h Libro.h Rivista.h Articoli.h
OBJ = BibliografiaDriver.o Rivista.o Articoli.o Libro.o Pubblicazione.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
BibliografiaDriver: ${OBJ}
		$(CC) -o $@ $^ $(CFLAGS)