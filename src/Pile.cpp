/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Pile.cpp
 */

#include "EmptyPileException.h"
#include "Pile.h"

bool Pile::isEmpty() const {
  return pile.size() == 0;
}

int Pile::getSize() const {
  return pile.size();
}

Card * Pile::remove() throw (EmptyPileException) {

    if (isEmpty()) {
        throw EmptyPileException();
    } else {
        Card * c = pile.back();
        pile.pop_back();
        return c;
    }

    return nullptr;

}

void Pile::shuffle() {
  std::random_shuffle(this->pile.begin(), this->pile.end());
}
