/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Pile.h
 */

#ifndef _PILE_H
#define _PILE_H

#include "Card.h"
#include <deque>

class Pile {
protected:
	std::deque<Card> pile;
	int size;

public:
	bool isEmpty();
	int getSize();
	virtual bool addCard() = 0;
	virtual Card removeCard() = 0;
};

#endif