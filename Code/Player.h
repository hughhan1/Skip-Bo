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

#ifndef _Player_h
#define _Player_h
#include "DiscardPile.h"
#include "StockPile.h"
#include "Hand.h"
#include <String>
class Player{
protected:
    std::string name;
    Hand phand;
    DiscardPile discardPiles[4];
    StockPile stockPile;
    bool isTurn;
public:
    Player(std::string nm);
    void printView();
};
#endif
