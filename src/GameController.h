/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: GameController.h
 */

#ifndef _GAMECONTROLLER_H
#define _GAMECONTROLLER_H

#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

class GameController {
private:
	/** The game. */
	Game* skipBo;

	/** Prints a welcome message to the screen. */
	void welcome();

public:
	/** Runs the game. */
	void runGame();

	/**
	 * Loads the game.
	 * @return if a game was loaded
	 */
	bool loadGame();	
};

#endif
