CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Matrix.h
OBJ = Matrix.o MatrixDriver.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
MatrixDriver: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)