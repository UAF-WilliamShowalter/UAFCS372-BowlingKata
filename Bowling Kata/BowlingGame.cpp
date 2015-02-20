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
		auto thisFrame = scoreFrame(frameNum);
		scoreTotal += thisFrame;
	}
	return scoreTotal;
}

void BowlingGame::addShot(unsigned int pins){
	_shots.push_back(pins);
	if (pins == STRIKE && !isFrameFull())
		_shots.push_back(0);
}

// Returns score of frame. Score is 0 if frame hasn't been shot yet.
// Doesn't score 3rd shot of 10th frame.
const unsigned int BowlingGame::scoreFrame(unsigned int frameNumber){
	if (isFrameEmpty(frameNumber))
		return 0;

	auto frameScore = firstShotFrame(frameNumber);

	if (frameScore == STRIKE)
		frameScore += scoreFrame(frameNumber+1);

	else if (isFrameFull() || shotsNextFrame(frameNumber)){
		frameScore += nextShotsInFrame(frameNumber);
		if (isSpare(frameNumber, frameScore))
			frameScore += firstShotFrame(frameNumber+1);
	}

	return frameScore;
}

const bool BowlingGame::isFrameFull (){
	return (!(_shots.size() % SHOTS_PER_FRAME));
}

const bool BowlingGame::isFrameEmpty (unsigned int currentFrame){
	if (FRAMES_PER_GAME <= currentFrame)
		return true;
	return (_shots.size() <= currentFrame * SHOTS_PER_FRAME);
}

const bool BowlingGame::shotsNextFrame (unsigned int currentFrame){
	return (_shots.size() - SHOTS_PER_FRAME > (currentFrame * SHOTS_PER_FRAME));
}

const unsigned int BowlingGame::firstShotFrame (unsigned int frameNumber){
	return _shots[frameNumber*SHOTS_PER_FRAME];
}

const unsigned int BowlingGame::nextShotsInFrame (unsigned int frameNumber){
	unsigned int frameScore = 0;
	for (size_t shotI = 1 + frameNumber*SHOTS_PER_FRAME;
		 shotI < frameNumber*SHOTS_PER_FRAME + SHOTS_PER_FRAME; shotI++){
		frameScore += _shots[shotI];
	}
	return frameScore;
}

const bool BowlingGame::isSpare(unsigned int currentFrame, unsigned int frameScore){
	return (frameScore == SPARE && _shots.size() > ((currentFrame+1)*SHOTS_PER_FRAME));
}