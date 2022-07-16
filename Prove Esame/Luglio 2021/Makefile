C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
OBJ=driver.o Date.o Rilevamento.o Rilevatore.o
DEPS=Date.h Rilevamento.h Rilevatore.h City.h

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}