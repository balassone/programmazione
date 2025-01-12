// Craps.cpp
// Craps simulation 
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
using std::cout;
using std::endl;

unsigned int rollDice(); // rolls dice, calculates and displays sum

int main(){
    //scoped enumeration with constants that represent the game status
    enum class Status {CONTINUE, WON, LOST}; // all craps in constants
    
    // randomize random number generator using current time 
    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0}; // point if no win or loss on first roll
    Status gameStatus; // can be CONTINUE, WIN or LOST
    unsigned int sumOfDice{rollDice()}; // first roll of the dice

    // determine game status and point (if needed) based on first roll
    switch (sumOfDice)
    {
    case 7: // win with 7 on the first roll
    case 11: // win with 11 on the first roll
        gameStatus = Status::WON;
        break;
    case 2: // lose with 2 on the first roll
    case 3: // lose with 3 on the first roll
    case 12: // lose with 12 on the first roll
        gameStatus = Status::LOST;
        break;
    default: // did not win or lose, so remember point
        gameStatus = Status::CONTINUE; // game is not over
        myPoint = sumOfDice; // remember the point
        cout << "Point is " << myPoint << endl;
        break; // optional at the end of the switck
    }

    //while game is not complete
    while (Status::CONTINUE == gameStatus) // not WON or LOST
    {
        sumOfDice = rollDice(); // roll dice again

        //determine game status
        if(sumOfDice == myPoint){ // win by making point
            gameStatus = Status::WON;
        }
        else{
            if(sumOfDice == 7){ // lose by rolling 7 before point
                gameStatus = Status::LOST;
            }
        }
    }
    if (Status::WON == gameStatus){
        cout << "Player wins" << endl;
    }
    else
    {
        cout << "Player loses" << endl;
    }
}

// roll dice, calculate sum and display results
unsigned int rollDice(){
    int die1{1+rand()% 6 }; // first die roll
    int die2{1+rand()% 6 }; // second die roll
    int sum {die1 + die2}; // compue sum of die values

    //display results of this roll
    cout << "Player rolled " << die1 << " + "<< die2 
    << " = " << sum << endl;

    return sum;
}

