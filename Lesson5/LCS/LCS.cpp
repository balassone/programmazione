#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T>

const T& max (const T& a, const T& b){
	return (a>b) ? a : b;
}

int lcs(string a, string b, int dima, int dimb){
	if (dima==0 || dimb==0){
		return 0;
	}
	if(a[dima-1]==b[dimb-1]){
		return (1+lcs(a,b,dima-1,dimb-1));
	}
	else{
		return max(lcs(a,b,dima,dimb-1),lcs(a,b,dima-1,dimb));
	}
}

int main(){
	string a{"ALBERTO"}, b{"ALTO"};

	cout << lcs(a,b,a.length(),b.length()) << endl;
	return 0;
}
