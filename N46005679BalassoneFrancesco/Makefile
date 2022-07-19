C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
OBJ=Persona.o Matrix.o Community.o driver.o
DEPS=Persona.h Matrix.h Community.h

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver:	${OBJ}
	${C} -o $@ $^ ${FLAGS}