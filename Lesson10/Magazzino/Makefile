C = g++
FLAGS = -std=c++11 -Wall -pedantic -Wextra -g
OBJ = Article.o driver.o
DEPS = Article.h

%.o: %.cpp $(DEPS)
	$(C) -c -o $@ $< $(FLAGS)
driver: $(OBJ)
	$(C) -o $@ $^ $(FLAGS)
