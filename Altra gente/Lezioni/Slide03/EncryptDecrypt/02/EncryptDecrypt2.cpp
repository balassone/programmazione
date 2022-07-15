#include <iostream>
#include <stdlib.h>
#include <math.h>

using std::cin;
using std::cout;
using std::string;
using std::endl;

void positioning(int array[]);
void encrypt(int array[]);
void decrypt(int array[]);
void swap(int &n1, int &n2);
void print(int array[]);

int main(){
    int array[4];
    int option = 0;
    while(option != -1){
        do{
            cout <<"*******MENU******* \n select an option \n press 1 to encrypt \n press 2 to decrypt \n press -1 to quit \n ";
            cin >> option;
        }while(option <-1 || option >2);
        
        switch (option)
        {
        case 1:
            positioning(array);
            encrypt(array);
            cout <<"the output number is ";
            print(array);
            break;
        
        case 2:
            positioning(array);
            decrypt(array);
            cout <<"the output number is ";
            print(array);
            break;

        default:
            cout <<"exiting... ";
        }
        

    } 
}

int power(int base, int exp){
    if(exp == 0)return 1;
    else
    return base * pow(base, exp-1);
}
void swap(int &n1, int &n2){
    int change;
    change=n1;
    n1=n2;
    n2=change;
}
void positioning(int array[]){
    for(int i=0; i<4;i++){
        cout <<"inserting the " <<i<<" digit ";
        cin >> array[i];
    }
    cout << "the input number is ";
    print(array);
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

