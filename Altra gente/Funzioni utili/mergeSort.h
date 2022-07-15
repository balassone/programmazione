#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;


//Merge
template <typename M>
void merge(vector<M>&A, int p, int r, int q){
    int i,j,k;
    static vector<M> c (A.size());
    i=p;
    k=p;
    j=q+1;
    while(i <= q && j <= r) {
        if(*A[i] < *A[j]){
            c[k] = A[i];
            k++;
            i++;
        }
        else {
            c[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= q) 
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        c[k] = A[j];
        k++;
        j++;
    }

    for (i = p; i < k; i++){
        A[i] = c[i];
    }
}

//mergeSort
template <typename M>
void mergeSort(vector<M>&A, int p, int r){
    int q;
    if ( p < r){
        //divide the array at mid and sort independently using merge sort
        q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        //merge or conquer sorted arrays
        merge(A,p,r,q);
    }
}
//passo iniziale
template <typename M>
void mergeSort(vector<M>&A){mergeSort(A, 0, A.size()-1);}

