CC = g++;
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = BSTNode.h BSTList.cpp BSTList.h
OBJ = main.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)