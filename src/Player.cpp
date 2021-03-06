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

Player::Player(std::string name) {
	this->name = name;
	this->hand = new Hand();
	for (int a = 0; a < 4; a++) {
		this->discardPiles[a] = new TopPile();
	}
	this->stockPile = new TopPile();
}

Player::~Player() { }

std::string Player::getName() const {
    return this->name;
}

Hand* Player::getHand() const {
    return this->hand;
}

TopPile** Player::getDiscardPiles() {
	return this->discardPiles;
}

TopPile* Player::getStockPile() const {
    return this->stockPile;
}

bool Player::addCardToHand(Card * card) {
    if (hand->add(card))
        return true;
    return false;
}

bool Player::addCardToStockPile(Card * card){
    if(stockPile->add(card))
        return true;
    return false;
}

Card * Player::removeCardFromHand(int index) {
    return this->hand->remove(index);
}

Card * Player::removeFromStockPile(){
    return this->stockPile->remove();
}
