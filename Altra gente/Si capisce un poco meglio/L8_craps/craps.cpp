//craps.cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
using std::cout;
using std::endl;

unsigned int rollDice(); //funzione che fa rotolare il dado, calcola e mostra la somma

int main() {
    enum class Status {CONTINUE, WON, LOST};

    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0};
    Status gameStatus;
    unsigned int sumOfDice{rollDice()};

    switch(sumOfDice){
        case 7:
        case 11:
            gameStatus=Status::WON;
            break;
        default:
            gameStatus=Status::CONTINUE;
            myPoint=sumOfDice;
            cout<<"Point is "<<myPoint<<endl;
            break;
    }

    while(Status::CONTINUE == gameStatus) {
        sumOfDice = rollDice();
        
    
        if(sumOfDice == myPoint) {
            gameStatus=Status::WON;
        }
        else  {
        
            if (sumOfDice==7) {
                gameStatus=Status::LOST;
            }
        }
    }

    if (Status::WON == gameStatus) {
        cout<<"Player wins"<<endl;
    }


    else{
        cout<<"Player loses"<<endl;
    }
}

//rollDice, funzione

unsigned int rollDice(){
    int die1(1+rand()%6);
    int die2(1+rand()%6);

    int sum{die1+die2};

    cout<<"Player rolled "<<die1<<" + "<<die2<<" = "<<sum<<endl;
    return sum;
}