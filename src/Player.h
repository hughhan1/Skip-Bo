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

#include "DiscardPile.h"
#include "StockPile.h"
#include "Hand.h"
#include <string>

/** This is the number of cards that a player can select from when making a move. */
#define NUM_OPTIONS 14

class Player {

protected:

    /** The Player's name. */
    std::string name;

    /** The Player's Hand. */
    Hand* hand;

    /** The four discard piles belonging to this Player. */
    DiscardPile* discardPiles[4];

    /** The stock pile belonging to this Player. */
    StockPile* stockPile;

public:

    Player(std::string = "no name");

    /** Getter methods. */
    std::string getName() const;
    Hand* getHand() const;
    DiscardPile** getDiscardPiles();
    StockPile* getStockPile() const;

    bool addCardToHand(Card * card);
    bool addCardToStockPile(Card * card);
    Card * removeCardFromHand(int);
    Card * removeFromStockPile();
    
    /** Setter methods. */
    virtual char moveFrom() = 0;
    virtual char moveTo() = 0;
};

#endif

