#include "DrawPile.h"

bool DrawPile::addCard(Card & n) 
{
  pile.push_back(n);
  return true;
}

Card DrawPile::removeCard() 
{
  Card n = pile.at(0);
  pile.pop_back();
  return n;
}
