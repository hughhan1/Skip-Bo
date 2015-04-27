/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Player.cpp
 */

#include <iostream>
#include "Player.h"

Player::Player(std::string name) {
    this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}

std::string Player::getName() const{
    return this->name;
}

Hand* Player::getHand() const {
    return this->hand;
}

DiscardPile** Player::getDiscardPiles() {
	return this->discardPiles;
}

StockPile* Player::getStockPile() const {
    return this->stockPile;
}

bool Player::setTurn() {
    this->isTurn = !this->isTurn;
}
