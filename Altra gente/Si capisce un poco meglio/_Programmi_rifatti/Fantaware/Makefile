CC= g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Date.h Progetto.h Programmatore.h Node.h LinkedList.h LinkedList.cpp
OBJ = main.o Date.o Progetto.o Programmatore.o

%.o : %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 