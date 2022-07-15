testTime: testTime.o Time.o
	g++ -o testTime testTime.o Time.o
testTime.o: testTime.cpp Time.h
	g++ -c testTime.cpp -std=c++11 -Wall -pedantic
Time.o: Time.h Time.cpp
	g++ -c Time.cpp -std=c++11 -Wall -pedantic