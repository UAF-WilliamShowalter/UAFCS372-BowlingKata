//
//  BowlingGame.cpp
//  Bowling Kata
//
//  Created by William Showalter on 2015/02/18.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include <stdio.h>
#include "BowlingGame.h"

const int BowlingGame::score(){
	unsigned int scoreTotal = 0;
	for (auto shot : _shots){
		scoreTotal += shot;
	}
	return scoreTotal;
}

void BowlingGame::addShot(unsigned int pins){
	_shots.push_back(pins);
}