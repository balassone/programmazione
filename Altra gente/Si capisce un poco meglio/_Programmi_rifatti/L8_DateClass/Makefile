CC= g++
CFLAGS = -std=c++11 -Wall
DEPS = Date.h
OBJ = Date.o testDate.o

%.o : %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
test : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 