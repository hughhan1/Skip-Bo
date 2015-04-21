/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Card.h
 */

#ifndef _Card_H
#define _Card_H

class Card {
 private:
  int num;
  
 public:
  Card();
  Card(int num);
  void setNum(int num);
  int getNum() const;
  Card& operator=(const Card& cpy);
};

#endif
