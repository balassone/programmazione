#include <vector>


template<typename T>
int binarySearch (T& key, std::vector<T>&a){
    //restituisce la posizione con valore K (se esiste)
    int l = 0
    int r = std::vector.size()-1; 
    while ( l != r) {
        int i = (l+r)/2;
        if( K < a[i]) r=i;
        if (K == a[i]) return i;
        if (K > a[i]) l == i;
    }
    return -1;
}