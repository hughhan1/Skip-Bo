/**
 * SegFaults
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

Card DiscardPile::removeCard() {
	Card c = this->top();
	this->pile.pop_back();
	return c;
}

bool DiscardPile::addCard(Card& c) {
	this->pile.push_back(c);
	return true;
}

Card DiscardPile::top() {
	return this->pile.back();
}
