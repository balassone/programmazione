CC= g++
CFLAGS = -std=c++11 -Wall
DEPS = CreateAndDestroy.h
OBJ = CreateAndDestroy.o test.o

%.o : %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
test : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 