C = g++
FLAGS = -std=c++11 -Wall -pedantic -Wextra
DEPS = TTT.h
OBJ = TTT.o driver.o

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS} -g
