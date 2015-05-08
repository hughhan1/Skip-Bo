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

/* EXTRA CREDIT ATTEMPT
	Card * buildTop = nullptr;
*/

	/* Check stock pile for wild card. */
	if (stockTop->getVal() == 0) {
		return '0';
	} 

/* EXTRA CREDIT ATTEMPT
	for (int i = 0; i < 4; i++) {
		if (!this->buildChoices[i]->isEmpty()
				&& this->buildChoices[i]->top() != nullptr
				&& this->buildChoices[i]->top()->getVal() + 1 == stockTop->getVal()) {
			this->moveCard = stockTop;
			return '0';
		}
	}
*/

	/* Check hand for wild card. */
	for (int i = 0; i < 5; i++) {
		if (this->hand->getCard(i) != nullptr
				&& this->hand->getCard(i)->getVal() == 0) {
			this->moveCard = this->hand->getCard(i);
			return i + 1 + ASCII_SHIFT;
		}
	}

	/* Check discard piles for wild card. */
	for (int i = 0; i < 4; i++) {
		if (!this->discardPiles[i]->isEmpty()
				&& this->discardPiles[i]->top()->getVal() == 0) {
			this->moveCard = this->discardPiles[i]->top();
			return i + 6 + ASCII_SHIFT;
		}
	}

	/* Otherwise, try random cards. */
	char ch = (rand() % NUM_MOVE_FROM) + ASCII_SHIFT;
	return ch;
}

char Computer::moveTo() {

/* EXTRA CREDIT ATTEMPT
	for (int i = 0; i < 4; i++) {
		if (this->moveCard != nullptr 
				&& !this->buildChoices[i]->isEmpty()
				&& this->buildChoices[i]->top() != nullptr) {
			if (this->moveCard->getVal() == buildChoices[i]->top()->getVal()) {
				return i + 'a';
			}
		}
	}
*/

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
