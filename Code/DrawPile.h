/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: DrawPile.h
 */

#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include "Pile.h"
#include <algorithm>

class DrawPile : public Pile {
 private:
 protected:

 public:
  DrawPile();
  bool addCard(Card& c);
  Card removeCard();
  void shuffle();
  void generateDeck();
};

#endif
