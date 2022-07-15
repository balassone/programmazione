CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Piano.h Cerchio.h Rettangolo.h Triangolo.h NodoP.h ListaP.h
OBJ = Piano.o Cerchio.o Rettangolo.o Triangolo.o ListaP.o Driver.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}
Driver: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}