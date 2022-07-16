C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g
OBJ=driver.o Date.o
DEPS=Date.h Prenotazione.h Albergo.h Azienda.h

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}