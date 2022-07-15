CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = DNode.h DLinkedList.h DLinkedList.cpp Insegnamento.h Studente.h quickSort.h
OBJ = Insegnamento.o Studente.o IstogrammaDriver.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}
IstogrammaDriver: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}