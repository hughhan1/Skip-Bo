/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: TopPile.h
 */

#ifndef _TOP_PILE_H
#define _TOP_PILE_H

#include "Pile.h"
#include <algorithm>

class TopPile : public Pile {
public:
	/** Constructor. */
	TopPile();

	/** Destructor. */
	virtual ~TopPile();

	/** 
	 * Adds a card to the pile.
	 * @param cPtr the card to be added
	 * @return if the card was added
	 */
	bool add(Card * c);

	/** 
	 * Returns the top card in the pile.
	 * @return the top card in the pile
	 */
	Card * top() const throw (EmptyPileException);
};

#endif
