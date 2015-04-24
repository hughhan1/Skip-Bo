/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Human.cpp
 */

#include "Human.h"

Human::Human(std::string name) {
	this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}
