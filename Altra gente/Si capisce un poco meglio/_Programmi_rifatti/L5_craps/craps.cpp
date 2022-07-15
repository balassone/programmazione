//craps.cpp
#include<cstdlib> //for rand and srand
#include<ctime>   //for function time, useful to randomize the generator of random numbers
#include<iostream>
using std::cout; using std::cin; using std::endl;

unsigned int rollDice();

int main() {
    enum class Status {WON, CONTINUE, LOST};

    //randomize random number generator using current time from 1/1/1970
    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0};
    Status gameStatus;
    unsigned int sumOfDice{rollDice()};
    
    //first roll:
    switch(sumOfDice){
        case 7:
        case 11:
            gameStatus= Status :: WON;
            break;

        case 2:
        case 3:
        case 12:
            gameStatus= Status::LOST;
            break;

        default:
            gameStatus = Status::CONTINUE;
            myPoint=sumOfDice;
            cout<<"Point is "<<myPoint<<endl;
            break;
        }
        
        while (gameStatus == Status::CONTINUE) {
            sumOfDice = rollDice();
            if (sumOfDice==myPoint){
                gameStatus = Status::WON;
                break;
            }
            else {
                if (sumOfDice == 7){
                    gameStatus= Status::LOST;
                }
            }
        }
    if (gameStatus == Status::WON) {
        cout<<"Player wins! :)"<<endl;
    }
    else {
        cout<<"Player lost! :("<<endl;
    }
}

//roll dice, calculates sum and display result
unsigned int rollDice() {
    int die1{1+rand()%6};
    int die2{1+rand()%6};
    int sum= die1+die2;

    cout<<"Player rolled "<<die1<<" + "<<die2<<" = "<<sum<<endl;
    
    return sum;
}