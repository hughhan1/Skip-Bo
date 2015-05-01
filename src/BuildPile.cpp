/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: BuildPile.cpp
 */

#include "BuildPile.h"

BuildPile::BuildPile() {
	this->size = 0;
}

bool BuildPile::add(Card * c) {
	this->pile.push_back(c);
	return true;
}

Card * BuildPile::top() const {
	try {
		if (this->isEmpty()) {
			throw new EmptyPileException();
		} else {
			return this->pile.back();
		}
	} catch (EmptyPileException & e) {
     	e.showErrorMessage();
    }
    return nullptr;
}

void BuildPile::shuffle() {
	std::random_shuffle(this->pile.begin(), this->pile.end());
}
