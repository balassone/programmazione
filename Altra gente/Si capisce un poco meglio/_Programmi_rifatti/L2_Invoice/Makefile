CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Invoice.h
OBJ = Invoice.o testInvoice.o

%.o : %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

testAccount : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)