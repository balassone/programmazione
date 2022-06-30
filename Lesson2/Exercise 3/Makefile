C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
OBJ= driver.o Motor.o
DEPS= Motor.h

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}

driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}	