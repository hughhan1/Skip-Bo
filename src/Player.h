/**
 * SegFaults
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

    /** A boolean denoting whether it's this Player's turn. */
    bool isTurn;

public:
    
    /** Constructor. */
    Player(std::string name = "no name");

    /** Getter methods. */
    std::string getName();
    Hand* getHand();
    DiscardPile * getDiscardPiles();
    StockPile getStockPile();

    /** Setter methods. */
    bool setTurn();
    virtual void move() = 0;
};

#endif
