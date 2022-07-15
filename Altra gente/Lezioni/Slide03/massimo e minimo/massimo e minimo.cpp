#include <iostream>

using std::cout;
using std::cin;

int main(){

    int number,maximum{0},minimum{0};
    cout<<"------------------------------"
        <<"\ninsert a number"
            <<"\n use 0 end the program \n";
    cin>>number;
    maximum = number;
    minimum = number;
    
	while(number != 0){
        cout<<"------------------------------"
            <<"\ninsert a number"
                <<"\n use 0 end the program \n";
        cin>>number;
		if(number > maximum){
			maximum = number;
		}
		if(number < minimum && number != 0)
		{
            minimum = number;
		}
    }
		cout <<"\n ************************************ \n The maximum number of the sequence is "<<maximum<<"\n the minimum number of the sequence is "<<minimum;
}
