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


std::string Player::getName() const{
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

bool Player::addCardTohand(Card * card){
  for(int i = 0; i < 5; i++){
    /*if(hand[i] != nullptr){
      hand[i] = card;
      return true;
      }*/
  }
  return false;
}

bool Player::setTurn() {
    this->isTurn = !this->isTurn;
}
