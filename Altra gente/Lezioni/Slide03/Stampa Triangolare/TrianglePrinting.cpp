#include<iostream>
using std::cout;

int main(){
	int temp; //temp allows us to print the * character based on the for counter
	int temp2; //temp2 allows us to print the blank character based on the for counter
	for(int i=0; i<10; i++){
		temp = i;
		while(temp >= 0){
			cout<<"*";
			temp--;
		}
		cout<<"\n";
	}
	for(int i=10; i>0; i--){
		temp = i;
		while(temp > 0){
			cout<<"*";
			temp--;
		}
		cout<<"\n";
	}
	for(int i=10; i>0; i--){
		temp = i;
		temp2 = 9-i;
		while(temp2 >= 0){
			cout<<" ";
			temp2--;
		}
		while(temp > 0){
			cout<<"*";
			temp--;
		}
		cout<<"\n";
	}
	for(int i=0; i<10; i++){
		temp = i;
		temp2 = 9-i;
		while(temp2 > 0){
			cout<<" ";
			temp2--;
		}
		while(temp >= 0){
			cout<<"*";
			temp--;
		}
		cout<<"\n";
	}
	
}