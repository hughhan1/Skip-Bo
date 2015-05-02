/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Human.cpp
 */

#include "Human.h"
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

Human::Human(std::string name) {
    this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}

char Human::moveFrom() {
    char ch;
    cout << "Enter a number representing a card you would like to move: "; 
    cin >> ch;
    cout << endl;
    return ch;
}

char Human::moveTo() {
    char ch;
    cout << "Enter a number representing a pile to which you would like to move that card: ";
    cin >> ch;
    cout << endl;
    return ch;
}
