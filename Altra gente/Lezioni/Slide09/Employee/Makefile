# Makefile for the Employee project

CC=g++
CFLAGS= -std=c++11 -pedantic -Wall
DEPS = BasePlusCommissionEmployee.h CommissionEmployee.h Employee.h SalariedEmployee.h
OBJ = CommissionEmployee.o SalariedEmployee.o testEmployee.o BasePlusCommissionEmployee.o Employee.o
OBJ2 = CommissionEmployee.o SalariedEmployee.o testDynCasting.o BasePlusCommissionEmployee.o Employee.o

%.o: %.cpp $(DEPS)
		 $(CC) -c -o $@ $< $(CFLAGS)
all: testEmployee testDynCasting
	
testEmployee: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
		
testDynCasting: $(OBJ2)
		$(CC) -o $@ $^ $(CFLAGS)