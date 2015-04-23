#include "Card.h"

Card::Card() {
  this->num = -1;
}

Card::Card(int val) {
  this->val = val;
}

void Card::setVal(int val) {
  this->val = val;
}

int Card::getVal() const {
  return val;
}

Card& Card::operator=(const Card& cpy) {
  this->val = cpy.val;
  return *this;
}

bool operator==(const Card& rhs) {
	return this->getVal() == rhs.getVal();
}

bool operator!=(const Card& rhs) {
	return this->getVal() != rhs.getVal();
}

bool operator<(const Card& rhs) {
	return this->getVal() < rhs.getVal();
}

bool operator>(const Card& rhs) {
	return this->getVal() > rhs.getVal();
}
