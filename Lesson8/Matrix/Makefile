C = g++
FLAGS = -std=c++11 -Wall -pedantic -Wextra
DEPS = Matrix.h
OBJ = Matrix.o driver.o

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${DEPS} -g
