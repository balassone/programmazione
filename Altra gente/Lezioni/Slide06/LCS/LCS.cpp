// LCSIterative.cpp
// computes the Longest common subsequence using two-dimensions array

#include <iostream>
#include <array>
using std::cout;
using std::endl;
using std::array;
using std::string;
template <typename T>

// template for the max function
const T& max(const T& x, const T& y) {
    return (x > y)? x:y;
}


//test the lcs funtion
int main(){
    string X{"ATACCAGA"};
    string Y{"CTCCTAG"};
    const size_t rows{9};
    const size_t columns{8};
    int lcsLength{0};
    array < array <int, rows>, columns> table {0};
    
    for(int i =0; i< rows; i++){
        for(int j=0; j < columns; j++){
            if(i==0 || j == 0){
                table[i][j] = 0;
            }
            else if(X.at(i-1) == Y.at(j-1)){
                lcsLength++;
                table[i][j] = lcsLength;
            }
            else
            {
                table[i][j] = lcsLength;
            }
            cout << table[i][j] <<" ";
        }
        cout << "\n";
    }

    cout << "Length of LCS is " << lcsLength << endl;

    
    return 0;
}