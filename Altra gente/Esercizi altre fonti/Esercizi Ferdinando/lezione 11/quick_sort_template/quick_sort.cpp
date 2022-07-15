#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template <typename T> void quickSort(vector<T>&,int,int);
template <typename T> int partition(vector<T>&,int,int);
template <typename T> void swap(vector<T>&,int,int);

int main(){
    vector<int> A{30,20,10};
    cout<<"Il vettore non ordinato è: "<<endl;
    for(int i: A){
    	cout<<i<<"\t";
    }
    quickSort(A,0,A.size()-1);
    cout<<endl;
    cout<<"Il vettore ordinato è: "<<endl;
    	for(int i: A){
    	 cout<<i<<"\t";
    }
    

}


template <typename T> void quickSort(vector<T>& A, int p, int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

template <typename T> int partition(vector<T>& A, int p, int r){
    int x=A[p];
    int i=p-1;
    int j=r+1;
    while(true){
        do
             j=j-1;
        while(A[j]>x);
        do 
            i=i+1;
        while(A[i]<x);
        if(i<j)
            swap(A,i,j);
            else
                return j;
    }
}

template <typename T> void swap(vector<T>& A, int i, int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
