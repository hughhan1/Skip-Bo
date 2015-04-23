/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: StockPile.h
 */

#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include "Pile.h"

class StockPile : public Pile {
public:
	Card remove();
	bool add(Card& c);
	Card top();
};

#endif