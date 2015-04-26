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
    std::string name;
    Hand* hand;
    DiscardPile* discardPiles[4];
    StockPile* stockPile;
    bool isTurn;

public:
    Player(std::string name = "no name");
    std::string getName();
    Hand* getHand();
    DiscardPile * getDiscardPiles();
    StockPile getStockPile();
    bool setTurn();
};

#endif
