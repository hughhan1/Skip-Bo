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

int Pile::getSize() const{
	return this->size;
}
