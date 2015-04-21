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

bool BuildPile::addCard(Card& c) {
	pile.push_back(c);
	return true;
}

Card BuildPile::removeCard() {
	Card c = pile.at(0);
	pile.pop_back();
	return c;
}

void BuildPile::shuffle() {
	// TO DO
}
