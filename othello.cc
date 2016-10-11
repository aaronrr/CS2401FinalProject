//
//  othello.cc
//  CS2401Project7
//
//  Created by Aaron Robeson on 11/20/15.
//  Copyright © 2015 Aaron Robeson. All rights reserved.
//
	

#include "othello.h"
#include "colors.h"
#include <iostream>

using namespace std;

namespace main_savitch_14 {
	
othello::othello() {
	board[3][3].setColor(space::white);
	board[3][4].setColor(space::black);
	board[4][3].setColor(space::black);
	board[4][4].setColor(space::white);
}

void othello::restart() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x].setColor(space::empty);
		}
	}
	board[3][3].setColor(space::white);
	board[3][4].setColor(space::black);
	board[4][3].setColor(space::black);
	board[4][4].setColor(space::white);
	game::restart();
}
	
void othello::make_move(const std::string& move) {
	int y = 0;
	int x = (move[1] - '0') - 1;
		 if (move[0] == 'A' || move[0] == 'a') { y = 0; }
	else if (move[0] == 'B' || move[0] == 'b') { y = 1; }
	else if (move[0] == 'C' || move[0] == 'c') { y = 2; }
	else if (move[0] == 'D' || move[0] == 'd') { y = 3; }
	else if (move[0] == 'E' || move[0] == 'e') { y = 4; }
	else if (move[0] == 'F' || move[0] == 'f') { y = 5; }
	else if (move[0] == 'G' || move[0] == 'g') { y = 6; }
	else if (move[0] == 'H' || move[0] == 'h') { y = 7; }
	
	if (moves_completed() % 2 == 0) {
		// White
		board[y][x].setColor(space::white);
		checkForFlips(move, space::white);
	} else {
		// Black
		board[y][x].setColor(space::black);
		checkForFlips(move, space::black);
	}
	
	game::make_move(move);
}

void othello::display_status() const {
	cout << BOLD << "   1 2 3 4 5 6 7 8" << endl;
	for (int i = 0; i < 8; i++) {
		cout << BOLD;
		switch (i) {
			case 0:
				cout << "A ";
				break;
			case 1:
				cout << "B ";
				break;
			case 2:
				cout << "C ";
				break;
			case 3:
				cout << "D ";
				break;
			case 4:
				cout << "E ";
				break;
			case 5:
				cout << "F ";
				break;
			case 6:
				cout << "G ";
				break;
			case 7:
				cout << "H ";
				break;
		}
		cout << RESET;
		for (int j = 0; j < 8; j++) {
			if (board[i][j].getColor() == space::white) {
				cout << B_GREEN << WHITE << "|" << WHITE << "o";
			} else if (board[i][j].getColor() == space::black) {
				cout << B_GREEN << WHITE << "|" << BLACK << "x";
			} else {
				cout << RESET << B_GREEN << WHITE << "| ";
			}
		}
		cout << WHITE << B_GREEN << "|";
		cout << RESET << BOLD;
		switch (i) {
			case 0:
				cout << " A";
				break;
			case 1:
				cout << " B";
				break;
			case 2:
				cout << " C";
				break;
			case 3:
				cout << " D";
				break;
			case 4:
				cout << " E";
				break;
			case 5:
				cout << " F";
				break;
			case 6:
				cout << " G";
				break;
			case 7:
				cout << " H";
				break;
		}
		cout << RESET;
		cout << B_BLACK << endl;
	}
	cout << RESET << BOLD << "   1 2 3 4 5 6 7 8" << endl;
}

