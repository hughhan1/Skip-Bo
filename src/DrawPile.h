/**
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

class DrawPile : public Pile {
public:	
	/** Constructor. */
	DrawPile();

	/** Destructor. */
	virtual ~DrawPile();

	/**
	 * Adds a card to the draw pile.
	 * @param c a card to be added
	 * @return if a card was added
	 */
	bool add(Card * c);
};

#endif
