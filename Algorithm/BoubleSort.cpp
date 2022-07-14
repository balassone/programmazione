#include <array>
const size_t x{10};
template <typename T>
void boubleSort(std::array<T,x>& myArray){
	T temp;
	for(size_t i{0}; i<x-1; ++i){
		for(size_t j{i+1}; j<x; ++j){
			if(myArray[i]>myArray[j]){
				temp=myArray[i];
				myArray[i]=myArray[j];
				myArray[j]=temp;
			}
		}
	}
}
