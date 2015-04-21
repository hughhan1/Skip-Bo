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

DrawPile::DrawPile(){
  Card card[162];

  int idx = 0;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 4; j++){
      card[i * 4+ j].setNum(i + 1);
      idx++;
    }
  }

  while(idx < 162){
    card[idx++].setNum(0);
  }

  for(int i = 0; i < 162; i++){
    pile.push_back(card[i]);
  }
}

bool DrawPile::addCard(Card& c) {
	pile.push_back(c);
	return true;
}

Card DrawPile::removeCard() {
	Card c = pile.at(0);
	pile.pop_back();
	return c;
}

void DrawPile::shuffle() {
	std::random_shuffle(this->pile.begin(), this->pile.end());
}
