/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: StockPile.cpp
 */

#include "StockPile.h"

StockPile::StockPile() {
	this->size = 0;
}

bool StockPile::add(Card * c) {
	this->pile.push_back(c);
	return true;
}

Card * StockPile::top() const {
	if (this->isEmpty()) {
	  //throw new EmptyPileException();
	} else {
		return this->pile.back();
	}
}
