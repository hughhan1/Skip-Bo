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
	try {
		if (this->stockPile->top() == 0) {
			return 0;
		} 
	} catch (EmptyPileException & e) {
		cout << e.what() << std::endl;
	}

	/* Check hand for wild card. */
	for (int i = 0; i < 5; i++) {
		if (this->hand->getCard(i) != nullptr) {
			if (this->hand->getCard(i) == 0) {
				return i + 1;
			}
		}
	}

	/* Check discard piles for wild card. */
	for (int i = 0; i < 4; i++) {
		try {
			if (this->discardPiles[i]->top() == 0) {
				return i + 6;
			}
		} catch (EmptyPileException & e) {
			cout << e.what() << std::endl;
		}
	}

	/* Otherwise, try random cards. */
	int ch = rand() % NUM_OPTIONS;
	return ch;
}

char Computer::moveTo() {
	int ch = (rand() % NUM_OPTIONS) + 4;
    switch (ch) {
    	case 10: ch = 'a';
    	case 11: ch = 'b';
    	case 12: ch = 'c';
    	case 13: ch = 'd';
    	default: break;
    }
    return ch;
}
