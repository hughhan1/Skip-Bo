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

Computer::Computer(std::string name) : Player(name) { }

char Computer::moveFrom() {

	/* Check stock pile for wild card. */
	if (this->stockPile->top()->getVal() == 0) {
		cout << "Returning stockpile card." << std::endl;
		return '0';
	} 

	/* Check hand for wild card. */
	for (int i = 0; i < 5; i++) {
		if (this->hand->getCard(i) != nullptr) {
			if (this->hand->getCard(i)->getVal() == 0) {
				cout << "Returning hand card." << std::endl;
				return i + 1 + ASCII_SHIFT;
			}
		}
	}

	/* Check discard piles for wild card. */
	for (int i = 0; i < 4; i++) {
		if (!this->discardPiles[i]->isEmpty()) {
			if (this->discardPiles[i]->top()->getVal() == 0) {
				cout << "Returning discardpile card." << std::endl;
				return i + 6 + ASCII_SHIFT;
			}
		}
	}

	/* Otherwise, try random cards. */
	char ch = (rand() % NUM_MOVE_FROM) + ASCII_SHIFT;
	return ch;
}

char Computer::moveTo() {
	char ch = (rand() % NUM_MOVE_TO) + 2 + ASCII_SHIFT;
    switch (ch) {
    	case '2': ch = 'a';
    	case '3': ch = 'b';
    	case '4': ch = 'c';
    	case '5': ch = 'd';
    	default: break;
    }
    cout << ch << std::endl;
    return ch;
}
