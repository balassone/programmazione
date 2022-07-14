#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <vector>
template <typename T>
void insertionSort(std::vector<T>& myVector){

	for(size_t j{1}; j<myVector.size(); ++j){
		T key=myVector[j];
		size_t i=j;
		while(i>0 && key<myVector[i-1]){
			myVector[i]=myVector[i-1];
			i--;
		}
		myVector[i]=key;
	}

}
#endif