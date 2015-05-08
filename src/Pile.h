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
	/** Destructor. */
	virtual ~Pile();

	/**
	 * Returns if the pile is empty.
	 * @return if the pile is empty
	 */
	bool isEmpty() const;

	/**
	 * Returns the size of the pile.
	 * @return the size of the pile
	 */
	int getSize() const;

	/** 
	 * Adds a card to the pile.
	 * @param cPtr the card to be added
	 * @return if the card was added
	 */
	virtual bool add(Card * cPtr) = 0; 

	/** 
	 * Removes a card from pile.
	 * @return the card that is removed
	 */
	Card* remove() throw (EmptyPileException);

	/** Shuffles the pile. */
	void shuffle();
};

#endif
