#include <array>
#include <iostream>

template <typename T>
void swap(T& first, T& second) {
	T third;
	third = first;
	first = second; 
	second = third;
}



template <typename T, size_t SIZE>
void heapify(std::array<T,SIZE>& A, int i){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < A.size()) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < A.size() && A[r] > A[largest]) largest = r;
	
	if(largest != i)
		{
			swap(A[i], A[largest]);
			heapify(A, largest);
		}
}
template <typename T, size_t SIZE>
void buildHeap(std::array<T,SIZE>& A){
	int heapSize = A.size();
	for(int i = (heapSize/2)-1; i>=0; i--){
		heapify(A,i);
	}
    for(int i = 0; i<A.size(); i++){
        std::cout << A[i] << " ";
    }
}
template <typename T, size_t SIZE>
void heapify(std::array<T,SIZE>& A, int i, int sizeArray){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < sizeArray) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < sizeArray && A[r] > A[largest]) largest = r;
	
	if(largest != i)
		{
			swap(A[i], A[largest]);
			heapify(A, largest, sizeArray);
		}
}

template <typename T, size_t SIZE>
void heapSort(std::array<T,SIZE>& A){
	buildHeap(A);
	for(int i = A.size()-1; i > 0; i--){
        swap(A[0], A[i]);
		heapify(A,0,i);
	}
}