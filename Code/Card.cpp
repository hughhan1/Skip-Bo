#include "Card.h"

Card::Card(){
  this->num = -1;
}

Card::Card(int num){
  this->num = num;
}

void Card::setNum(int num){
  this->num = num;
}

int Card::getNum() const{
  return num;
}

Card& Card::operator=(const Card& cpy){
  this->num = cpy.num;
  return *this;
}
