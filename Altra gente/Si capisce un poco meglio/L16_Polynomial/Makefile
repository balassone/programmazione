testPolynomial: testPolynomial.o Polynomial.o
	g++ -o testPolynomial testPolynomial.o Polynomial.o
testPolynomial.o: testPolynomial.cpp Polynomial.h
	g++ -c testPolynomial.cpp -std=c++11 -pedantic -Wall
Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -c Polynomial.cpp -std=c++11 -pedantic -Wall