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

class BuildPile : public Pile {
public:
	bool addCard(Card& c);
	Card removeCard();
	void shuffle();
};

#endif
