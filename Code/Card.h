// Coded by Marc Feldman

#ifndef _Card_H
#define _Card_H

class Card
{
  int num; // value of the card

 public:
  Card(int = -1);
  int getNum() const { return num; } ;
}

#endif
