/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Game.h
 */

#ifndef _GAME_H
#define _GAME_H

#include "Player.h"
#include "DrawPile.h"
#include "BuildPile.h"

class Game {
private:
	Player players[];
	DrawPile drawPile;
	BuildPile buildPiles[4];
	int turn;

public:
	Game(Player[] players);
	Game(FILE* file);

	void startGame();
	void loadGame();
	void saveGame();
	void endGame();

	void printView();

};