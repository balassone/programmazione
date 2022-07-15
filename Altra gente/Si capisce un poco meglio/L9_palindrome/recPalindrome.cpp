//recPalindrome.cpp
//program that verifies if a string is palindrome

#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;

bool recPalindrome(string word);
int main(){
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    if (recPalindrome(word)){
        cout<<word<<" IS palindrome\n";
    }        
    else {
        cout<<word<<" is NOT palindrome\n";
    }
    return 0;
}

bool recPalindrome(string word) {
    if (word.length()<=1){ 
        return true; //caso base
    }
    else {
        return word.at(0) == word.at(word.length()-1) && recPalindrome(word.substr(1,word.length()-2)); //caso ricorsivo
    }
}