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

bool DiscardPile::add(Card * c) {
	this->pile.push_back(c);
	return true;
}

const Card * DiscardPile::remove() {
	const Card * c = this->top();
	this->pile.pop_back();
	return c;
}

const Card * DiscardPile::top() const {
	return this->pile.back();
}
