/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: TopPile.h
 */

#ifndef _TOPPILE_H
#define _TOPPILE_H

#include "Pile.h"
#include <algorithm>

class TopPile : public Pile {
 public:
  TopPile();
  
  bool add(Card * c);
  Card * top() const throw (EmptyPileException);
};

#endif
