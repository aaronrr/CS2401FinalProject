//
//  othello.h
//  CS2401Project7
//
//  Created by Aaron Robeson on 11/20/15.
//  Copyright © 2015 Aaron Robeson. All rights reserved.
//

#ifndef othello_h
#define othello_h

#include "game.h"
#include "space.h"

namespace main_savitch_14 {

class othello : public game {
public:
	
	othello();
	
	// Restart the game from the beginning:
	void restart();
	// Have the next player make a specified move:
	void make_move(const std::string& move);
	// Display the status of the current game:
	void display_status() const;
	// Return true if the given move is legal for the next player:
	bool is_legal(const std::string& move) const;
	// Return true if the game is over
	bool is_game_over() const;
	// Check if player has legal moves
	bool playerHasLegalmoves() const;
	// return the player with the most pieces
	who winning() const;
	// Return a pointer to a copy of myself:
	game* clone() const {
		return new othello(*this);
	}
	// Compute all the moves that the next player can make:
	void compute_moves(std::queue<std::string>& moves) const;
	// Positive values are good for the computer.
	int evaluate( ) const;
	
private:
	void checkForFlips(const std::string &move, space::color colorToFlipTo);
	space board[8][8];
};

}

#endif /* othello_h */
