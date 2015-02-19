//  Created by William Showalter on 2015/02/18.
//	TDD Bowling Kata for CS 372

// Include Catch library for testing - using Catch's main.
#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "BowlingGame.h"

TEST_CASE("Scores a game of bowling.", "BowlingGame")
{
	SECTION("BowlingGame class"){
		BowlingGame game1;

		REQUIRE(game1.score() == 0);

		game1.addFrame(1);
		REQUIRE(game1.score() == 1);
	}
}

