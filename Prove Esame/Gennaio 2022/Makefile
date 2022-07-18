FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
DEPS=Date.h Pacco.h Extra.h Node.h LinkedList.h Azienda.h
OBJ=driver.o Date.o Pacco.o Extra.o

%.o: %.cpp ${DEPS}
	g++ -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	g++ -o $@ $^ ${FLAGS}
