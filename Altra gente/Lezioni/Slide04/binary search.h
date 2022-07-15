#include <iostream>

static int binary (int K, int* array, int left, int right){
    //restituisce la posizione con valore K (se esiste)
    int l = left-1;
    int r = right+1; 
    while ( l+1 != r) {
        int i = (l+r)/2;
        if( K < array[i]) r=i;
        if (K == array[i]) return i;
        if (K > array[i]) l == i;
    }
    return 0;
}