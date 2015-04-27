/** 
 * Marc Feldman
 * Hugh Han 
 * SeungHwan Lee
 * Matthew Cowen-Green 
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Card.cpp
 */

#include "Card.h"
#include <cassert>

Card::Card() {
    this->val = -1;
}

Card::Card(int val) {
    this->val = val;
}

int Card::getVal() const {
    return val;
}

const Card& Card::operator=(const Card& cpy) {
  this->val = cpy.val;
  return *this;
}

bool Card::operator==(const Card& rhs) const {
	return this->getVal() == rhs.getVal();
}

bool Card::operator!=(const Card& rhs) const {
	return this->getVal() != rhs.getVal();
}

bool Card::operator<(const Card& rhs) const {
	return this->getVal() < rhs.getVal();
}

bool Card::operator>(const Card& rhs) const {
	return this->getVal() > rhs.getVal();
}

void CardTest() {
  Card c1;
  assert(c1.getVal() == -1);
  Card c2(1);
  assert(c2.getVal() == 1);
  Card c3(1);
  assert(c2 == c3);
  assert(c1 < c2);
  assert(c2 > c1);
  assert(c1 != c2);
}
