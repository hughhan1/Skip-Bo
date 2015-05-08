/**
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
#include "EmptyPileException.h"
#include <deque>
#include <algorithm>
#include <iostream>

class Pile {
protected:
	std::deque<Card*> pile;
	int size;
  
public:
	bool isEmpty() const;
	int getSize() const;
	virtual bool add(Card * cPtr) = 0; 
	Card* remove() throw (EmptyPileException);
	void shuffle();
};

#endif
