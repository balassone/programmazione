cascade: cascade.o Time.o
	g++ -o cascade cascade.o Time.o
cascade.o: cascade.cpp Time.h
	g++ -c cascade.cpp -std=c++11 -Wall -pedantic
Time.o: Time.cpp Time.h
	g++ -c Time.cpp -std=c++11 -Wall -pedantic