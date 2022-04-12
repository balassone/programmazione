#include <vector>

using std::vector;
void merge(vector<int>& A, int p, int r, int q){

	int i,j,k;
	static vector<int> c(A.size());
	i=p;
	k=p;
	j=q+1;

	while(i<=q && j<=r){
		if (A[i]<A[j]){
			c[k]=A[i];
			i++;
			k++;
		}
		else{
			c[k]=A[j];
			j++;
			k++;
		}

	}
	while (i<=q){
		c[k]=A[i];
		i++;
		k++;
	}
	while (j<=r){
		c[k]=A[j];
		j++;
		k++;
	}

	for(i=p; i<k; i++){
		A[i]=c[i];
	}
}
void mergeSort(vector<int>& A, int p, int r){

	int q;
	if(p<r){
		q=(p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,r,q);
	}

}
