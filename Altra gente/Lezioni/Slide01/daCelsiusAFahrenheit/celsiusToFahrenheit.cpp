#include <iostream>
using std::cin;
using std::cout;

int main(){
	//var declaration and input
    float temperature{0};
    char scale;
	
	cout<<"insert the value of the temperature \n";
    cin>>temperature;
	cout<<"insert the scale of the temperature entered \n" 
		"Press f for Fahrenheit \n"
		"Press c for Celsius \n";
	cin>>scale;
	
	//if- input control
    if (scale=='c' || scale == 'C') {
		cout<<"converting to Fahrenheit \n";		//celsius to fahrenheit
        temperature=(temperature*(9/5)+32);
		scale = 'F';			//assigning the character of the output scale
    }
    else if (scale == 'f' || scale == 'F'){
		cout<<"converting to Celsius \n";		//fahrenheit to celsius
        temperature = (temperature-32)*(5/9);
		scale = 'C';
	}
    else{
        cout<<"error ";		//wrong input: close the program. better handling with do-while
        return 1;
    }
    cout <<"the temperature is "<<temperature <<scale <<"°";
    return 0;
}
