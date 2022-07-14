#ifndef BOUBLESORT_H
#define BOUBLESORT_H
#include <vector>
template <typename T>
void boubleSort(std::vector<T>& myVector){
	T temp;
	for(size_t i{0}; i<(myVector.size()-1); ++i){
		for(size_t j{i+1}; j<myVector.size(); ++j){
			if(myVector[i]>myVector[j]){
				temp=myVector[i];
				myVector[i]=myVector[j];
				myVector[j]=temp;
			}
		}
	}
}
#endif