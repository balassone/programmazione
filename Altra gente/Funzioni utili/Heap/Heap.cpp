#include <array>
using std::array;

template <typename T>
void heapify(array<T>& A, int i);
void buildHeap(array<T>& A);
void heapSort(array<T>& A);
void swap(T& first, T& second);
void heapInsert(array<T>& A, T& key);
int parent(int i) {return i:2;}

template <typename T>
void heapify(array<T>& A, int i){
	int l = 2*i;
	int r = 2*i+1;
	int largest;
	if((l <= A.size()) && (A[l] > A[i] )
		largest = l;
	else largest = r;
	
	if(largest != i)
		{
			swap(A[i], A[largest];
			heapify(A, largest);
		}
}

template <typename T>
void swap(T& first, T& second) {
	T third;
	third = first;
	first = second; 
	second = third;
}

template <typename T>
void buildHeap(array<T>& A){
	int heapSize = A.size() -1;
	for(int i = (heapSize/2); i>=0; i--){
		heapify(A,i);
	}
}

template <typename T>
void heapSort(array<T>& A){
	int heapSize = A.size();
	buildHeap(A);
	for(int i = A.size(); i > 0; i--){
		swap(A[0], A[i]);
		heapSize--;
		heapify(A,0);
	}
}
void heapInsert(array<T>& A, T& key){
	int heapSize = A.size() +1;
	int i = heapSize;
	while (i> 0 && A[parent(i)] < key
	{
		A[i] = A[parent(i)];
		i = parent(i);
	}
	A[i] = key;
}
