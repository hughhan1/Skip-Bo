/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: BuildPile.cpp
 */

#include "BuildPile.h"

bool BuildPile::add(Card& c) {
	pile.push_back(c);
	return true;
}

Card BuildPile::remove() {
	Card c = pile.at(0);
	pile.pop_back();
	return c;
}

void BuildPile::shuffle() {
	std::random_shuffle(this->pile.begin(), this->pile.end());
}
