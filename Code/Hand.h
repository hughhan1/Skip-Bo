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
  bool isEmpty();
  bool add();
  Card remove(int index);
};
