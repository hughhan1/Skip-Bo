/**
 * SegFaults
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

bool Hand::add(Card& c) {
    int index = 0;
    Card* scan = hand[index];
    while (scan != nullptr && index < 5) {
        index++;
    }
    if(index < 5) {
        hand[index] = &c;
        return true;
    }
    return false;
    
}

Card* Hand::remove(int index) {
    if(index<=0||index>5){
        std::cout << "Invalid index." << std::endl;
    }
    Card* tmp = hand[index];
    hand[index] = nullptr;
    return tmp;
}

Card* Hand::getCard(int i) {
    return hand[i];
}
