//TicTacToe.cpp
// Member-function definitions for class TicTacToe.
#include <iostream>
#include <iomanip>
#include "TicTacToe.h" // include definition of class TicTacToe
using std::cout;
using std::cin;
using std::setw;
TicTacToe::TicTacToe() {
	for (int j{0}; j<3; ++j) { //initialize board
		for (int k{0}; k<3; ++k) {
			board[j][k] = ' ';
		}
	}
}
bool TicTacToe::validMove(int r, int c ) const {
	return r>= 0 && r <3 && c>= 0 && c<=3 && board[r][c] == ' ';
}

// must specify that type Status is part of the TicTacToe class
TicTacToe::Status TicTacToe::gameStatus() const {
	//check for a win on diagonals
	if (board [0][0] != ' ' && board[0][0] == board[1][1] && board [0][0] == board[2][2])
		{return WIN;}
	else if (board[2][0] != ' ' && board[2][0] == board [1][1] && board[2][0] == board[0][2])
		{return WIN;}


	// check for win in rows
	for (int a{0}; a<3; ++a){
		if(board[a][0] != ' ' && board[a][0] == board[a][1] && board[a][0] == board[a][2])
			{return WIN; }
	}
	
		
	// check for win in columns
	for (int a{0}; a<3; ++a){
		if(board[0][a] != ' ' && board[0][a] == board[1][a] && board[0][a] == board[2][a])
			{return WIN; }
	}
	
	// check for a completed game
	for (int r{0}; r<3; r++) {
		for (int c{0}; c<3; c++) {
			if(board[r][c] == ' ' ) {
				return CONTINUE; // game is not finished
			}
		}
	}
	return DRAW; 	// game is a draw
}

void TicTacToe::printBoard() const {
	cout << "   0    1    2\n\n";
	
	for(int r{0}; r<3; ++r) {
		cout << r;
		
		for (int c{0}; c< 3; ++c) {
			cout << setw(3) << board [r][c];
			
			if (c!= 2) {
				cout << " |";
			}
		}
		
		if (r!= 2) {
			cout << "\n ____|____|____\n     |    |     \n";
		}
	}
	cout << "\n\n";
}

void TicTacToe::makeMove() {
	printBoard();
	
	while (true) {
		if (xoMove('X')) {
			break;
		}
		else if(xoMove('O')){
			break;
		}
	}
}

bool TicTacToe::xoMove(char Player) {
	int x;
	int y;
	
	do{
		cout << "Player " << Player << " enter move: ";
		cin >> x >> y;
		cout << '\n';
	}while(!validMove(x, y));
	
	board[x][y] = Player;
	printBoard();
	Status xoStatus = gameStatus();
	
	if (xoStatus == WIN) {
		cout << "Player " << Player << " wins ! \n";
		return true;
	}
	else if (xoStatus == DRAW) {
		cout << "Game is a draw.\n";
		return true;
	}
	else { // xoStatus = CONTINUE
		return false;
	}
}