Gcc = g++ 
Cflags = -std=c++11 -Wall -pedantic 
AccountTest: AccountTest.o
	${Gcc} -o AccountTest AccountTest.o
AccountTest.o: AccountTest.cpp Account.h
	${Gcc} -c AccountTest.cpp ${Cflags}
