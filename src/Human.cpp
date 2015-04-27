/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Human.cpp
 */


#include "Human.h"
#include <cassert>

Human::Human(std::string name) {
    this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}

void Human::move() {

}



//TEST FUNCTIONS

void humanTest(){
  Player * player1 = new Human("human1");
  assert(player1->getName() == "human1");

  const Hand * h = player1->getHand();
  for(int i = 0; i < 5; i++){
    //assert(h[i] == nullptr);
  }
  
  
}


