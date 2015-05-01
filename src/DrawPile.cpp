/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DrawPile.cpp
 */

#include "DrawPile.h"
#include <cassert>

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
   
}

bool DrawPile::add(Card * c) {
	pile.push_front(c);
	return true;
}

void DrawPileTest() {
  DrawPile test;
  Card* c;
  assert(test.getSize() == 162);
  assert(!test.isEmpty());
  
  for (int i = 0; i < 18; i++) {
    assert(test.getSize() + i == 162);
    c = test.remove();
    assert (c->getVal() == 0);
  }

  
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      c = test.remove();
      assert(c->getVal() == 12-i);
    }
  }

  assert(test.isEmpty());

  c = new Card(11);
  Card* d = new Card(9);
  assert(test.add(c));
  assert(test.getSize() == 1);
  assert(!test.isEmpty());
  assert(test.add(d));
  assert(test.getSize() == 2);
  assert(test.remove()->getVal() == 11);
  assert(test.getSize() == 1);
  assert(test.remove()->getVal() == 9);
  assert(test.getSize() == 0);
  assert(test.isEmpty());
}
