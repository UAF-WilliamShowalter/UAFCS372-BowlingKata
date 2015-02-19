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

		// Second frame - strike
		gameT.addShot(10);
		REQUIRE(gameT.score() == 26);

		// Third frame - 8 pins, open
		gameT.addShot(6);
		REQUIRE(gameT.score() == 38);

		// Third frame - 8 pins, open
		gameT.addShot(2);
		REQUIRE(gameT.score() == 42);
	}

}
