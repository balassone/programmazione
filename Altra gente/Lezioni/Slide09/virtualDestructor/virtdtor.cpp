//virtdtor.cpp
#include "virtdtor.h"
int main() {
	// Note use of base-class ointer
	Base * obj = new Derived();
	delete obj; 	 // invokes the Base destructor
	return 0;
}