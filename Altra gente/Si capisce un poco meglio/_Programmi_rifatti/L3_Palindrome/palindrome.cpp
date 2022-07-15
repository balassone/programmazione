//palindrome.cpp
#include<iostream>
#include<string>
using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
    string a;
    cout<<"Insert an integer value and I will tell you wether it is palindrome or not"<<endl;
    cin>>a;
    int i{0};
    while (i < (a.length()/2) && a[i] == a[a.length()-1-i]){
        i++;
    }
    cout<<i<<endl;
    if (i==(a.length()/2)) {
        cout<<"Number is palindrome :)"<<endl;
    }
    else cout<<"Number is NOT palindrome :("<<endl;
}