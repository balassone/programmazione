CC = g++
CFLAGS = -std=c++11
DEPS = Node.h Progetto.h Programmatore.h Task.h LinkedList.h Date.h
OBJ = Date.o  Programmatore.o LinkedList.o Driver.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}
Driver: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}