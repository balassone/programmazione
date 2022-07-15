//MergeSort.cpp
#include<vector>
#include<iostream>
using std::vector;

template<typename T>
void mergeSort(vector<T>&, int, int);
template<typename T>
void merge(vector<T>&, int, int, int);


int main(){
    vector<int> a={3,5,7,9,6,4,2,6,5,1};
    mergeSort(a, 0, a.size()-1);
    for (int i=0; i<a.size(); i++){
        std::cout<<a[i]<<"\t";
    }
}


template<typename T>
void mergeSort(vector<T>& A, int p, int r ){
    int q;
    if (p<r){
        q=(p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A,p,r,q);
    }
}

template<typename T>
void merge(vector<T>& A, int p, int r, int q){

    int i; //indice che scorre la metÃ  lista di sinistra-->parte dal primo elemento di questa sottolista
    int j; //indice che scorre la metÃ  lista di destra--> parte dal primo elemento di questa sottolista
    int k; //indice che scorre la lista che deve esser ordinata, ovvero il vettore da costruire
    static vector<T> c(A.size());
    i=p;
    k=p;
    j=q+1;
    while (i<=q && j<=r){
        if (A[i]<A[j]){
            c[k]=A[i];
            k++;
            i++;
        }
        else {
            c[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=q){
        c[k]=A[i];
        k++;
        i++;
    }
    while (j<=r){
        c[k]=A[j];
        k++;
        j++;
    }

    for (i=p; i<k; i++){
        A[i]=c[i];
    }
}