#include <array>
const size_t x{10};
template <typename T>
void insertionSort(std::array<T,x>& myArray){

	for(size_t j{1}; j<x; ++j){
		T key=myArray[j];
		size_t i=j;
		while(i>0 && key<myArray[i-1]){
			myArray[i]=myArray[i-1];
			i--;
		}
		myArray[i]=key;
	}

}
