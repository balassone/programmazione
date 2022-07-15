//vectorMergeSort.cpp
//vectorMergeSort example 

/*
// Create an empty vector
    vector<int> vect1;
    int n = 3;

//Creates a vector with 3 int initialized to zero
    vector<int> vect2(3);

//Create a vector of size n with all values as 10
    vector<int> vect3(n,10);

//create a vector with initializers
    vector<int> vect4{10, 20, 30};
*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

void merge(vector <int> &,int, int , int);

//mergeSort
void mergeSort(vector<int>&A, int p, int r){
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
//Merge
void merge(vector<int>&A, int p, int r, int q){
    int i,j,k;
    static vector<int> c (A.size());
    i=p;
    k=p;
    j=q+1;
    while(i <= q && j <= r) {
        if(A[i] < A[j]){
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
        c[k] == A[i];
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

int main(){
    vector <int> myarray;
    int num; 
    int val;
    cout<<"Enter number of elements to be sorted: ";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted: ";
    for(int i = 0; i < num; i++){
        cin>> val;
        myarray.push_back(val);
    }
    mergeSort(myarray, 0, num-1);
    cout <<"Sorted array \n";
    for(int i = 0; i<< num; i++){
        cout<<myarray[i]<<"\t";
    }
    cout <<"\n";
}