/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DrawPile.cpp
 */

#include "DrawPile.h"

bool DrawPile::addCard(Card& c) {
	pile.push_back(c);
	return true;
}

Card DrawPile::removeCard() {
	Card c = pile.at(0);
	pile.pop_back();
	return c;
}

void DrawPile::shuffle() {
	// TO DO
}
