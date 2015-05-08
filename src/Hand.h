/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Hand.h
 */

#ifndef _CARD_H
#define _CARD_H 

#include "Card.h"

class Hand {
protected:
	/** The hand. */
	Card * hand[5];

public:
	/** Constructor. */
    Hand();

    /** Destructor. */
    ~Hand();

    /** 
     * Returns if the hand is empty.
     * @return if the hand is empty
     */
    bool isEmpty();

    /** 
     * Returns if the hand is full.
     * @return if the hand is full
     */
    bool isFull();

    /** 
     * Add a card to the hand.
     * @param c the card to be added
     * @return if the card was added
     */
    bool add(Card * c);

    /** 
     * Remove a card from the hand.
     * @param index the index of the card to be removed
     * @return if the card was removed
     */
    Card* remove(int index);

    /** 
     * Return a card at a specified index.
     * @param a specified index
     * @return a card
     */
    Card* getCard(int i) const;

};

#endif
