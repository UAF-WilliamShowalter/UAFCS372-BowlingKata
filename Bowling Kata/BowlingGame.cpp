//
//  BowlingGame.cpp
//  Bowling Kata
//
//  Created by William Showalter on 2015/02/18.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include <stdio.h>
#include "BowlingGame.h"

const unsigned int BowlingGame::score(){
	unsigned int scoreTotal = 0;
	for (auto frameNum = 0; frameNum < FRAMES_PER_GAME; frameNum++){
		scoreTotal += scoreFrame(frameNum);
	}
	return scoreTotal;
}

void BowlingGame::addShot(unsigned int pins){
	_shots.push_back(pins);
}

// Returns score of frame. Score is 0 if frame hasn't been shot yet.
// Doesn't score 3rd shot of 10th frame.
unsigned int BowlingGame::scoreFrame(unsigned int frameNumber){
	auto numberOfShotsTaken = _shots.size();

	if (numberOfShotsTaken <= frameNumber * SHOTS_PER_FRAME)
		return 0;

	// Has at least first shot
	auto frameScore = _shots[frameNumber*SHOTS_PER_FRAME];

	// All frames full
	if (!(numberOfShotsTaken % SHOTS_PER_FRAME)){
		for (size_t shotI = 1 + frameNumber*SHOTS_PER_FRAME;
			 shotI < frameNumber*SHOTS_PER_FRAME + SHOTS_PER_FRAME; shotI++){
			frameScore += _shots[shotI];
		}
	}

	return frameScore;
}