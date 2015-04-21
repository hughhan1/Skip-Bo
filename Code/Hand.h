/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Hand.h
 */

#include "Card.h"

class Hand 
{
 protected:
  Card[5] hand;

 public:
  Hand();
  bool isEmpty();
  bool add(Card & c);
  Card remove(int index);
};