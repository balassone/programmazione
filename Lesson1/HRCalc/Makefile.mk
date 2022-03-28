HRCalc: HRCalc.o
	g++ -o HRCalc HRCalc.o
HRCalc.o: HRCalc.cpp
	g++ -c HRCalc.cpp -std=c++11 -Wall -pedantic -Wextra