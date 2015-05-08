/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: TopPile.cpp
 */

#include "TopPile.h"
#include <cassert>

TopPile::TopPile() { }
TopPile::~TopPile() { }

bool TopPile::add(Card * c) {
  this->pile.push_back(c);
  return true;
}

Card * TopPile::top() const throw (EmptyPileException) {
  try {
    if (this->isEmpty()) {
      throw EmptyPileException();
    } else {
      return this->pile.back();
    }
  } catch (EmptyPileException & e) {
    std::cout << e.what() << std::endl;
  }
  return nullptr;
}
