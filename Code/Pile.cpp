/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Pile.cpp
 */

#include "Pile.h"

bool Pile::isEmpty() const {
	return this->size == 0;
}

int Pile::getSize() const{
	return this->size;
}

void Pile::addCard(Card& c){
  pile.push_back(c);
}

Card  Pile::drawCard(){
  Card c;
  
  if(pile.size() == 0){
    c.setNum(-1);
    return c;
  }
  else{
    c = *(pile.end());
    pile.pop_back();
    return c;
  }
  
}
