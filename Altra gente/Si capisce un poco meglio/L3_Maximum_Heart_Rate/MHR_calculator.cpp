//Program calculating Maximum Heart Rate (MHR)

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main (){ 
  int age=0;

  cout<<"Hello, please enter your age and i will tell u your Maximum Heart Rate according to different equations studied in the course of the last years"<<endl;
  cin>>age;
  int MHR1=220-age;
  int MHR2=208-0.7*(age);
  int MHR3=207-0.7*(age);
  int MHR4=211-0.64*(age);
  cout<<"MHR:\n\n"<<MHR1<<"\n"<<MHR2<<"\n"<<MHR3<<"\n"<<MHR4<<"\n"<<endl;
  int max=MHR1;
  if (MHR2>max) {
    max=MHR2;
  }

  if (MHR3>max) {
    max=MHR3;
  }
  if (MHR4>max) {
    max=MHR4;
  }
  cout<<"Il massimo è : "<<max<<endl;

  return 0;
}
