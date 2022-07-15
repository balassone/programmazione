CC=g++
CFLAGS= -std=c++11 -Wall -pedantic
DEPS = Date.h Node.h LinkedList.h LinkedList.cpp Cliente.h Albergo.h
OBJ = Date.o Cliente.o Albergo.o AlbergoDriver.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
Driver: ${OBJ}
		$(CC) -o $@ $^ $(CFLAGS)

						
							