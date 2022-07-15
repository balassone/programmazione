#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void quickSort(vector<int>&,int,int);
int partition(vector<int>&,int,int);
void swap(vector<int>&,int,int);

int main(){

    vector<int>A{10,30,40,50,20,90,70,80,60};

    cout<<"Il vettore non ordinato è: "<<endl;
    for(size_t i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }

    quickSort(A,0,A.size()-1);


    cout<<"\nIl vettore ordinato è: "<<endl;
    for(size_t i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }

    return 0;
}

void quickSort(vector<int>& v1,int p,int r){
    if(p<r){ //passo base //ci sono almeno due elementi nel vettore
        int q=partition(v1,p,r);
        quickSort(v1,p,q);
        quickSort(v1,q+1,r);
    }
}

int partition(vector<int>& v1,int p,int r){
    int x=v1[p]; //elemento pivot //è il primo elemento del vettore
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while(v1[j]>x);
        do      
            i=i+1;
        while(v1[i]<x);
        if(i<j){
            swap(v1,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(vector<int>& A,int x,int y){
    int temp;
    temp=A[x];
    A[x]=A[y];
    A[y]=temp;
}
