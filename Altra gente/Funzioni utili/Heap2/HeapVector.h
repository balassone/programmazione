#include <vector>
#include <iostream>

template <typename T>
void swap(T& first, T& second) {
	T third;
	third = first;
	first = second; 
	second = third;
}
template <typename T>
void heapify(std::vector<T>& A, const int i){
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
template <typename T>
void buildHeap(std::vector<T>& A){
	int halfSize = (A.size()-1)/2;
	for(int i = halfSize; i>=0; i--){
		heapify(A,i);
	}
}
template <typename T>
void heapify(std::vector<T>& A, int i, int sizeVector = A.size()){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < sizeVector) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < sizeVector && A[r] > A[largest]) largest = r;
	
	if(largest != i)
		{
			swap(A[i], A[largest]);
			heapify(A, largest, sizeVector);
		}
}

template <typename T>
void heapSort(std::vector<T>& A){
	buildHeap(A);
	for(int i = A.size()-1; i > 0; i--){
        swap(A[0], A[i]);
		heapify(A,0,i);
	}
}

template <typename T>
T heapExtractMax(vector<T>&v){
    //if(v.size() == 0) return;
    T value = v[0];
    swap(v[0], v[v.size()-1]);
    v.pop_back();
    heapify(v,0);
    return value;
}

template <typename T>
void heapInsert(std::vector<T>& A, const T& key){	
	A.push_back(key);
	int i = A.size()-1;
	int parent = (i%2 == 0) ? (i-1)/2 : i/2;
	while (i>0 && A[parent] < key)
	{
		std::cout << " swapping "<< key << " with " << A[parent];
		A[i] = A[parent];
		i = parent;
		parent = (i%2 == 0) ? (i-1)/2 : i/2;
	}
	A[i] = key;
}