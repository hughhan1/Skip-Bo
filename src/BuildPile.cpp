/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: BuildPile.cpp
 */

#include "BuildPile.h"
#include <cassert>

BuildPile::BuildPile() {
}

bool BuildPile::add(Card * c) {
  this->pile.push_back(c);
  return true;
}

Card * BuildPile::top() const throw (EmptyPileException) {
  try {
    if (this->isEmpty()) {
      throw new EmptyPileException();
    } else {
      return this->pile.back();
    }
  } catch (EmptyPileException & e) {
    e.what();
  }
  return nullptr;
}

// This is the same as StockPile test because StockPile and BuildPile are the
// same but just have different names.
void BuildPileTest() {
  BuildPile test;
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
