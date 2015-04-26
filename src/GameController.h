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

class GameController {
private:
	Game* skipBo;

public:

	/** Runs the game. */
	void runGame();

	/** Prints a welcome message to the screen. */
	void welcome();
	
};

#endif
