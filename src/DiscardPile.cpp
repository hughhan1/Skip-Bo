/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DiscardPile.cpp
 */

#include "DiscardPile.h"

DiscardPile::DiscardPile() {
	this->size = 0;
}

bool DiscardPile::add(Card * c) {
	this->pile.push_back(c);
	return true;
}

Card * DiscardPile::top() const {
	if (this->isEmpty()) {
	  //throw new EmptyPileException();
	} else {
		return this->pile.back();
	}
}
