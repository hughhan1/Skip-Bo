/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Computer.cpp
 */

#include "Computer.h"

using std::cout;
using std::endl;

Computer::Computer(std::string name) {
	this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        this->discardPiles[a] = new DiscardPile();
    }
    this->stockPile = new StockPile();
    this->isTurn = false;
}

char Computer::moveFrom() {
	char ch;
    cout << "Enter a number representing a card you would like to move." << endl;
	ch = rand() % NUM_OPTIONS;
	cout << ch << endl;
	return ch;
}

char Computer::moveTo() {
	int ch;
    cout << "Enter a number representing a pile to which you would like to move that card." << endl;
    ch = rand() % NUM_OPTIONS;
    switch (ch) {
    	case 10: ch = 'a';
    	case 11: ch = 'b';
    	case 12: ch = 'c';
    	case 13: ch = 'd';
    	default: break;
    }
    cout << ch << endl;
    return ch;
}
