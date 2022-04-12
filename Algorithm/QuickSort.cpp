#include <vector>
using std::vector;
using std::swap;
int partition(vector<int>& A, int p, int r){
	int x=A[p];
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
			swap(A[i],A[j]);
		else
			return j;

	}
}
void quickSort(vector<int>& A, int p, int r){
	if(p<r){
		int q{partition(A,p,r)};
		quickSort(A,p,q);
		quickSort(A,q+1,r);
	}
}
