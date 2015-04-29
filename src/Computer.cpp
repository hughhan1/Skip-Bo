/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Computer.cpp
 */

#include "Computer.h"

Computer::Computer(std::string name) {
	this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}

int Computer::moveFrom() {
	return rand() % NUM_OPTIONS;
}

int Computer::moveTo(int moveFrom) {
	int i;
	do {
		i = rand() % NUM_OPTIONS;
	} while (i == moveFrom);
	return i;
}
