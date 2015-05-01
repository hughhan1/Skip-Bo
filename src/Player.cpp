/**
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

std::string Player::getName() const {
    return this->name;
}

const Hand* Player::getHand() const {
    return this->hand;
}

DiscardPile** Player::getDiscardPiles() {
	return this->discardPiles;
}

const StockPile* Player::getStockPile() const {
    return this->stockPile;
}

bool Player::addCardToHand(Card * card) {
    if(hand->add(card))
        return true;
    return false;
}

bool Player::addCardToStockPile(Card * card){
    if(stockPile->add(card))
        return true;
    return false;
}

bool Player::setTurn() {
    this->isTurn = !this->isTurn;
}

Card * Player::removeCardFromHand(int index){
    return this->hand->remove(index);
}

Card * Player::removeFromStockPile(){
    return this->stockPile->remove();
}
