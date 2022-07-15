#include <vector>

template <typename T>
void heapify(std::vector<T>& A, int i){
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
	int heapSize = A.size();
	for(int i = (heapSize/2)-1; i>=0; i--){
		heapify(A,i);
	}
    for(int i = 0; i<A.size(); i++){
        cout << A[i] << " ";
    }
}
template <typename T>
void heapify(std::vector<T>& A, int i, int sizeVector){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < sizesVector) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < sizesVector && A[r] > A[largest]) largest = r;
	
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
void swap(T& a, T&b) {
    T c;
    c = a;
    a = b;
    b = c;
}