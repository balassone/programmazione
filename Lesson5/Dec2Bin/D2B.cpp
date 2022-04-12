#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int decToBin(int);

int main(){
	int a{0};
	cout << "Che numero vuoi convertire?: "; cin >> a;
	
	cout << "Il numero convertito e': " << decToBin(a) << endl;
	
	return 0;
}

int decToBin(int num){
	static unsigned int i{1};
	if (num==0){
		return 0;
	}
	i*=10;
	int r{num%2};
	return ((i/10)*r)+decToBin(num/=2);

}
