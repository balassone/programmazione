//readTillEOF.cpp
//program that reads integer given in input until EOF
//then counts how many valid integers are given in input
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <limits>

using std::vector;
using std::cin;
using std::cout;
using std::setw;
using std::endl;

//function prototypes

void insert(vector<int32_t> &v); 
void control(vector<int32_t> &v, int n);
bool search(vector<int32_t> &v, int n);
void output(vector<int32_t> &v);

int main(){
    vector <int32_t> inputNumbers;
    insert(inputNumbers);
    output(inputNumbers);

}

//allows to insert numbers into the vector until EOF
void insert(vector<int32_t> &v){
    int32_t input {0};
    cin.exceptions(std::istream::failbit);
    while(input != -1){
        //the exception controls if the input number is an int
        //otherwise the input will be discarded with an error message
        try
        {
            input = 0;
            cout << "\ninsert value inside the vector \n";
            cin >> input;
        }
        catch (std::istream::failure& e) {                                                                                                                                                                                                                                                                                  
             cout << "invalid argument given in input, please try again";                                                                                                                                                                                                                                                                                      
             cin.clear();                                                                                                                                                                                                                                                                                                 
             cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
             continue;                                                                                                                                                                                                                                                          
         }
        if(input!= -1)control(v, input); 
    }
}

//checks if the value is already in array. 
//If is not, the function will provide to insert the value in the array
void control(vector<int32_t> &v, int32_t n){
    if(!search(v,n)){
        v.push_back(n);
    }
    else{
        cout << "\n\nthe number is already in the vector, please try again\n";
    }
}

void output (vector<int32_t> &v){
    cout << "number of input inserted: "<<v.size()
        << "\nInput number"<< setw(15) <<"value\n";
    for(int i=0; i<v.size(); i++){
        cout << i << setw(25) <<v[i]<<"\n";
    }
}

//binary search algorytm to find if the number is already in the vector
bool search(vector<int32_t> &v, int n) {
    bool found{false};
    for(const auto value: v){
        if(value == n){
            found = true;
            break;
        }
    }
    return found;
}