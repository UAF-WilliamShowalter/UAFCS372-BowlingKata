//
//  BowlingGame.h
//  Bowling Kata
//
//  Created by William Showalter on 2015/02/18.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef Bowling_Kata_BowlingGame_h
#define Bowling_Kata_BowlingGame_h
#include <vector>

/* Class invarients:
	addShot may not be called more than 21 times (number of shots in a game).
*/

class BowlingGame {
public:
	BowlingGame(){
	}
	const int score();
	void addShot (unsigned int pins);

private:
	std::vector <unsigned int> _shots;
};

#endif
