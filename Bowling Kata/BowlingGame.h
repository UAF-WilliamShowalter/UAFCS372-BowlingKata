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
#include <cstdlib> // for size_t

using std::size_t;

// Bowling Constants
const unsigned int STRIKE = 10;
const unsigned int SPARE = 10;
const unsigned int SHOTS_PER_FRAME = 2;
const unsigned int FRAMES_PER_GAME = 10;

/* Class invarients:
	addShot may not be called more than 21 times (number of shots in a game).
*/

class BowlingGame {
public:
	BowlingGame(){}

	const unsigned int score();
	void addShot (unsigned int pins);

public:
	const unsigned int scoreFrame(unsigned int frameNumber);

private:
	const bool isFrameFull ();
	const bool isFrameEmpty (unsigned int currentFrame);
	const bool shotsNextFrame (unsigned int currentFrame);
	
	const unsigned int firstShotInFrame (unsigned int frameNumber);
	const unsigned int nextShotsInFrame (unsigned int frameNumber);
	const unsigned int scoreStrikeNextShots (unsigned int currentFrame);
	const bool isSpare(unsigned int currentFrame, unsigned int frameScore);
	const bool isStrike(unsigned int currentFrame, unsigned int frameScore);
	const bool afterLastFrame(unsigned int frameNumber);
	const bool lastFrame(unsigned int currentFrame);


private:
	std::vector <unsigned int> _shots;
};

#endif
