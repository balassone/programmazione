#include <iostream>
#include <array>

using namespace std;



template <typename T, size_t SIZE>
void heapify(array<T,SIZE>& A, int i){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < A.size()) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < A.size() && A[r] > A[largest]) largest = r;
	
	if(largest != i)
		{
            cout << "swapping "<< A[i]<<" with "<<A[largest]<< "\n";
			swap(A[i], A[largest]);
			heapify(A, largest);
		}
    else{cout << "\n swap failed \n";}
}
template <typename T, size_t SIZE>
void buildHeap(array<T,SIZE>& A){
	int heapSize = A.size();
	for(int i = (heapSize/2)-1; i>=0; i--){
		heapify(A,i);
	}
    for(int i = 0; i<A.size(); i++){
        cout << A[i] << " ";
    }
}
template <typename T, size_t SIZE>
void heapify(array<T,SIZE>& A, int i, int sizeArray){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if((l < sizeArray) && (A[l] > A[i] ))
		largest = l;
    else largest = i;

	if(r < sizeArray && A[r] > A[largest]) largest = r;
	
	if(largest != i)
		{
            cout << "swapping "<< A[i]<<" with "<<A[largest]<< "\n";
			swap(A[i], A[largest]);
			heapify(A, largest, sizeArray);
		}
    else{cout << "\n swap failed \n";}
}

template <typename T, size_t SIZE>
void heapSort(array<T,SIZE>& A){
	buildHeap(A);
    cout << "heapsort started \n";
	for(int i = A.size()-1; i > 0; i--){
		cout << "swapping "<< A[0]<<" with "<<A[i]<< "\n";
        swap(A[0], A[i]);
		heapify(A,0,i);
	}
}

int main(){
    array<int, 10> array{1,14,10,8,7,9,3,2,4,16};
    cout <<array.size()<<": is the number of nodes in the tree \n\n\n";
    for(int i=0; i<10; i++){
        cout <<array[i]<<" ";
    }
    heapSort(array);
    for(int i=0; i<10; i++){
        cout <<array[i]<<" ";
    }
    
}