//  Created by William Showalter on 2015/02/18.
//	TDD Bowling Kata for CS 372

// Include Catch library for testing - using Catch's main.
#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"

#include "BowlingGame.h"

TEST_CASE("Scores a game of bowling.", "BowlingGame")
{
	SECTION("BowlingGame class trivial"){
		BowlingGame gameT;

		REQUIRE(gameT.score() == 0);

		// First frame - 9 pins, open
		gameT.addShot(1);
		REQUIRE(gameT.score() == 1);
		gameT.addShot(8);
		REQUIRE(gameT.score() == 9);

		// Second frame - 9 pins, open
		gameT.addShot(5);
		gameT.addShot(4);
		REQUIRE(gameT.score() == 18);
	}

	SECTION("BowlingGame class spare"){
		BowlingGame gameT;

		REQUIRE(gameT.score() == 0);

		// First frame - spare
		gameT.addShot(1);
		REQUIRE(gameT.score() == 1);
		gameT.addShot(9);
		REQUIRE(gameT.score() == 10);

		// Second frame - after spare
		gameT.addShot(5);
		REQUIRE(gameT.score() == 20);
		gameT.addShot(4);
		REQUIRE(gameT.score() == 24);
	}

	SECTION("BowlingGame class strike"){
		BowlingGame gameT;

		REQUIRE(gameT.score() == 0);

		// First frame - 8 pins, open
		gameT.addShot(5);
		REQUIRE(gameT.score() == 5);
		gameT.addShot(3);
		REQUIRE(gameT.score() == 8);

		// Second frame - 8 pins, open
		gameT.addShot(2);
		REQUIRE(gameT.score() == 10);
		gameT.addShot(6);
		REQUIRE(gameT.score() == 16);

		// Third frame - strike
		gameT.addShot(10);
		REQUIRE(gameT.score() == 26);

		// Fourth frame - 8 pins, open
		gameT.addShot(6);
		REQUIRE(gameT.score() == 38);
		gameT.addShot(2);
		REQUIRE(gameT.score() == 42);

		// Fifth frame - 1st strike in row
		gameT.addShot(10);
		REQUIRE(gameT.score() == 52);

		// Sixth frame - 2nd strike in row
		gameT.addShot(10);
		REQUIRE(gameT.score() == 72);

		// Seventh frame - 3rd strike in row
		gameT.addShot(10);
		REQUIRE(gameT.score() == 102);

		// Eighth frame - 8 pins, open
		gameT.addShot(5);
		REQUIRE(gameT.score() == 122);
		gameT.addShot(3);
		REQUIRE(gameT.score() == 134);

		// Nineth frame - 8 pins, open
		gameT.addShot(2);
		REQUIRE(gameT.score() == 136);
		gameT.addShot(6);
		REQUIRE(gameT.score() == 142);

		// Tenth frame - 8 pins, open
		gameT.addShot(5);
		REQUIRE(gameT.score() == 147);
		gameT.addShot(3);
		REQUIRE(gameT.score() == 150);

		// 11th frame - off board - shouldn't score more
		gameT.addShot(2);
		REQUIRE(gameT.score() == 150);
		gameT.addShot(6);
		REQUIRE(gameT.score() == 150);
	}

	SECTION("BowlingGame class check frame"){
		BowlingGame gameT;

		REQUIRE(gameT.score() == 0);

		// First frame - 8 pins, open
		gameT.addShot(5);
		gameT.addShot(3);
		// Second frame - 8 pins, open
		gameT.addShot(2);
		gameT.addShot(6);
		// Third frame - strike
		gameT.addShot(10);
		// Fourth frame - 8 pins, open
		gameT.addShot(6);
		gameT.addShot(2);
		// Fifth frame - 1st strike in row
		gameT.addShot(10);
		// Sixth frame - 2nd strike in row
		gameT.addShot(10);
		// Seventh frame - 3rd strike in row
		gameT.addShot(10);
		// Eighth frame - 8 pins, open
		gameT.addShot(5);
		gameT.addShot(3);
		// Nineth frame - 8 pins, open
		gameT.addShot(2);
		gameT.addShot(6);
		// Tenth frame - 8 pins, open
		gameT.addShot(5);
		gameT.addShot(3);
		// 11th frame - off board - shouldn't score more
		gameT.addShot(2);
		gameT.addShot(6);

		// ZERO INDEXED FRAMES
		REQUIRE(gameT.scoreFrame(0) == 8);
		REQUIRE(gameT.scoreFrame(1) == 8);
		REQUIRE(gameT.scoreFrame(2) == 18);
		REQUIRE(gameT.scoreFrame(3) == 8);
		REQUIRE(gameT.scoreFrame(4) == 38);
		REQUIRE(gameT.scoreFrame(5) == 28);
		REQUIRE(gameT.scoreFrame(6) == 18);
		REQUIRE(gameT.scoreFrame(7) == 8);
		REQUIRE(gameT.scoreFrame(8) == 8);
		REQUIRE(gameT.scoreFrame(9) == 8);
		REQUIRE(gameT.scoreFrame(10) == 0);

	}

	SECTION("BowlingGame class Perfect Game"){
		BowlingGame gameT;

		REQUIRE(gameT.score() == 0);

		// Strikes in a row
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);
		gameT.addShot(10);

		// ZERO INDEXED FRAMES
		REQUIRE(gameT.scoreFrame(0) == 30);
		REQUIRE(gameT.scoreFrame(1) == 30);
		REQUIRE(gameT.scoreFrame(2) == 30);
		REQUIRE(gameT.scoreFrame(3) == 30);
		REQUIRE(gameT.scoreFrame(4) == 30);
		REQUIRE(gameT.scoreFrame(5) == 30);
		REQUIRE(gameT.scoreFrame(6) == 30);
		REQUIRE(gameT.scoreFrame(7) == 30);
		REQUIRE(gameT.scoreFrame(8) == 30);
		REQUIRE(gameT.scoreFrame(9) == 30);

		REQUIRE(gameT.score() == 300);

	}

}
