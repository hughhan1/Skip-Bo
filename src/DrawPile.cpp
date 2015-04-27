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

    this->size = 162;
}

bool DrawPile::add(Card * c) {
	pile.push_front(c);
	this->size++;
	return true;
}

void DrawPileTest() {
  DrawPile test;
  Card* c;
  assert(test.getSize() == 162);
  
  for (int i = 0; i < 18; i++) {
    assert(test.getSize() + i == 162);
    c = test.remove();
    assert (c->getVal() == 0);
  }

  
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      // assert(test.getSize() + i*j + 18 == 162);
      c = test.remove();
      assert(c->getVal() == 12-i);
    }
  }

}
