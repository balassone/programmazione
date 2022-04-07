#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int fibo(const int&);

int main(){
	int x;
	do{
		cin >> x;
	}while(x<=0);
	cout << endl << fibo(x);
	return 0;
}

int fibo(const int& num){
	if (num==0)
		return 0;
	if(num==1)
		return 1;
	else{
		return fibo(num-1)+fibo(num-2);
	}	

}
