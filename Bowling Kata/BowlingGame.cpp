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
	if (pins == STRIKE && !isLastFrameFull()) // second shot on frame with strike
		_shots.push_back(0);
}

const unsigned int BowlingGame::scoreFrame(unsigned int frameNumber){
	// Frame score is 0 if frame hasn't been shot yet.
	if (isFrameEmpty(frameNumber))
		return 0;

	auto frameScore = firstShotInFrame(frameNumber);

	if (isSpareOrStrike(frameNumber,frameScore) && notLastFrame(frameNumber)){
		frameScore += scoreStrikeNextShots(frameNumber);
	}

	else if (isLastFrameFull() || notLastFrame(frameNumber)){
		frameScore += nextShotsInFrame(frameNumber);
		if (isSpareOrStrike(frameNumber, frameScore) && notLastFrame(frameNumber))
			frameScore += scoreSpareNextShot(frameNumber);
	}

	return frameScore;
}

const unsigned int BowlingGame::scoreStrikeNextShots(unsigned int currentFrame){
	unsigned int frameScore = 0;

	if (isFrameEmpty(currentFrame+1) && !lastFrame(currentFrame))
		return frameScore;

	unsigned int firstShot = firstShotInFrame (currentFrame+1);

	frameScore += firstShot;

	if (firstShot == STRIKE){
		if (isFrameEmpty(currentFrame+2) && !afterLastFrame(currentFrame+2))
			return frameScore;
		frameScore += firstShotInFrame (currentFrame+2);
		return frameScore;
	}

	if (isLastFrameFull() || notLastFrame(currentFrame+1))
		frameScore += nextShotsInFrame(currentFrame+1);
	return frameScore;
}

const unsigned int BowlingGame::scoreSpareNextShot(unsigned int currentFrame){
	return firstShotInFrame(currentFrame+1);
}

const unsigned int BowlingGame::firstShotInFrame (unsigned int frameNumber){
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

const bool BowlingGame::isLastFrameFull (){
	return (!(_shots.size() % SHOTS_PER_FRAME));
}

const bool BowlingGame::isFrameEmpty (unsigned int currentFrame){
	if (FRAMES_PER_GAME <= currentFrame)
		return true;
	return (_shots.size() <= currentFrame * SHOTS_PER_FRAME);
}

const bool BowlingGame::notLastFrame (unsigned int currentFrame){
	return (_shots.size() - SHOTS_PER_FRAME > (currentFrame * SHOTS_PER_FRAME));
}

const bool BowlingGame::isSpareOrStrike(unsigned int currentFrame, unsigned int frameScore){
	return (frameScore == SPARE)||(frameScore == STRIKE);
}

const bool BowlingGame::afterLastFrame(unsigned int frameNumber){
	return !(frameNumber < FRAMES_PER_GAME);
}

const bool BowlingGame::lastFrame(unsigned int currentFrame){
	return (currentFrame+1 == FRAMES_PER_GAME);
}