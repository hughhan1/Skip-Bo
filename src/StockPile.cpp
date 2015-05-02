/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: StockPile.cpp
 */

#include "StockPile.h"
#include <cassert>

StockPile::StockPile() {
}

bool StockPile::add(Card * c) {
  this->pile.push_back(c);
  return true;
}

Card * StockPile::top() const {
  try {
    if (this->isEmpty()) {
      throw EmptyPileException();
    } else {
      return this->pile.back();
    }
  } catch(EmptyPileException &e) {
    std::cout << e.what() << std::endl;
  }
  return nullptr;
}

