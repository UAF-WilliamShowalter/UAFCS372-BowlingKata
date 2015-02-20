# UAFCS372-BowlingKata
Bowling Kata exercise done with TDD.
Class BowlingGame that scores a bowling game.
Interface:
addShot(int) - adds shots in game, exactly as they would occur in a match of bowling.
score() - returns current score, as it would be estimated on a bowling score board 
  (except it estimates strikes treating future frames as zero)
scoreFrame(int) - takes a zero-index frame number and returns the score of that individual frame (non-cumulative)

scoreFrame could be used to build a display board using a BowlingGame object.

Main.cpp provides for testing BowlingGame class with Catch C++ testing library.
