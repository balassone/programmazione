C = g++
FLAGS = -std=c++11 -Wall -pedantic -Wextra
OBJ = Point.o Rectangle.o driver.o
DEPS = Point.h Rectangle.h 

%.o: %.cpp $(DEPS)
	$(C) -c -o $@ $< $(FLAGS)
driver: $(OBJ)
	$(C) -o $@ $^ $(FLAGS)
