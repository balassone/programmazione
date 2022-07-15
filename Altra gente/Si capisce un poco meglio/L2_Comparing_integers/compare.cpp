//Program comparing 2 integers

#include <iostream>
using std::cout;
using std::cin;
using std::endl ;

int main () {
  int num1{0};
  int num2{0};

  cout<<"Inserire il primo numero: "<<endl;
  cin>>num1;
  cout<<"Inserire il secondo numero: "<<endl;
  cin>>num2;

  if(num1>num2){
    cout<<num1<<" e' maggiore di "<<num2<<endl;
  }
  else{
    if (num2>num1){
      cout<<num1<<" e' minore di "<<num2<<endl;
    }
    else {
      cout<<num1<<" e' uguale a  "<<num2<<endl;
    }
  }
}

