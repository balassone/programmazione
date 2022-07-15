#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
	float height;
	int weight;
	
	
	
	cout<<"insert the height \n";
	cin>>height;
	cout<<"insert the weight \n";
	cin>>weight;
	
	float BMI=float(weight)/(height*height);
	cout<<"your BMI is "<<BMI<<"\n";
	return 0;
}
