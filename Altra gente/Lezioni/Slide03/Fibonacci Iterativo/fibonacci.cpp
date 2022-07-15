#include <iostream>

using std::cout;
int main(){
int number{0};
int nextNumber{1};
int thirdNumber{0};
cout<<number<<" , "<<nextNumber<<" , ";
while(thirdNumber < 22){
	thirdNumber=number+nextNumber;
	cout<<thirdNumber<<" , ";
	number=nextNumber;
	nextNumber=thirdNumber;
	
	
	
}
}