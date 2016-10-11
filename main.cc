//
//  main.cc
//  CS2401Project7
//
//  Created by Aaron Robeson on 11/19/15.
//  Copyright © 2015 Aaron Robeson. All rights reserved.
//

#include <iostream>
#include "game.h"
#include "othello.h"


using namespace main_savitch_14;
using namespace std;

int main(int argc, const char * argv[]) {
    cout << endl << endl << endl << "You Are Playing as White" << endl << endl;
	othello myGame;
	myGame.play();
	if (myGame.winning() == 0) {
		cout << endl << "White Wins!" << endl;
	} else {
		cout << endl << "Black Wins!" << endl;
	}
    return 0;
}
