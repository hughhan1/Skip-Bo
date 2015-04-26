/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DrawPile.cpp
 */

#include "DrawPile.h"

DrawPile::DrawPile() {

    Card * card[162];

    int idx = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            card[idx++] = new Card(i + 1);
        }
    }

    while (idx < 162){
      card[idx++] = new Card(0);
    }

    for (int i = 0; i < 162; i++) {
        this->pile.push_back(card[i]);
    }

    this->shuffle();
    
}

bool DrawPile::add(Card * c) {
	pile.push_back(c);
	return true;
}

Card * DrawPile::remove() {
	Card * c = this->pile.back();
	this->pile.pop_back();
	return c;
}

void DrawPile::shuffle() {
	std::random_shuffle(this->pile.begin(), this->pile.end());
}

