//Addition program that displays the sum of two integers

#include <iostream>

int main () {
  //declaring and initializing variables
  int number1{0};
  int number2{0};
  int sum{0};

  std::cout<< "Enter first integer :\n";
  std::cin>>number1;

  std::cout<<"Enter second integer :\n";
  std::cin>>number2;

  sum=number1+number2;

  std::cout<<"Sum is :\t"<<sum<<std::endl;
}
