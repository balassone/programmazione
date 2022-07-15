//heapify.h
#include <iostream>
#include <iterator>

template<typename T>
void swap( T& a, T& b){
	T c;
	
	c = a;
	a = b;
	b = c;
	
}
template<typename T>

void heapify(T&const A, int i) {
	int l {2*i};
	int r {2*i+1};
	int largest{0}
	T::const_iterator left (T.begin());
	T::const_iterator right (T.begin());
	T::const_iterator position (T.begin());
	advance(position, i);
	advance(left, l);
	advance(right, r);
	T::const_iterator end(T.end());
	if (l < A.size() && (*left > *position)) largest = l;
	else largest = i;
	
	T::const_iterator large(T.begin());
	advance(large, largest)
	
	if (r < A.size() && (*right >  *largest) largest = r;
	if largest != i;
	{
		swap(*position, *largest);
		heapify(A, largest);
	}
	
} 

template<typename T>
void buildHeap(T& const A){
	int heapSize = A.size();
	for (int i = heapSize/2; i > 0; i--){
		heapify(A,i);
		} 
	
}

template <typename T>
void HeapSort(T& const A) {
	buildHeap(A);
	heapSize = A.size();
	T::const_iterator firstPosition(T.begin());
	T::const_iterator lastPosition(T.begin());
	advance(firstPosition, 1);
	for (int i =A.size(); i > 1; i++){
		advance(lastPosition(T.end());
		swap(*firstPosition, *lastPosition);
		heapSize--;
		heapify(A,1);
	}
	
}