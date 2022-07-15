//vectorQuickSortBinarySearchFunctions.cpp
//example of QuickSort using vectors
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

//function prototypes
void quickSort(vector<int> &A, int p, int r);
void swap(vector<int> &A, int x, int y);
int partition(vector<int>&A, int p, int q);
int binarySearch(vector<int> &A, int num);
int binarySearchRecursive(vector<int> &A, int num, int left, int right);
//function implementations

void quickSort(vector<int> &A, int p, int r){
    if(p < r ){
        int q = partition(A, p, r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

void swap(vector<int> &A, int x, int y){
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(vector<int> &A, int p, int r){
    int x = A[p];
    int i = p-1;
    int j = r+1;
    while (true)
    {
        do
            j=j-1;
        while(A[j]>x);
        do
            i = i+1;
        while (A[i] < x);
        if(i < j)swap(A,i,j);
        else return j;
    }
    
}

