/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Hand.cpp
 */

#include "Hand.h"
#include <iostream>
#include <cassert>

Hand::Hand() { 
    for (int a = 0; a < 5; a++) {
        hand[a] = nullptr;
    }
}

bool Hand::isEmpty() {
    for (int a = 0; a < 5; a++) {
        if (hand[a] != nullptr) {
            return false;
        }
    }
    return true;
}


bool Hand::add(Card * c) {
    int index = 0;
    while (hand[index] != nullptr && index < 5) {
        index++;
    }
    if(index < 5) {
        hand[index] = c;
        return true;
    }
    return false;
}

Card * Hand::remove(int index) {
    if (index < 0 || index >= 5) {
        std::cout << "Invalid index." << std::endl;
	return nullptr;
    }
    Card* tmp = hand[index];
    hand[index] = nullptr;
    return tmp;
}

Card * Hand::getCard(int i) const {
    return hand[i];
}


void HandTest() {
  Hand test;
  assert(test.isEmpty());
  Card* c = new Card(1);
  assert(test.add(c));
  assert(!test.isEmpty());
  assert(c == test.getCard(0));
  Card c1(2);
  assert(test.add(&c1));
  Card c2(3);
  assert(test.add(&c2));
  Card c3(4);
  assert(test.add(&c3));
  Card c4(5);
  assert(test.add(&c4));
  Card c5(6);
  assert(!test.add(&c5));
  assert(&c4 == test.getCard(4));
  assert(c == test.remove(0));
  assert(&c1 == test.remove(1));
  assert(&c2 == test.remove(2));
  assert(&c3 == test.remove(3));
  assert(&c4 == test.remove(4));
  assert(test.getCard(0) == nullptr);
}
