/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DrawPile.h
 */

#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include "Card.h"
#include "Pile.h"
#include <algorithm>

class DrawPile : public Pile {

public:
	
	DrawPile();

	bool add(Card * c);
	Card * remove();
	void shuffle();
};

#endif