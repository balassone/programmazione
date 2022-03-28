#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){

	int num{0};
	cin >> num;

	int a=num/10000;
	num-=a;
	if(num%10==0){
		num-=(a*10000);
		num/=10;
		a=num/100;
		num-=a;
		if(num%10==0){
			cout << "Palindromo!" << endl;
		}else cout << "Non palindromo!" << endl;
	}
	else cout << "Non palindromo!" << endl;




	return 0;
}
