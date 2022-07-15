CC=g++
CFLAGS=-std=c++11
DEPS=Rilevamento.h NodoRil.h, RilevList.h, City.h, Date.h, Rilevamento.cpp, RilevList.cpp, City.cpp, Date.cpp, RilevDriver.cpp
OBJ=Rilevamento.o, RilevList.o, City.o, Date.o, RilevDriver.o 

%.o: %.cpp $(DEPS)

	$(CC) -c -o $@ $< $(CFLAGS)

RilevDriver: $(OBJ)

	$(CC) -o $@ $^ $(CFLAGS)
