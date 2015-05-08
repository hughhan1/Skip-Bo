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
	Card * hand[5];

public:
    Hand();
    bool isEmpty();
    bool isFull();
    bool add(Card * c);
    Card* remove(int index);
    Card* getCard(int i) const;

};

#endif
