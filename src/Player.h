/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Player.h
 */

#ifndef _PLAYER_H
#define _PLAYER_H

#include "TopPile.h"
#include "Hand.h"
#include <string>

class Player {

protected:

    /** The Player's name. */
    std::string name;

    /** The Player's Hand. */
    Hand* hand;

    /** The four discard piles belonging to this Player. */
    TopPile* discardPiles[4];

    /** The stock pile belonging to this Player. */
    TopPile* stockPile;

public:

    Player(std::string = "no name");
    virtual ~Player();

    /** Getter methods. */
    std::string getName() const;
    Hand* getHand() const;
    TopPile** getDiscardPiles();
    TopPile* getStockPile() const;

    bool addCardToHand(Card * card);
    bool addCardToStockPile(Card * card);
    Card * removeCardFromHand(int);
    Card * removeFromStockPile();
    
    /** Setter methods. */
    virtual char moveFrom() = 0;
    virtual char moveTo() = 0;
};

#endif

