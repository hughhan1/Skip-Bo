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
      throw new EmptyPileException();
    } else {
      return this->pile.back();
    }
  } catch(EmptyPileException &e) {
    std::cout << e.what() << std::endl;
  }
  return nullptr;
}

void StockPileTest() {
  StockPile test;
  Card* c;
  
  assert(test.getSize() == 0);
  assert(test.isEmpty());

  Card c0(1);
  assert(test.add(&c0));
  assert(test.top()->getVal() == c0.getVal());
  assert(!test.isEmpty());
  assert(test.getSize() == 1);

  Card c1(2);
  assert(test.add(&c1));
  assert(test.top()->getVal() == c1.getVal());
  assert(!test.isEmpty());
  assert(test.getSize() == 2);

  Card c2(10);
  assert(test.add(&c2));
  assert(test.top()->getVal() == c2.getVal());
  assert(!test.isEmpty());
  assert(test.getSize() == 3);

  c = test.remove();
  assert(c->getVal() == c2.getVal());
  assert(test.top()->getVal() == c1.getVal());
  assert(!test.isEmpty());
  assert(test.getSize() == 2);

  c = test.remove();
  assert(c->getVal() == c1.getVal());
  assert(test.top()->getVal() == c0.getVal());
  assert(!test.isEmpty());
  assert(test.getSize() == 1);
  
  c = test.remove();
  assert(c->getVal() == c0.getVal());
  assert(test.isEmpty());
  assert(test.getSize() == 0);
}
