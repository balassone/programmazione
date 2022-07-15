//EncryptDecrypt 1
// Encrypting or decrypting a 4 digit number given in input by swapping the 1st with the 3rd number and the second with the 4th number
//then adding 7 to every digit and divide it by 10, taking the remainder for the encryption phase 
#include <iostream>
#include <stdlib.h>


using std::cin;
using std::cout;
using std::string;
using std::endl;

int digitSelection(int digit, int index); // gives a single digit of the sequence
void positioning(int digit, int array[]); // positions the digit in a 4 cell array
void encrypt(int array[]); // encrypting the digits
void decrypt(int array[]); // decrypting the digits
void swap(int &n1, int &n2); // swapping the digits inside the array
void print(int array[]); //printing the 4 digits during the process and when the process is over
int power(int base, int exp); //using a recursive power funtion for the encryption/decryption algorithm
int main(){ 
    int digit; //  the digit given in input
    int array[4]; // the array where the digit will be loaded
    int option = 0; // sentinel variable for the menu
    while(option != -1 || digit != -1){ //menu
        do{ //checking if the digit fiven in input is correct
            cout<<"insert a 4 digit number that you want to encrypt \n any value above or below 4 digit is invalid \n press -1 to quit ";
            cin >> digit;
        }while(digit>9999);//ckeck if the digit has less than 5 numbers
        if(digit == -1)break; // ends the program

        if(digit >999){ //checks if the digit has  more than 3 numbers. This because even -1 is a valid input
            do{
                cout <<"select an option \n press 1 to encrypt \n press 2 to decrypt \n press -1 to return back \n "; 
                cin >> option;
            }while(option <-1 || option >2); //checks if the options are correct
            if(option == -1) cout <<"\n "; //if the option is equal to -1 then the program goes back to the insertion stage
            else positioning(digit, array);
        }

        

        switch (option)
        {
        case 1: //encrypting
            encrypt(array);
            cout <<"the output number is ";
            print(array);
            break;
        
        case 2: //decrypting
            decrypt(array);
            cout <<"the output number is ";
            print(array);
            break;
        }

    } 
}

int power(int base, int exp){ //power function for the encrypting and decrypting funcions
    if(exp == 0)return 1;
    else
    return base * power(base, exp-1);
}
void swap(int &n1, int &n2){
    int change;
    change=n1;
    n1=n2;
    n2=change;
}
void positioning(int digit, int array[]){
    cout <<"the input number is ";
    for(int i=0; i<4;i++){
        array[i]=digitSelection(digit, i); //Select the first digit of the sequence
        cout<<array[i] <<" ";
    }
    cout <<"\n";
}
void encrypt(int array[]){
    cout << "encrypting the number ... \n";
    swap(array[1], array[3]);
    swap(array[0], array[2]);
     for(int i=0; i<4;i++){
        array[i]=(array[i]+7)%10; 
    }
}
void decrypt(int array[]){
    cout <<"decrypting the number ... \n";
    swap(array[1], array[3]);
    swap(array[0], array[2]);
    for(int i=0; i<4;i++){
        array[i]=((array[i]+3) %10);
    }
}
void print(int array[]){
    for (int i = 0; i < 4; i++)
    {
       cout << array[i]<<" ";
    }
    cout << "\n ";
    
}

int digitSelection(int digit, int index){
    int number;
    number = digit %power(10,4-index); //selects the sequence to be elaborate
    number = number / (power(10,3-index)); //gives the first character of the sequence
    return number;
}

