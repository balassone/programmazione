//Palindrome.cpp
//Determine whether a number is palindrome
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

bool isPalindrome (unsigned int mySeq[], int len);

int main () {
  unsigned int number{0}; //user input number
  unsigned int nDigits{0};
  unsigned int digits[20];

  cout<<"Enter a number: ";
  cin>>number;
  cout<<"You entered "<<number<<endl;

  while (number !=0){
    digits[nDigits++] = number % 10; //%10 vuol dire modulo 10: prende l'ultima cifra del numero
    number /= 10; //butta via l'ultima cifra del numero dopo che è stata salvata nel vettore
  }

  if (isPalindrome(digits, nDigits)){
    cout<< "The number you entered is palindrome\n";
  }
  else {
    cout<< "The number you entered is NOT palindrome\n";
  }
  return 0;
}

bool isPalindrome (unsigned int seq[], int length) {
  bool answer{true};
  int i{0};
  while (i < length/2) {
    if (seq[i]!=seq[length-i-1]){
      answer=false;
      break;
    }
    i++;
  }
  return (answer);
}