bool othello::is_legal(const std::string& move) const{
	
	space::color colorToFlipTo;
	if (moves_completed() % 2 == 0 ) {
		colorToFlipTo = space::white;
	} else {
		colorToFlipTo = space::black;
	}
	
	int y = 0;
	int x = (move[1] - '0') - 1;
	     if (move[0] == 'A' || move[0] == 'a') { y = 0; }
	else if (move[0] == 'B' || move[0] == 'b') { y = 1; }
	else if (move[0] == 'C' || move[0] == 'c') { y = 2; }
	else if (move[0] == 'D' || move[0] == 'd') { y = 3; }
	else if (move[0] == 'E' || move[0] == 'e') { y = 4; }
	else if (move[0] == 'F' || move[0] == 'f') { y = 5; }
	else if (move[0] == 'G' || move[0] == 'g') { y = 6; }
	else if (move[0] == 'H' || move[0] == 'h') { y = 7; }
	
	if (y < 8 && y >= 0 && x < 8 && x >= 0 && board[y][x].getColor() == space::empty) {
		// check up
		if (!(board[y-1][x].getColor() == space::empty || board[y-1][x].getColor() == colorToFlipTo)) {
			for (int i = y-2; i >= 0 ; i--) {
				if (board[i][x].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check up/right
		if (!(board[y-1][x+1].getColor() == space::empty || board[y-1][x+1].getColor() == colorToFlipTo)) {
			for (int i = y-2, j = x+2; i >= 0 && j < 8; i--, j++) {
				if (board[i][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check right
		if (!(board[y][x+1].getColor() == space::empty || board[y][x+1].getColor() == colorToFlipTo)) {
			for (int j = x+2; j < 8 ; j++) {
				if (board[y][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check right/down
		if (!(board[y+1][x+1].getColor() == space::empty || board[y+1][x+1].getColor() == colorToFlipTo)) {
			for (int i = y+2, j = x+2; i < 8 && j < 8; i++, j++) {
				if (board[i][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check down
		if (!(board[y+1][x].getColor() == space::empty  || board[y+1][x].getColor() == colorToFlipTo)) {
			for (int i = y+2; i < 8 ; i++) {
				if (board[i][x].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check down/left
		if (!(board[y+1][x-1].getColor() == space::empty  || board[y+1][x-1].getColor() == colorToFlipTo)) {
			for (int i = y+2, j = x-2; i < 8 && j >= 0; i++, j--) {
				if (board[i][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check left
		if (!(board[y][x-1].getColor() == space::empty  || board[y][x-1].getColor() == colorToFlipTo)) {
			for (int j = x-2; j >= 0 ; j--) {
				if (board[y][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
		
		// check left/up
		if (!(board[y-1][x-1].getColor() == space::empty || board[y-1][x-1].getColor() == colorToFlipTo)) {
			for (int i = y-2, j = x-2; i >= 0 && j >= 0; i--, j--) {
				if (board[i][j].getColor() == colorToFlipTo) {
					return true;
				}
			}
		}
	}
	return false;
}

void othello::checkForFlips(const std::string &move, space::color colorToFlipTo) {
	int y = 0;
	int x = (move[1] - '0') - 1;
	     if (move[0] == 'A' || move[0] == 'a') { y = 0; }
	else if (move[0] == 'B' || move[0] == 'b') { y = 1; }
	else if (move[0] == 'C' || move[0] == 'c') { y = 2; }
	else if (move[0] == 'D' || move[0] == 'd') { y = 3; }
	else if (move[0] == 'E' || move[0] == 'e') { y = 4; }
	else if (move[0] == 'F' || move[0] == 'f') { y = 5; }
	else if (move[0] == 'G' || move[0] == 'g') { y = 6; }
	else if (move[0] == 'H' || move[0] == 'h') { y = 7; }
	
	// check up
	if (board[y-1][x].getColor() != space::empty && board[y-1][x].getColor() != colorToFlipTo) {
		for (int i = y-1; i >= 0 ; i--) {
			if (board[i][x].getColor() == colorToFlipTo) {
				// flip between [y,x] and [i,x]
				for (int k = y-1; k > i ; k--) {
					board[k][x].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check up/right
	if (board[y-1][x+1].getColor() != space::empty && board[y-1][x+1].getColor() != colorToFlipTo) {
		for (int i = y-1, j = x+1; i >= 0 && j < 8; i--, j++) {
			if (board[i][j].getColor() == colorToFlipTo) {
				// flip diagonally between [y,x] and [i,j]
				for (int k = y-1, l = x+1; k > i && l < j; k--, l++) {
					board[k][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check right
	if (board[y][x+1].getColor() != space::empty && board[y][x+1].getColor() != colorToFlipTo) {
		for (int j = x+1; j < 8 ; j++) {
			if (board[y][j].getColor() == colorToFlipTo) {
				// flip between [y,x] and [y,j]
				for (int l = x+1; l < j ; l++) {
					board[y][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check right/down
	if (board[y+1][x+1].getColor() != space::empty && board[y+1][x+1].getColor() != colorToFlipTo) {
		for (int i = y+1, j = x+1; i < 8 && j < 8; i++, j++) {
			if (board[i][j].getColor() == colorToFlipTo) {
				// flip diagonally between [y,x] and [i,j]
				for (int l = x+1, k = y+1; l < j && k < i; l++, k++) {
					board[k][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check down
	if (board[y+1][x].getColor() != space::empty && board[y+1][x].getColor() != colorToFlipTo) {
		for (int i = y+1; i < 8 ; i++) {
			if (board[i][x].getColor() == colorToFlipTo) {
				// flip between [y,x] and [i,x]
				for (int k = y+1; k < i ; k++) {
					board[k][x].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check down/left
	if (board[y+1][x-1].getColor() != space::empty && board[y+1][x-1].getColor() != colorToFlipTo) {
		for (int i = y+1, j = x-1; i < 8 && j >= 0; i++, j--) {
			if (board[i][j].getColor() == colorToFlipTo) {
				// flip diagonally between [y,x] and [i,j]
				for (int k = y+1, l = x-1; k < i && l > j ; k++, l--) {
					board[k][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check left
	if (board[y][x-1].getColor() != space::empty && board[y][x-1].getColor() != colorToFlipTo) {
		for (int j = x-1; j >= 0 ; j--) {
			if (board[y][j].getColor() == colorToFlipTo) {
				// flip between [y,x] and [y,j]
				for (int l = x-1; l > j ; l--) {
					board[y][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
	
	// check left/up
	if (board[y-1][x-1].getColor() != space::empty && board[y-1][x-1].getColor() != colorToFlipTo) {
		for (int i = y-1, j = x-1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j].getColor() == colorToFlipTo) {
				// flip diagonally between [y,x] and [i,j]
				for (int l = x-1, k = y-1; l > j && k > i ; l--, k--) {
					board[k][l].setColor(colorToFlipTo);
				}
				break;
			}
		}
	}
}

bool othello::is_game_over() const {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x].getColor() == space::empty) {
				return false;
			}
		}
	}
	return true;
}

bool othello::playerHasLegalmoves() const {
	string moveString;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			moveString = 'a' + y;
			moveString += '0' + x;
			if (is_legal(moveString)) {
				return true;
			}
		}
	}
	return false;
}
	
game::who othello::winning() const {
	int whiteCount = 0, blackCount = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x].getColor() == space::white) {
				whiteCount++;
			} else if (board[y][x].getColor() == space::black) {
				blackCount++;
			}
		}
	}
	if (whiteCount > blackCount) {
		return HUMAN;
	} else {
		return COMPUTER;
	}
}
	
void othello::compute_moves(std::queue<std::string>& moves) const {
	string move("  ");
	move[0] = 'A';
	move[1] = '1';
	while (move[1] != '9') {
		move[0] = 'A';
		while (move[0] != 'I') {
			if (is_legal(move)) {
				moves.push(move);
			}
			move[0]++;
		}
		move[1]++;
	}
}
	
int othello::evaluate() const {	// Positive values are good for the computer.
	int whiteValue = 0, blackValue = 0;
	
	// Value by count
	int value;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			value = 1;
			if (x == 0 || x == 7) {
				value += 3;
			}
			if (y ==  0 || y == 7) {
				value += 3;
			}
			if (board[y][x].getColor() == space::white) {
				whiteValue += value;
			} else if (board[y][x].getColor() == space::black) {
				blackValue += value;
			}
		}
	}
	
	return blackValue - whiteValue;
}
	
}





