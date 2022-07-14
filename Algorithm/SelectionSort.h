#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <vector>
template <typename T>
void selectionSort(std::vector<T>& myVector){
	T temp;
	size_t posmin;
	for(size_t i{0}; i<myVector.size()-1; ++i){
		posmin=i;
		for(size_t j{i+1}; j<myVector.size(); ++j){
			if(myVector[j]<myVector[posmin]){
				posmin=j;
			}
		}
		if(posmin!=i){
			temp=myVector[i];
			myVector[i]=myVector[posmin];
			myVector[posmin]=temp;
		}
	}

}
#endif