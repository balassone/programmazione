//recPalindrome.cpp

#include<string>
#include<iostream>
using std::string;
using std::cin; using std::cout;

bool recPalindrome(const string&);

int main() {
    string word;
    cout<<"Insert a word or a number and i will tell you wether it is palindrome"<<std::endl;
    cin>>word;
    cout<<"bip bip. . . Calculating . . ."<<std::endl;
    if (recPalindrome(word)==true){
        cout<<"Word is palindrome :)"<<std::endl;
    } else cout<<"Word is not palindrome :("<<std::endl;
}

bool recPalindrome(const string& word){
    if (word.length()<=1){
        return true;
    }
    else return (word.at(0) == word.at(word.length()-1) && recPalindrome(word.substr(1, word.length()-2)));
}