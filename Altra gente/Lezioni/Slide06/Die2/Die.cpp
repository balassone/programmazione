// die.cpp
//Die-rolling program using and array instead of swithch
#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::array;
using std::setw;
using std::endl;

int main() {
	// use the default random-number generation engine to produce uniformly distributed pseudorandom int values
	// from 1 to 6
	// default_random_engie engine(static cast<usinged int>(time(0)))
	// uniform_int_distribution<unsigned int> randomInt(1,6);
	
	const size_t arraySize{6}; 	 // ignore element zero
	array<unsigned int, arraySize> frequency{}; // initialize to 0s
	
	// roll die 60,000,000 times; use die value as frequency index
	for (unsigned int roll{1}; roll <= 60000000; ++roll){
	++frequency[rand()%6];	
	}
	
	cout << "Face" << setw(13) << "Frequency" << endl;
	
	// output each array element's value
	for (size_t face{0}; face < frequency.size(); ++face) {
		cout << setw(4) << face+1 << setw(13) << frequency[face] << endl;
	}
}