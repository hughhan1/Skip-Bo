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

#include "Pile.h"

bool Pile::isEmpty() const {
    return this->size == 0;
}

int Pile::getSize() const {
	return this->size;
}

/* Pure Virtual
bool Pile::add(Card* c) {
    this->pile.push_back(c);
    return true;
}
*/

Card * Pile::remove() {
    if (this->isEmpty()) {
        return nullptr;
    } else {
        Card * c = this->pile.back();
        this->pile.pop_back();
	this->size--;
        return c;
    }
}

void Pile::shuffle() {
  std::random_shuffle(this->pile.begin(), this->pile.end());
}
