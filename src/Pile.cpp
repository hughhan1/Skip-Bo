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

/* These are virtual methods; I don't think they should be defined here, right?
    - Hugh
bool Pile::add(Card& c) {
    this->pile.push_back(c);
    return true;
}

Card Pile::remove() {
    Card c;
    if (this->isEmpty()) {
        c.setVal(-1);
        return c;
    } else {
        c = this->pile.back();
        this->pile.pop_back();
        return c;
    }
}
*/
