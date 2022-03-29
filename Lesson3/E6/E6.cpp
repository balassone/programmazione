#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int encrypt(int num){

	int i{1000};
	int temp;
	int newnum{0};
	while(i!=0){
		temp=num/i;
		num-=(temp*i);
		temp+=7;
		temp=(temp%10);
		newnum+=temp*i;
		i/=10;
	}
	i=1000;
	while(i!=0){
	
		temp=newnum/i;
		newnum-=(temp*i);
		if(i>10){
			num+=temp*(i/100);
		}
		else {
			num+=temp*(i*100);
		}
		i/=10;

	}

	return num;
}

int decrypt(int num){

	int i{1000};
	int temp;
	int newnum{0};

	while(i!=0){

		temp=num/i;
		num-=(temp*i);
		if(i>10){
			newnum+=temp*(i/100);
		}
		else {
			newnum+=temp*(i*100);
		}
		i/=10;

	}

	i=1000;
	while(i!=0){

		temp=newnum/i;
		newnum-=temp*i;
		temp+=10;
		temp-=7;
		if(temp>=10) temp-=10;
		num+=temp*i;
		i/=10;

	}
	return num;
}

int main(){

	int num{0};
	char choice;

	do{
		cout << "Give me the number: ";
		cin >> num;
	} while (num>9999);

	do{
		cout << "Encrypt (e), Decrypt (d): ";
		cin >> choice;
	} while (choice != 'e' && choice != 'd');

	switch(choice){
		case 'e':
			cout << "Encrypted: " << encrypt(num) << endl;
			break;
		case 'd':
			cout << "Decrypted: " << decrypt(num) << endl;
			break;
		default:
			break;
	}
	return 0;
}
