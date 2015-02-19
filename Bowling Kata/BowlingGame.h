//
//  BowlingGame.h
//  Bowling Kata
//
//  Created by William Showalter on 2015/02/18.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef Bowling_Kata_BowlingGame_h
#define Bowling_Kata_BowlingGame_h

class BowlingGame {
public:
	BowlingGame(){
		_scoreTotal = 0;
	}
	const int score();
	void addShot (unsigned int pins);

private:
	unsigned int _scoreTotal;
};

#endif
