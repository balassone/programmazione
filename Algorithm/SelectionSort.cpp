#include <array>
using std::array;
const size_t x{10};

void selectionSort(array<int,x>& myArray){
	int temp;
	size_t posmin;
	for(size_t i{0}; i<x-1; ++i){
		posmin=i;
		for(size_t j{i+1}; j<x; ++j){
			if(myArray[j]<myArray[posmin]){
				posmin=j;
			}
		}
		if(posmin!=i){
			temp=myArray[i];
			myArray[i]=myArray[posmin];
			myArray[posmin]=temp;
		}
	}

}
