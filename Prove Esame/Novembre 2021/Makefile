C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
DEPS=Programmatore.h Task.h Node.h LinkedList.h Project.h Azienda.h Date.h
OBJ=driver.o Programmatore.o LinkedList.o Task.o Project.o Date.o

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}
