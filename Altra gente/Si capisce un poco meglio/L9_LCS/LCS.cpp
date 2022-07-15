//LCS.cpp
//computates the longest common subsequence recursively

#include<iostream>
using std::cout;
using std::endl;
template <typename T>

//template for the maximum function
const T& max(const T& x, const T& y) {
    return(x>y)? x:y;
}

//computers the lcs
int lcs(const std::string& X, const std::string& Y, int m, int n) {

if(m==0 || n==0){
    return 0;
}
if (X[m-1] == Y[n-1]){
    return 1+lcs(X,Y,m-1,n-1);
}
else 
    return max(lcs(X,Y,m-1,n), lcs(X,Y,m,n-1));
}

int main() {
    std::string X{"ACGTCTGATC"};
    std::string Y{"CTGTGTAGTA"};
    
    cout<<"Length of LCS is "<<lcs(X,Y,X.length(),Y.length())<<endl;
    return 0;
}