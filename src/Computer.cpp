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

Computer::Computer(std::string name) : Player(name) { }

void Computer::importChoices(TopPile** buildPiles) {
	for (int i = 0; i < 4; i++) {
		this->buildChoices[i] = buildPiles[i];
	}
}

char Computer::moveFrom() {

	Card * stockTop = this->stockPile->top();
	Card * buildTop = nullptr;

	/* Check stock pile for wild card. */
	if (stockTop->getVal() == 0) {
		return '0';
	} 

	for (int i = 0; i < 4; i++) {
		if (!this->buildChoices[i]->isEmpty()) {
			buildTop = this->buildChoices[i]->top();
			if (buildTop != nullptr) {
				if (stockTop->getVal() == buildTop->getVal() + 1) {
					return '0';
				}
			}
		}
	}

	/* Check hand for wild card. */
	for (int i = 0; i < 5; i++) {
		if (this->hand->getCard(i) != nullptr) {
			if (this->hand->getCard(i)->getVal() == 0) {
				return i + 1 + ASCII_SHIFT;
			}
		}
	}

	/* Check discard piles for wild card. */
	for (int i = 0; i < 4; i++) {
		if (!this->discardPiles[i]->isEmpty()) {
			if (this->discardPiles[i]->top()->getVal() == 0) {
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
    	case '2': ch = 'a'; break;
    	case '3': ch = 'b';	break;
    	case '4': ch = 'c';	break;
    	case '5': ch = 'd';	break;
    	default: break;
    }
    return ch;
}
