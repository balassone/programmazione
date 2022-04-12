#include <array>

using std::array;

const size_t x{10};

void insertionSort(array<int,x> myArray){

	for(size_t j{1}; j<x; ++j){
		int key=myArray[j];
		size_t i=j;
		while(i>0 && key<myArray[i-1]){
			myArray[i]=myArray[i-1];
			i--;
		}
		myArray[i]=key;
	}

}
