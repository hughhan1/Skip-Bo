/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: CheckMoves.h
 */

#ifndef _CHECKMOVES_H
#define	_CHECKMOVES_H

#include "BuildPile.h"
#include "DrawPile.h"
#include "StockPile.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"

class CheckMoves {
	
	/**
	 * Returns whether a Player can still draw cards.
	 * @return whether a Player's Hand is full
	 */
	bool canDraw(Player& player);

	/** 
	 * Returns whether the top card of a pile can be removed by a Player to
	 * put into another Pile.
	 * @return whether the top card of a pile is valid to be removed
	 */
	bool canRemove(Pile& pile);

	/** 
	 * Returns whether any cards in a Hand can be removed by a Player to
	 * put into another Pile.
	 * @return whether any cards in a Hand are valid to be removed
	 */
	bool canRemove(Hand& hand);

	/**
	 * Returns whether a Player can move a card onto a BuildPile.
	 * @return whether a Card can be moved onto a BuildPile
	 */
	bool canBuild(Card& card, Pile& pile);

};

#endif
