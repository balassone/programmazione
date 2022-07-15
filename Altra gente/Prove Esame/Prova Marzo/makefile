CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = CNode.h CLinkedList.h CLinkedList.cpp LinkedQueue.h LinkedQueue.cpp Paziente.h Dottore.h
OBJ = Paziente.o Dottore.o PoliambulatorioDriver.o

%.o: %.cpp ${DEPS}
		${CC} -c -o $@ $< ${CFLAGS}
PoliambulatorioDriver: ${OBJ}
		${CC} -o $@ $^ ${CFLAGS}


