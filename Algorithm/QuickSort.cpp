#include <vector>
template <typename T>

void swap(std::vector<T>& A, const int& i, const int& j){
	T temp{A[i]};
	A[i]=A[j];
	A[j]=temp;
}
template <typename T>
int partition(std::vector<T>& A, int p, int r){
	T x=A[p];
	int i=p-1;
	int j=r+1;
	while(true){
		do
			j-=1;
		while(A[j]>x);
		do
			i+=1;
		while(A[i]<x);
		if(i<j)
			swap(A,i,j);
		else
			return j;

	}
}
template <typename T>
void quickSort(std::vector<T>& A, int p, int r){
	if(p<r){
		int q{partition(A,p,r)};
		quickSort(A,p,q);
		quickSort(A,q+1,r);
	}
}
