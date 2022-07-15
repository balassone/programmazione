Gcc = -g++ 
Cflacs = -std=c++11 -pedantic -Wall 
AccountTest: AccountTest.o
	${Gcc} -o AccountTest AccountTest.o
AccountTest.o: AccountTest.cpp Account.h
	${Gcc} -c AccountTest.cpp ${Cflags}