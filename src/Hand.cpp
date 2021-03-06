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

Hand::~Hand() {
    for (int i = 0; i < 5; i++) {
        delete this->hand[i];
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

bool Hand::isFull() {
    for (int a = 0; a < 5; a++) {
        if (hand[a] == nullptr) {
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
