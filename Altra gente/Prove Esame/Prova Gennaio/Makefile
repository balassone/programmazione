CC = g++
CFLAGS = -std=c++11
DEPS = Date.h ListaP.h NodoP.h Pacco.h PaccoExtra.h
OBJ = Date.o  ListaP.o Pacco.o PaccoExtra.o Driver.o

%.o: %.cpp ${DEPS}
		${CC} -c -o $@ $< ${CFLAGS}
Driver: ${OBJ}
		${CC} -o $@ $^ ${CFLAGS}