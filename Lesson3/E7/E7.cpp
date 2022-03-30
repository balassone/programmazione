#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main(){
	string a{"*"};
	for (int i{0}; i<10; ++i){

		cout << a << endl;
		a.append("*");
	}
	for (int i{0}; i<10;++i){
		a.pop_back();
		cout << a << endl;

	}

	a="**********";
	cout << a << endl;
	for(int i{0}; i<9; ++i){
		a[i]=' ';
		cout << a << endl;

	}


	for(int i{9}; i>=0; --i){
		a[i]='*';
		cout << a << endl;
	}
	return 0;
}
