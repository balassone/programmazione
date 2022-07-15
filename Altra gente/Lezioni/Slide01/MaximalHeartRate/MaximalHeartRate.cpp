#include <iostream> 
using std::cin;
using std::cout;

int main(){
	int age; //age input 
	int min,max; //range of maximal heart rates
	int hr1,hr2,hr3,hr4; //heart rates 
	//input
	cout <<"insert age: ";
	cin >>age; 
	//common equation
	hr1 = 220 - age;
	min=hr1;
	max=hr1;
	cout <<"Maximal Heart Rate using common equation: "<<hr1;
	//Tanka equation
	hr2 = 208 - 0.7*(float(age));
	if(hr2>max)
	{
		max = hr2;
	}
	if(hr2 < min){
		min = hr2;
	}
	cout <<"\nMaximal Hear Rate using Tanaka equation: "<<hr2;
	//Gellish Equation
	hr3 = 207 - 0.7*(float(age));
	if(hr3>max)
	{
		max = hr3;
	}
	if(hr3 < min){
		min = hr3;
	}
	cout <<"\nMaximal Hear Rate using Gellish equation: "<<hr3;
	//Nes Equation
	hr4 = 211-0.64*(float(age));
	if(hr4>max)
	{
		max = hr4;
	}
	if(hr4 < min){
		min = hr4;
	}
	cout <<"\nMaximal Hear Rate using Nes equation: "<<hr4;
	
	cout <<"\n It's reccomended to have a maximal heart rate between "<<min <<" and "<<max;
	
	
}