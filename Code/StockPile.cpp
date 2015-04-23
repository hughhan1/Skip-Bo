/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: StockPile.cpp
 */

#include "StockPile.h"

Card StockPile::remove() {
	Card c = this->top();
	this->pile.pop_back();
	return c;
}

bool StockPile::add(Card& c) {
	this->pile.push_back(c);
	return true;
}

Card StockPile::top() {
	return this->pile.back();
}
