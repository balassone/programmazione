#include <cmath>
#include <iostream>

using std::cout;

int main(){
	
	for(int hypotenuse = 1; hypotenuse <= 500; hypotenuse++){
		
		for(int side1 = 1; side1<=500; side1++){
			
			for(int side2 = 1; side2<=500; side2++){
				
				if((pow(side1,2)+pow(side2,2))==pow(hypotenuse,2))
				{
					cout <<side1<<","<<side2<<","<<hypotenuse<<"\n";
				}
			}
		}
		
	}
	
}