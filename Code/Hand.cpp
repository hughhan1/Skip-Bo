// This isn't done at all and hand.h also isnt totally complete

#include "Hand.h"


Hand::Hand() {
  
}

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
