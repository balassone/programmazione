# Makefile for the Employee project

CC=g++
CFLAGS=-std=c++11
DEPS = BasePlusCommissionEmployee.h CommissionEmployee.h Employee.h SalariedEmployee.h 
OBJ1 = CommissionEmployee.o SalariedEmployee.o testEmployee.o  BasePlusCommissionEmployee.o  Employee.o
OBJ2 = CommissionEmployee.o SalariedEmployee.o testDynCasting.o BasePlusCommissionEmployee.o  Employee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: testEmployee testDynCasting

testEmployee: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)
testDynCasting: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

