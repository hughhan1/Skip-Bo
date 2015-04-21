/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DiscardPile.h
 */

#ifndef _DISCARDPILE_H
#define _DISCARDPILE_H

#include "Pile.h"

class DiscardPile : public Pile {

	bool addCard(Card &);
	Card removeCard();
	Card top();

};

#endif
