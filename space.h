//
//  space.h
//  CS2401Project7
//
//  Created by Aaron Robeson on 11/19/15.
//  Copyright © 2015 Aaron Robeson. All rights reserved.
//

#ifndef space_h
#define space_h

#include <stdio.h>

namespace main_savitch_14 {

class space {
public:
	
	enum color {empty, white, black};
	
	space() {spaceColor = empty;}
	
	color getColor() const {return spaceColor;}
	
	void setColor(color toSet) {
		spaceColor = toSet;
	}
	
	void flip() {
		if (spaceColor == black) {
			spaceColor = white;
		} else if (spaceColor == white) {
			spaceColor = black;
		}
	}

private:
	color spaceColor;
};
	
}

#endif /* space_h */
/*
	void setColor(char toSet) {
 if (toSet == 'w') {
 spaceColor = white;
 } else if (toSet == 'b') {
 spaceColor = black;
 } else if (toSet == 'e') {
 spaceColor = empty;
 }
	}
*/