#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPalindrome(string A, int l, int r);

int main(){
	string a;
	cin >> a;
	cout << isPalindrome(a,0,a.length()-1);
	return 0;
}

bool isPalindrome(string A, int l, int r){

	if(r-l<=1){
		return true;
	}

	if(A[l]==A[r]){
		return isPalindrome(A,l+1,r-1);
	}
	else
		return false;

}
