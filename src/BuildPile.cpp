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

BuildPile::BuildPile() {
	this->size = 0;
}

bool BuildPile::add(Card * c) {
	this->pile.push_back(c);
	return true;
}

const Card * BuildPile::remove() {
	const Card * c = top();
	this->pile.pop_back();
	return c;
}

const Card * BuildPile::top() const {
	return this->pile.back();
}

void BuildPile::shuffle() {
	std::random_shuffle(this->pile.begin(), this->pile.end());
}
