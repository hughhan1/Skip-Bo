/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: BuildPile.h
 */

#ifndef _BUILDPILE_H
#define _BUILDPILE_H

#include "Pile.h"
#include <algorithm>

class BuildPile : public Pile {
public:
	BuildPile();
	
	bool add(Card * c);
	Card * top() const;
	void shuffle();
};

#endif
